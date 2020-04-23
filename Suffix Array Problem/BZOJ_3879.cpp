#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
const int maxm=3e6+5;
const ll mod=23333333333333333LL;
int a[maxm],b[maxn];
int n,q;
int oldrk[maxn],px[maxn],id[maxn],cnt[maxn];
char s[maxn];
int rk[maxn],sa[maxn],ht[maxn];
int l[maxm],r[maxm];
int lg[maxn];
int dp[maxn][20];
int st[maxn];
bool cmp(int x,int y,int w)
{
    return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];
}
void SA(char s[],int n)
{
    int m=300,p;
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) ++cnt[rk[i]=s[i]];
    for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
    for (int w=1;w<n;w<<=1,m=p) {  // m=p 就是优化计数排序值域
        p=0;
        for (int i=n;i>n-w;i--) id[++p]=i;
        for (int i=1;i<=n;i++)
            if (sa[i]>w) id[++p]=sa[i]-w;
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) ++cnt[px[i]=rk[id[i]]];
        for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for (int i=n;i>=1;i--) sa[cnt[px[i]]--]=id[i];
        memcpy(oldrk,rk,sizeof(rk));
        for (int p=0,i=1;i<=n;i++)
            rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
    }
}
void calcH(char a[],int n)
{
    for (int i=1,j=0;i<=n;i++) {
        if (j) --j;
        while (a[i+j]==a[sa[rk[i]-1]+j]) ++j;
        ht[rk[i]]=j;
    }
}
void InitST(int a[],int n)
{
    for (int i=1;i<=n;i++) dp[i][0]=a[i];
    for (int j=1;j<=lg[n];j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
        dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmqMin(int l,int r)
{
    int k=lg[r-l+1];
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
    lg[0]=-1;
    for (int i=1;i<maxn;i++)
        if (i&(i-1)) lg[i]=lg[i-1];
        else lg[i]=lg[i-1]+1;
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    SA(s,n);
    calcH(s,n);
    InitST(ht,n);
    int num;
    while (q--) {
        scanf("%d",&num);
        for (int i=1;i<=num;i++) scanf("%d",&a[i]);
        for (int i=1;i<=num;i++) a[i]=rk[a[i]];
        sort(a+1,a+num+1);
        num=unique(a+1,a+num+1)-(a+1);
        for (int i=1;i+1<=num;i++) b[i]=rmqMin(a[i]+1,a[i+1]);
        //for (int i=1;i<=num-1;i++) printf("%d ",b[i]); printf("\n");
        int h=0;
        for (int i=1;i<=num-1;i++) {
            while (h>0&&b[st[h-1]]>b[i]) {
                r[st[h-1]]=i-1;
                h--;
            }
            st[h++]=i;
        }
        while (h>0) {
            r[st[h-1]]=num-1;
            h--;
        }
        for (int i=num-1;i>=1;i--) {
            while (h>0&&b[st[h-1]]>=b[i]) {
                l[st[h-1]]=i+1;
                h--;
            }
            st[h++]=i;
        }
        while (h>0) {
            l[st[h-1]]=1;
            h--;
        }
        ll ans=0;
        for (int i=1;i<=num-1;i++)
            ans=(ans+1LL*(i-l[i]+1)*(r[i]-i+1)%mod*b[i]%mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

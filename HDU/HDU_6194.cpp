#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int oldrk[maxn],id[maxn],px[maxn],cnt[maxn];
int sa[maxn],ht[maxn],rk[maxn];
char s[maxn];
int T,k;
int dp[maxn][20];
int lg[maxn];
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
void initST(int a[],int n)
{
    for (int i=1;i<=n;i++) dp[i][0]=a[i];
    for (int j=1;j<=lg[n];j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
        dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq(int l,int r)
{
    int k=lg[r-l+1];
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d",&T);
    lg[0]=-1;
    for (int i=1;i<maxn;i++)
        if (i&(i-1)) lg[i]=lg[i-1];
        else lg[i]=lg[i-1]+1;
    while (T--) {
        scanf("%d",&k);
        scanf("%s",s+1);
        int n=strlen(s+1);
        SA(s,n);
        calcH(s,n);
        initST(ht,n);
        ll ans=0;
        if (k==1) {
            int l0,r0;
            for (int i=1;i<=n;i++) {
                l0=0,r0=0;
                if (i>1) l0=ht[i];
                if (i<n) r0=ht[i+1];
                ans=ans+n-sa[i]+1-max(l0,r0);
            }
        }
        else {
            int l0,r0;
            int t;
            for (int i=1;i+k-1<=n;i++) {
                l0=0; r0=0;
                if (i>1) l0=ht[i];
                if (i+k-1<n) r0=ht[i+k];
                t=rmq(i+1,i+k-1);
                if (max(l0,r0)<t) ans+=t-max(l0,r0);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

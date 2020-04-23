#include<bits/stdc++.h>
using namespace std;
const int maxn=3050;
int id[maxn],px[maxn],oldrk[maxn],cnt[maxn];
int sa[maxn],ht[maxn],rk[maxn];
char s[maxn];
int dp[maxn][15];
int lg[maxn];
int n;
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
    scanf("%d",&n);
    scanf("%s",s+1);
    SA(s,n);
    calcH(s,n);
    InitST(ht,n);
    for (int i=1;i<=n;i++) {
        int cur=ht[i]+1;
        int nxt=i+1;
        while (nxt<=n&&ht[nxt]>=cur) nxt++;
        //printf("debug %d\n",sa[i]);
        if (nxt-i>1) printf("%d\n",nxt-i);
        int l=ht[i]+2,r=nxt-1;
        while (l<=n-sa[i]+1) {
            while (i<r&&rmqMin(i+1,r)<l) r--;
            if (r-i+1>=2) printf("%d\n",r-i+1);
            else break;
            l++;
        }
    }
    return 0;
}

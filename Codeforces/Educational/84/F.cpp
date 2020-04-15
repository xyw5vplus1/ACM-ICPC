/*#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=5e5;
typedef long long ll;
typedef double db;
int father[maxn+5],mx[maxn+5];
bool bo[maxn+5];
int l[maxn+5],r[maxn+5],x[maxn+5];
int n,m,k;
int f[maxn+5];
int dp[maxn+5],sum[maxn+5];
int _find(int x)
{
    if (x==father[x]) return x;
    father[x]=_find(father[x]);
    return father[x];
}
void _merge(int u,int v)
{
    u=_find(u); v=_find(v);
    bo[v]=1;
    if (u==v) return ;
    father[u]=v;
    mx[v]=max(mx[v],mx[u]);
}
void cover(int L,int R)
{
    int cur=L;
    while (cur<=R) {
        int nxt=mx[_find(cur)]+1;
        //if (nxt>R) return ;
        _merge(cur,min(nxt,R));
        cur=nxt;
    }
}
int calc(int bt)
{
    for (int i=1;i<=n+1;i++) {
        father[i]=i; mx[i]=i; bo[i]=0; f[i]=0;
    }
    for (int i=1;i<=m;i++) {
        if (x[i]&(1<<bt)) cover(l[i],r[i]);
        else {
            f[r[i]+1]=max(f[r[i]+1],l[i]);
        }
    }
    for (int i=1;i<=n+1;i++) bo[i]=bo[_find(i)];
    for (int i=1;i<=n+1;i++) f[i]=max(f[i],f[i-1]);
    dp[0]=1; sum[0]=1;
    for (int i=1;i<=n+1;i++) {
        if (bo[i]) dp[i]=0;
        else if (f[i]>=1) dp[i]=(sum[i-1]-sum[f[i]-1]+mod)%mod;
        else dp[i]=sum[i-1];
        sum[i]=(sum[i-1]+dp[i])%mod;
    }
    return dp[n+1];
}
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for (int i=1;i<=m;i++) scanf("%d%d%d",&l[i],&r[i],&x[i]);
    int ans=1;
    for (int bt=0;bt<k;bt++) ans=1LL*ans*calc(bt)%mod;
    printf("%d\n",ans);
    return 0;
}*/

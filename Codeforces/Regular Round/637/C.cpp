#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
const int mod=1e9+7;
typedef long long ll;
typedef double db;
int gcd(int n,int m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
int quick_pow(int a,int b,int mod)
{
    int ans=1;
    while (b) {
        if (b&1LL) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans%mod;
}
inline ll quick_mul(ll x,ll y,ll mod)
{
    return (x*y-(ll)((long double)x/mod*y)*mod+mod)%mod;
}
queue<pair<int,int> > q;
ll dp[maxn+5][1005];
int a[maxn+5];
int n,m;
int g,b;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    m=unique(a+1,a+m+1)-(a+1);
    scanf("%d%d",&g,&b);
    memset(dp,-1,sizeof(dp));
    dp[1][0]=0;
    q.push(make_pair(1,0));
    while (q.size()) {
        pair<int,int> e=q.front(); q.pop();
        int x=e.first,y=e.second;
        if (x!=1) {
            if (y+a[x]-a[x-1]<=g) {
                int x0=x-1,y0=(y+a[x]-a[x-1])%g;
                if (dp[x0][y0]==-1||dp[x0][y0]>dp[x][y]+a[x]-a[x-1]+((y0==0)?b:0)) {
                    dp[x0][y0]=dp[x][y]+(a[x]-a[x-1]);
                    if (y0==0) dp[x0][y0]+=b;
                    q.push(make_pair(x0,y0));
                }
            }
        }
        if (x!=m) {
            if (y+a[x+1]-a[x]<=g) {
                int x0=x+1,y0=(y+a[x+1]-a[x])%g;
                if (dp[x0][y0]==-1||dp[x0][y0]>dp[x][y]+a[x+1]-a[x]+((y0==0)?b:0)) {
                    dp[x0][y0]=dp[x][y]+(a[x+1]-a[x]);
                    if (y0==0) dp[x0][y0]+=b;
                    q.push(make_pair(x0,y0));
                }
            }
        }
    }
    ll ans=INF;
    for (int i=1;i<=m;i++)
        if (dp[i][0]!=-1&&n-a[i]<=g) ans=min(ans,dp[i][0]+n-a[i]);
    if (ans==INF) printf("-1\n");
    else printf("%lld\n",ans);
    return 0;
}

#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int INF=0x3f3f3f3f;
const int maxn=1e5;
int dp[maxn][5];
int a[maxn],b[maxn],n;
int calc(int a[])
{
    memset(dp,0x3f,sizeof(dp));
    rep(i,1,4)
    if (a[1]==i) dp[1][i]=0;
    else dp[1][i]=1;
    rep(i,2,n+1)
        rep(j,1,4)
        rep(k,j,4) dp[i][k]=min(dp[i][k],dp[i-1][j]+(a[i]!=k));
    int ans=INF;
    rep(i,1,4)
        if (ans>dp[n][i]) ans=dp[n][i];
    return ans;
}
int main()
{
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",&a[i]);
    rep(i,1,n+1) b[i]=a[n+1-i];
    printf("%d\n",min(calc(a),calc(b)));
    return 0;
}

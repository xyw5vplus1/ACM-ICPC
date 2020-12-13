#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int INF=0x3f3f3f3f;
const int maxn=1000+10;
int a[maxn],b[maxn],dp[maxn][maxn];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    for (int i=1;i<=n;i++) dp[i][0]=i;
    for (int j=1;j<=m;j++) dp[0][j]=j;
    dp[0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
        else {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
        }
    printf("%d\n",dp[n][m]);
    /*for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) printf("%d ",dp[i][j]); printf("\n");
    }*/
    return 0;
}


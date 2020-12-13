#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=200+10;
ll dp[maxn][50];
int n;
int main()
{
    scanf("%d",&n);
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=12;j++)
            for (int k=0;k<i;k++)
                dp[i][j]=(dp[i][j]+dp[k][j-1]);
    printf("%lld\n",dp[n][12]);
    return 0;
}


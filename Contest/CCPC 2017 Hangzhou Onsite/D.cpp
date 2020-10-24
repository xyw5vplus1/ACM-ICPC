#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int mod=998244353;
int inv[maxn],dp[maxn],sum[maxn],a[maxn];
int T,n;
void setInv(int n)
{
    inv[0]=inv[1]=1;
    for (int i=2;i<=n;i++)
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}
int main()
{
    setInv(maxn);
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        dp[0]=1; sum[0]=1;
        for (int i=1;i<n;i++) {
            dp[i]=(1LL*sum[i-1]*inv[i]%mod+1)%mod;
            sum[i]=(sum[i-1]+dp[i])%mod;
        }
        //for (int i=0;i<n;i++) printf("debug %d %d\n",i,dp[i]);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        int tot=0;
        for (int i=0;i<n;i++) {
            tot=(tot+1LL*a[i]*dp[i]%mod)%mod;
        }
        tot=1LL*tot*inv[n]%mod;
        printf("%d\n",tot);
    }
    return 0;
}
/*
2
2
1 1
3
1 2 3
*/

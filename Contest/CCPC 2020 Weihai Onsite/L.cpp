#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e4+10;
const int maxnum=3245+10;
bool is_prime[maxn];
int primes[maxn];
int num=0;
double dp[maxnum][maxn];
void Sieve(int n)
{
    for (int i=2;i<=n;i++) is_prime[i]=true;
    for (int i=2;i<=n;i++) {
        if (is_prime[i]) primes[++num]=i;
        for (int j=1;j<=num&&1LL*primes[j]*i<=n;j++) {
            is_prime[i*primes[j]]=false;
            if (i%primes[j]==0) break;
        }
    }
}
int T,n;
int main()
{
    Sieve(1000);
    for (int k=1;k<=num;k++) {
        for (int j=0;j<=maxn;j++) {
            dp[k][j]=dp[k-1][j];
            for (ll i=1,cnt=0;i<=j;i*=primes[k],cnt++) {
                if (dp[k-1][j-i]+cnt*log(primes[k])>dp[k][j]) {
                    dp[k][j]=dp[k-1][j-i]+cnt*log(primes[k]);
                }
            }
        }
    }
    //printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        printf("%.12f\n",dp[num][n]);
    }
    /*int ans=0;
    for (int i=1;i<=maxn;i++)
        ans=max(ans,mx[num][i]);
    printf("%d\n",ans);*/
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int mod=998244353;
int phi[maxn],primes[maxn];
bool is_prime[maxn];
int num=0;
int T,p,q,n;
void Sieve(int n)
{
    for (int i=2;i<=n;i++) {
        is_prime[i]=true;
        phi[i]=i;
    }
    phi[1]=1;
    for (int i=2;i<=n;i++) {
        if (is_prime[i]) {
            primes[num++]=i; phi[i]=i-1;
        }
        for (int j=0;j<num&&i*primes[j]<=n;j++) {
            is_prime[i*primes[j]]=false;
            if (i%primes[j]==0) {
                phi[i*primes[j]]=phi[i]*primes[j];
                break;
            }
            else {
                phi[i*primes[j]]=phi[i]*(primes[j]-1);
            }
        }
    }
}
int quick_pow(int a,int b)
{
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans;
}
int calc(int p,int q)
{
    int ans=1;
    ans=1LL*(p-1)*quick_pow(p,q-1)%mod*q%mod;
    ans=(ans+quick_pow(p,q))%mod;
    return ans;
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        int ans=1;
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&p,&q);
            ans=1LL*ans*calc(p,q)%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
2
2 1
3 1
2
2 2
3 2
*/

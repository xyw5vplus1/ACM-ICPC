#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
typedef long long ll;
bool is_prime[maxn+5];
int primes[maxn+5];
int num=0;
ll gcd(ll n,ll m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
void Sieve(int n)
{
    for (int i=2;i<=n;i++) is_prime[i]=true;
    for (int i=2;i<=n;i++) {
        if (is_prime[i]) primes[num++]=i;
        for (int j=0;j<num&&1LL*i*primes[j]<=n;j++) {
            is_prime[i*primes[j]]=false;
            if (i%primes[j]==0) break;
        }
    }
}
ll getPhi(ll x)
{
    ll ans=x;
    for (int i=0;i<num&&1LL*primes[i]*primes[i]<=x;i++) {
        if (x%primes[i]==0) {
            while (x%primes[i]==0) x/=primes[i];
            ans=ans/primes[i]*(primes[i]-1);
        }
    }
    if (x>1) ans=ans/x*(x-1);
    return ans;
}
int T;
ll a,m;
int main()
{
    Sieve(maxn);
    scanf("%d",&T);
    while (T--) {
        scanf("%I64d%I64d",&a,&m);
        ll d=gcd(a,m);
        a/=d; m/=d;
        printf("%I64d\n",getPhi(m));
    }
    return 0;
}



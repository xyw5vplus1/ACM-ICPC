#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
const int mod=1e9+7;
int primes[maxn];
bool is_prime[maxn];
int num=0;
vector<int> e[maxn];
int n;
int a[maxn];
ll quick_pow(ll a,int b)
{
    ll ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a;
        a=1LL*a*a;
        b>>=1;
    }
    return ans;
}
int gcd(int n,int m)
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
void divide(int x)
{
    for (int i=2;i<maxn&&i*i<=x;i++)
    if (x%i==0) {
        int cnt=0;
        while (x%i==0)
        {
            x/=i; cnt++;
        }
        e[i].pb(cnt);
    }
    if (x>1) e[x].pb(1);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    Sieve(200000);
    for (int i=1;i<=n;i++) divide(a[i]);
    //printf("lala\n");
    ll ans=1;
    for (int i=0;i<maxn;i++) sort(e[i].begin(),e[i].end());
    //for (int i=0;i<10;i++) printf("%d %d\n",i,e[i].size());
    for (int i=2;i<maxn;i++) {
        if (e[i].size()==n-1) ans=1LL*ans*quick_pow(i,e[i][0]);
        else if (e[i].size()==n) ans=1LL*ans*quick_pow(i,e[i][1]);
        //printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

typedef long long LL;

const LL maxn=1e10+10;

const int maxn1=1e7+10;
bool is_prime[maxn1];
int primes[maxn1];
LL psum[maxn1];
int n0;
namespace Min25 {

    int prime[N], id1[N], id2[N], flag[N], ncnt, m;

    LL g[N], sum[N], a[N], T, n;

    inline int ID(LL x) {
        return x <= T ? id1[x] : id2[n / x];
    }

    inline LL calc(LL x) {
        return x * (x + 1) / 2 - 1;
    }

    inline LL f(LL x) {
        return x;
    }

    inline void init() {
        T = sqrt(n + 0.5);
        ncnt=0; m=0;
        for (int i = 2; i <= T; i++) {
            if (!flag[i]) prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
            for (int j = 1; j <= ncnt && i * prime[j] <= T; j++) {
                flag[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;
            }
        }
        for (LL l = 1; l <= n; l = n / (n / l) + 1) {
            a[++m] = n / l;
            if (a[m] <= T) id1[a[m]] = m; else id2[n / a[m]] = m;
            g[m] = calc(a[m]);
        }
        for (int i = 1; i <= ncnt; i++)
            for (int j = 1; j <= m && (LL)prime[i] * prime[i] <= a[j]; j++)
                g[j] = g[j] - (LL)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
    }

    inline LL solve(LL x) {
        if (x <= 1) return x;
        return n = x, init(),g[ID(n)];
    }
}
int quick_pow(int a,int b,int mod)
{
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans;
}
void setPrime(int n)
{
    for (int i=2;i<=n;i++) is_prime[i]=true;
    for (int i=2;i<=n;i++) {
        if (is_prime[i]) primes[++n0]=i;
        for (int j=1;j<=n0&&1LL*primes[j]*i<=n;j++) {
            is_prime[i*primes[j]]=false;
            if (i%primes[j]==0) break;
        }
    }
}
int T,mod;
int main() 
{
    n0=0;
    setPrime(maxn1);
    //for (int i=1;i<=10;i++) printf("%d %d\n",i,primes[i]);
    for (int i=1;i<=n0;i++) psum[i]=psum[i-1]+primes[i];

    scanf("%d",&T);
    while (T--) {
        LL n; 
        scanf("%lld", &n);
        scanf("%d",&mod);
        if (n>=maxn1) {
            LL ans=1LL*(n%mod)*((n+3)%mod)%mod;
            ans=1LL*ans*quick_pow(2,mod-2,mod)%mod;
            LL ans2=Min25::solve(n+1);
            ans2=(ans2+ans)%mod;
            ans2=(ans2-4+mod)%mod;
            printf("%lld\n",ans2);
        }
        else {
            int k=upper_bound(primes+1,primes+n0+1,n+1)-(primes+1);
            LL ans=1LL*n*(n+3)%mod;
            ans=1LL*ans*quick_pow(2,mod-2,mod)%mod;
            LL ans2=psum[k];
            ans2=(ans2+ans)%mod;
            ans2=(ans2-4+mod)%mod;
            printf("%lld\n",ans2);
        }
    }
    return 0;
}
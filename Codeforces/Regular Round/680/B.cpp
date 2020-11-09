#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int mod=998244353;
const int maxn=3e5+10;
int a[maxn],inv[maxn],fac[maxn],facInv[maxn];
void setInv(int n)
{
    inv[0]=inv[1]=1;
    for (int i=2;i<=n;i++)
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}
void setFac(int n)
{
    fac[0]=1; facInv[0]=1;
    for (int i=1;i<=n;i++) {
        fac[i]=1LL*fac[i-1]*i%mod;
        facInv[i]=1LL*facInv[i-1]*inv[i]%mod;
    }
}
int C(int n,int m)
{
    if (n<m) return 0;
    if (n<0||m<0) return 0;
    int ans=fac[n];
    ans=ans*1LL*facInv[m]%mod;
    ans=ans*1LL*facInv[n-m]%mod;
    return ans;
}
int n;
int main()
{
    setInv(maxn); setFac(maxn);
    scanf("%d",&n);
    for (int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    ll sum=0;
    for (int i=1;i<=n;i++) sum+=a[i+n]-a[i];
    printf("%lld\n",sum%mod*C(2*n,n)%mod);
    return 0;
}


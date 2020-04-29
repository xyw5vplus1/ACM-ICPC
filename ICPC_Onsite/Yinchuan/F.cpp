#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
int inv2,inv6;
ll n;
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
int sum1(ll x)
{
    x%=mod;
    return 1LL*x*(x+1)%mod*inv2%mod;
}
int sum1(ll l,ll r)
{
    return (sum1(r)-sum1(l-1)+mod)%mod;
}
int sum2(ll x)
{
    x%=mod;
    return 1LL*x*(x+1)%mod*(2*x+1)%mod*inv6%mod;
}
int sum2(ll l,ll r)
{
    return (sum2(r)-sum2(l-1)+mod)%mod;
}
int calc(int n)
{
    int ans=0;
    for (int i=2;i<=n;i++)
    for (int j=i;j<=n;j++) {
        double tem=log(j)/log(i);
        int t=floor(tem); ans=(ans+i*t)%mod;
    }
    return ans;
}
int main()
{
    scanf("%lld",&n);
    int m=floor(sqrt(n*1.0))+1;
    inv2=quick_pow(2,mod-2); inv6=quick_pow(6,mod-2);
    int ans=0;
    ans=(ans+1LL*(n+1)%mod*sum1(m,n)%mod)%mod;
    ans=(ans-sum2(m,n)+mod)%mod;
    for (int i=2;i<=m-1;i++) {
        ll cur=i,last=i; int cnt=0;
        while (cur<=n) {
            cur=last*i; cnt++;
            if (cur>n) {
                ans=(ans+cnt*(n-last+1)%mod*i%mod)%mod;
                //printf("debug %lld %lld %d\n",last,n,cnt);
                break;
            }
            else {
                ans=(ans+cnt*(cur-last)%mod*i%mod)%mod;
                //printf("debug %lld %lld\n",last,cur);
            }
            last=cur;
        }
    }
    printf("%d\n",ans);
    return 0;
}

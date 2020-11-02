#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e6;
/*const ll INF=1e18;
vector<int> factors;
mt19937 myrand(time(0));
ll rand_x(ll up)
{
    ll tem=myrand();
    tem%=up;
    tem=(tem+up)%up;
    return tem;
}
inline ll quick_mul(ll x,ll y,ll mod)
{
    return (x*y-(ll)((long double)x/mod*y)*mod+mod)%mod;
}
ll quick_pow(ll a,ll b,ll mod)
{
    ll ans=1;
    while (b) {
        if (b&1LL) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1LL;
    }
    return ans%mod;
}
bool check(ll a,ll n,ll x,ll t)
{
    ll tem=quick_pow(a,x,n);
    ll last=tem;
    for (int i=1;i<=t;i++) {
        tem=quick_mul(tem,tem,n);
        if (tem==1&&last!=1&&last!=n-1) return true;
        last=tem;
    }
    if (last!=1) return true;
    return false;
}
bool Miller_Rabin(ll n)
{
    if (n<2) return false;
    if (n==2) return true;
    if (!(n&1LL)) return false;
    ll x=n-1,t=0;
    while (!(x&1LL)) {
        x>>=1LL; t++;
    }
    for (int i=0;i<8;i++) {
        ll a=rand_x((n-1))+1;
        if (check(a,n,x,t)) return false;
    }
    return true;
}
ll pollard_rho(ll x,ll c)
{
    ll i=1,k=2;
    ll x0=rand_x((x-1))+1;
    ll y=x0;
    while (true) {
        i++;
        x0=(quick_mul(x0,x0,x)+c)%x;
        ll d=abs(__gcd(y-x0,x));
        if (d!=1&&d!=x) return d;
        if (y==x0) return x;
        if (i==k) {
            y=x0; k+=k;
        }
    }
}
void FindFac(ll n,int k)
{
    //printf("debug %lld\n",n);
    if (n==1) return ;
    if (Miller_Rabin(n)) {
        factors.push_back(n);
        return ;
    }
    ll p=n;
    int c=k;
    while (p>=n) p=pollard_rho(p,c--);
    FindFac(p,k);
    FindFac(n/p,k);
}*/
int T;
ll n;
int main()
{
    scanf("%d",&T);
    //T=10;
    while (T--) {
        //n=rand_x(INF);
        scanf("%lld",&n);
        //factors.clear();
        if (n==1) {
            printf("no\n");
            continue;
        }
        /*FindFac(n,107);
        sort(factors.begin(),factors.end());
        //for (int i=0;i<factors.size();i++) printf("%d ",factors[i]); printf("\n");
        bool bo=false;
        for (int i=0;i<factors.size()-1;i++)
        if (factors[i]==factors[i+1]) {
            bo=true;
        }*/
        bool bo=false;
        for (int i=2;1LL*i*i<=n&i<=INF;i++)
        if (n%(1LL*i*i)==0) {
            bo=true; break;
        }
        for (int i=1;i<=min(1LL*INF,n-1);i++) {
            if (n%i) continue;
            ll tem=n/i;
            ll p=sqrt(tem*1.0);
            if (p*p==tem) {
                //printf("debug %lld\n",p);
                bo=true; break;
            }
        }
        if (bo) printf("yes\n");
        else printf("no\n");
    }
    //printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

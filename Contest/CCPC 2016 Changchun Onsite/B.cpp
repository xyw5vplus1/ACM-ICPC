#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000;
int T,n;
ll a[maxn],b[maxn];
struct frac
{
    ll x,y;
}c[maxn];
ll gcd(ll n,ll m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
        c[n].x=b[n]; c[n].y=a[n];
        ll d=gcd(c[n].x,c[n].y);
        c[n].x/=d; c[n].y/=d;
        for (int i=n-1;i>=1;i--) {
            ll x0=b[i]*c[i+1].y;
            ll y0=a[i]*c[i+1].y+c[i+1].x;
            ll d=gcd(x0,y0);
            c[i].x=x0/d; c[i].y=y0/d;
        }
        printf("Case #%d: %lld %lld\n",kase,c[1].x,c[1].y);
    }
    return 0;
}

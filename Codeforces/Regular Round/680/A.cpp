#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const ll INF=1e18;
int T;
ll p;
int q;
ll left(ll p,ll prime)
{
    ll n=p;
    ll tem=1;
    while (n%prime==0) {
        tem*=prime; n/=prime;
    }
    return p/tem;
}
ll getAns(int q)
{
    ll mx=0;
    for (int i=2;i*i<=q;i++)
    if (q%i==0) {
        //printf("debug %d\n",i);
        ll tem=1;
        while (q%i==0) {
            q/=i; tem*=i;
        }
        tem/=i;
        if (tem*left(p,i)>mx) mx=tem*left(p,i);
        //printf("debug %lld\n",tem*left(p,i));
    }
    if (q>1) {
        if (left(p,q)>mx) mx=left(p,q);
    }
    return mx;
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%lld%d",&p,&q);
        if (p%q!=0) printf("%lld\n",p);
        else {
            printf("%lld\n",getAns(q));
        }
    }
    return 0;
}


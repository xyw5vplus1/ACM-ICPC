#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
ll n;
int main()
{
    scanf("%lld",&n);
    ll l=1,r=sqrt(2.0*n)+10;
    while (l<r) {
        ll mid=(l+r+1)>>1LL;
        if (mid*(mid+1)/2<=n+1) l=mid;
        else r=mid-1;
    }
    printf("%lld\n",n+1-l);
    return 0;
}


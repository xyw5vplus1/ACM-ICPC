#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define first fi
#define second se
using namespace std;
typedef long long ll;
typedef double db;
int n,s,k;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0) {
        x=1; y=0; return a;
    }
    ll r=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return r;
}
int T;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&s,&k);
        int d=__gcd(n,k);
        if ((n-s)%d!=0) printf("-1\n");
        else {
            ll x,y;
            exgcd(k,n,x,y);
            x*=(n-s)/d;
            int t=(n/d);
            x=(x%t+t)%t;
            printf("%lld\n",x);
        }
    }
    return 0;
}


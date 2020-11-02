#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n,x,t;
        scanf("%lld%lld%lld",&n,&x,&t);
        ll ans1 = max(2*n*t, x+t) + 2 * n * t;
        ll remain = max(0ll, x + t - 2 * n * t);
        if(remain < t) ans1 += t - remain;
        ll ans2 = max(2*n*t, x + 2 * t) + 2 * n * t;
        printf("%lld\n", min(ans1, ans2));
    }
    /*
    100
199 23 233
185468
201 11 1
804
201 1 101
81204
201 11 19
15276
133 233 19
10108
100
199 23 233
9200
185468
    */
    return 0;

}

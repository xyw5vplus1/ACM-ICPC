#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
int T;
ll l,r;
int a[20];
ll pw[20];
ll calc(ll up)
{
    int len=0;
    ll m=up;
    while (m) {
        a[++len]=m%10;
        m/=10;
    }
    ll ans=0;
    for (int i=len;i>=1;i--)
    if (a[i]%2==(len-i+1)%2) {
        ans+=(a[i]/2)*pw[i-1];
    }
    else {
        if (a[i]%2==0) ans+=(a[i]/2)*pw[i-1];
        else ans+=(a[i]/2+1)*pw[i-1];
        break;
    }
    for (int i=len-1;i>=1;i--) ans+=pw[i];
    return ans;
}
int main()
{
    pw[0]=1;
    for (int i=1;i<=18;i++) pw[i]=pw[i-1]*5;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%lld%lld",&l,&r);
        printf("Case #%d: %lld\n",kase,calc(r+1)-calc(l));
        //printf("debug %lld %lld\n",calc(l),calc(r+1));
    }
    return 0;
}
/*
3
5 15
120 125
779 783
*/

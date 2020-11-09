#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll INF=1e10;
int T;
ll a[maxn],b[maxn];
int n;
bool check(ll k)
{
    ll sum=0;
    for (int i=1;i<=n;i++) b[i]=a[i]-k;
    for (int i=1;i<=n;i++) {
        if (b[i]<0) sum-=b[i];
        if (sum>k) return false;
    }
    return true;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        ll l=0,r=INF;
        while (l<r) {
            ll mid=(l+r+1)>>1LL;
            if (check(mid)) l=mid;
            else r=mid-1;
        }
        printf("Case #%d: %lld\n",kase,l+1);
    }
    return 0;
}

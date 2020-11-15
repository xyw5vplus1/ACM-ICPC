#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const ll INF=1e18;
const int maxn=1e5+10;
int T;
int n;
int x[maxn],y[maxn];
int dx,dy;
ll myDist(ll x,ll y)
{
    ll dist=x-y;
    if (dist>=0) return dist;
    return -dist;
}
ll calcDist(ll pos)
{
    ll tot=0;
    for (int i=1;i<=n;i++)
        tot+=myDist(1LL*x[i],1LL*(pos+i-1));
    return tot;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d",&n);
        ll ans1=0;
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&dx,&dy);
            x[i]=dx; y[i]=dy;
        }
        sort(x+1,x+n+1); sort(y+1,y+n+1);
        int posy=y[(n+1)/2];
        for (int i=1;i<=n;i++) ans1+=abs(y[i]-posy);
        ll l=x[1]-n,r=x[n];
        while (l+2<r) {
            ll t1=(l+l+r)/3,t2=(l+r+r)/3;
            ll ans1=calcDist(t1),ans2=calcDist(t2);
            if (ans1<ans2) r=t2;
            else if (ans2<ans1) l=t1;
            else {
                l=t1; r=t2;
            }
        }
        //printf("debug %lld %lld\n",l,r);
        ll ans2=INF;
        ans2=min(ans2,calcDist(l));
        if (l+1<=r) ans2=min(ans2,calcDist(l+1));
        if (l+2<=r) ans2=min(ans2,calcDist(l+2));
        printf("Case #%d: %lld\n",kase,ans1+ans2);
        //printf("debug %lld %lld\n",ans1,ans2);
    }
    return 0;
}


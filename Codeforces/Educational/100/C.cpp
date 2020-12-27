#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
const ll INF=1e18;
struct event
{
    ll time;
    int x;
}a[maxn];
vector<pair<ll,ll> > vtime;
vector<pair<int,int> > vpos;
int T,n;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%lld%d",&a[i].time,&a[i].x);
        }
        vtime.clear(); vpos.clear();
        int ans=0;
        a[n+1].time=INF;
        ll curt=0;
        int curx=0;
        for (int i=1;i<=n;i++) {
            if (curt<=a[i].time) {
                if (abs(curx-a[i].x)<=a[i+1].time-a[i].time) ans++;
                vtime.pb(make_pair(a[i].time,a[i].time+abs(curx-a[i].x)));
                vpos.pb(make_pair(curx,a[i].x));
                curt=a[i].time+abs(curx-a[i].x);
                curx=a[i].x;
            }
            else {
                ll up=min(curt,1LL*a[i+1].time);
                ll Lt=vtime[vtime.size()-1].first,Rt=vtime[vtime.size()-1].second;
                int from=vpos[vpos.size()-1].first,to=vpos[vpos.size()-1].second;
                if (from<=a[i].x&&a[i].x<=to||from>=a[i].x&&a[i].x>=to) {
                    ll need=abs(from-a[i].x)+Lt;
                    if (need>=a[i].time&&need<=up) {
                        ans++;
                    }
                }
            }
            //printf("debug %d %d\n",i,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
1
8
1 1
2 -6
7 2
8 3
12 -9
14 2
18 -1
23 9
*/

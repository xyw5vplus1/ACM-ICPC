#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a-1;i>=b;i--)
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int maxn=1e5+10;
const db eps=1e-6;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,k,cmpd,qid;
ll qx,qy;
priority_queue<ll,vector<ll>,greater<ll> > q;
struct node
{
    int l,r;
    ll mx[2],mn[2];
    ll d[2];
}tr[maxn];
ll a[maxn];
bool cmp(node a,node b)
{
    return a.d[cmpd]<b.d[cmpd]||(a.d[cmpd]==b.d[cmpd]&&a.d[cmpd^1]<b.d[cmpd^1]);
}
ll getDist(ll x0,ll y0,ll qx,ll qy)
{
    return (x0-qx)*(x0-qx)+(y0-qy)*(y0-qy);
}
void updateMin(ll &x,ll y)
{
    x=min(x,y);
}
void updateMax(ll &x,ll y)
{
    x=max(x,y);
}
void pushup(int p)
{
    int l,r;
    l=tr[p].l; r=tr[p].r;
    if (l) {
        updateMax(tr[p].mx[0],tr[l].mx[0]);
        updateMax(tr[p].mx[1],tr[l].mx[1]);
        updateMin(tr[p].mn[0],tr[l].mn[0]);
        updateMin(tr[p].mn[1],tr[l].mn[1]);
    }
    if (r) {
        updateMax(tr[p].mx[0],tr[r].mx[0]);
        updateMax(tr[p].mx[1],tr[r].mx[1]);
        updateMin(tr[p].mn[0],tr[r].mn[0]);
        updateMin(tr[p].mn[1],tr[r].mn[1]);
    }
}
int build(int l,int r,int d) //建K-D tree的过程，l,r为数组下标，d为当前划分的维度
{
    int mid=(l+r)>>1;
    int p=mid;
    cmpd=d;
    nth_element(tr+l,tr+mid,tr+r+1,cmp); //能够按照第d维的大小对区间进行划分
    tr[p].mx[0]=tr[p].mn[0]=tr[p].d[0];
    tr[p].mx[1]=tr[p].mn[1]=tr[p].d[1];
    if (l<mid) tr[p].l=build(l,mid-1,d^1);
    if (mid<r) tr[p].r=build(mid+1,r,d^1);
    pushup(p);
    return p;
}
ll getDistMax(int p,ll qx,ll qy)//统计某个点(qx,qy)到以p为根的矩形区域的最近距离
    //其中，如果查询点在矩形区域内部，则需要继续递归，当前返回值为0。
{
    ll l,r;
    l=max(abs(qx-tr[p].mn[0]),abs(qx-tr[p].mx[0]));
    r=max(abs(qy-tr[p].mn[1]),abs(qy-tr[p].mx[1]));
    ll dist=(l*l+r*r);
    return dist;
}
void updateAns(ll val)
{
    if (q.size()<k) q.push(val);
    else {
        if (val<q.top()) return ;
        q.push(val); q.pop();
    }
}
void show()
{
    int t=0;
    while (q.size()) {
        a[++t]=q.top(); q.pop();
    }
    rep(i,1,t+1) printf("%d ",a[i]); printf("\n");
    rep(i,1,t+1) q.push(a[i]);
}
void queryMax(int p)
{
    if (!p) return ;
    ll d=getDist(tr[p].d[0],tr[p].d[1],qx,qy);
    //printf("dfs %d %d %lld\n",p,qid,d);
    //printf("calc %lld %lld %lld %lld\n",tr[p].d[0],tr[p].d[1],qx,qy);
    if (qid!=p) updateAns(d);
    //printf("debug %d\n",qid);
    //show();
    ll dl=0,dr=0;
    if (tr[p].l) dl=getDistMax(tr[p].l,qx,qy);
    if (tr[p].r) dr=getDistMax(tr[p].r,qx,qy);
    if (dl>dr) {
        if (q.size()<k||dl>q.top()) queryMax(tr[p].l);
        if (q.size()<k||dr>q.top()) queryMax(tr[p].r);
    }
    else {
        if (q.size()<k||dr>q.top()) queryMax(tr[p].r);
        if (q.size()<k||dl>q.top()) queryMax(tr[p].l);
    }
    //printf("debug %d\n",qid);
    //show();
}
int main()
{
    scanf("%d%d",&n,&k);
    k<<=1;
    rep(i,1,n+1) scanf("%lld%lld",&tr[i].d[0],&tr[i].d[1]);
    int root=build(1,n,0);
    //printf("root=%d\n",root);
    //rep(i,1,n+1) printf("%d (%lld,%lld) %d %d\n",i,tr[i].d[0],tr[i].d[1],tr[i].l,tr[i].r);
    rep(i,1,n+1) {
        qx=tr[i].d[0]; qy=tr[i].d[1]; qid=i;
        queryMax(root);
        //show();
    }
    printf("%lld\n",q.top());
    return 0;
}



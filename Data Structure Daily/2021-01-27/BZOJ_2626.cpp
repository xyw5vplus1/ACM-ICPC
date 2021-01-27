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
const int maxn=5e5+10;
const int INF=0x3f3f3f3f;
int n,m,k,qx,qy,cmpd;
struct node
{
    int l,r;
    int mx[2],mn[2],mnd;
    int d[2];
    int id;
}tr[maxn];
priority_queue<pair<ll,int> > q;
ll getDist(int x0,int y0,int x1,int y1)
{
    return 1LL*(x0-x1)*(x0-x1)+1LL*(y0-y1)*(y0-y1);
}
bool cmp(node a,node b)
{
    return a.d[cmpd]<b.d[cmpd]||(a.d[cmpd]==b.d[cmpd]&&a.d[cmpd^1]<b.d[cmpd^1]);
}
void updateMax(int &x,int y)
{
    x=max(x,y);
}
void updateMin(int &x,int y)
{
    x=min(x,y);
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
        updateMin(tr[p].mnd,tr[l].mnd);
    }
    if (r) {
        updateMax(tr[p].mx[0],tr[r].mx[0]);
        updateMax(tr[p].mx[1],tr[r].mx[1]);
        updateMin(tr[p].mn[0],tr[r].mn[0]);
        updateMin(tr[p].mn[1],tr[r].mn[1]);
        updateMin(tr[p].mnd,tr[r].mnd);
    }
}
int build(int l,int r,int d) //建K-D tree的过程，l,r为数组下标，d为当前划分的维度
{
    int mid=(l+r)>>1;
    int p=mid;
    cmpd=d;
    nth_element(tr+l,tr+mid+1,tr+r+1,cmp); //能够按照第d维的大小对区间进行划分
    tr[p].mx[0]=tr[p].mn[0]=tr[p].d[0];
    tr[p].mx[1]=tr[p].mn[1]=tr[p].d[1];
    tr[p].mnd=tr[p].id;
    if (l<mid) tr[p].l=build(l,mid-1,d^1);
    if (mid<r) tr[p].r=build(mid+1,r,d^1);
    pushup(p);
    return p;
}
ll getDistMax(int p,int qx,int qy)
{
    int dist=0;
    int l=max(abs(qx-tr[p].mn[0]),abs(qx-tr[p].mx[0]));
    int r=max(abs(qy-tr[p].mn[1]),abs(qy-tr[p].mx[1]));
    return 1LL*l*l+1LL*r*r;
}
void updateVal(pair<ll,int> e)
{
    if (q.size()<k) {
        q.push(e); return ;
    }
    else {
        if (e<q.top()) {
            q.pop(); q.push(e);
        }
    }
}
void queryMax(int p)
{
    if (!p) return ;
    ll d=getDist(tr[p].d[0],tr[p].d[1],qx,qy);
    updateVal(mp(-d,tr[p].id));
    ll dl=0,dr=0;
    if (tr[p].l) dl=getDistMax(tr[p].l,qx,qy);
    if (tr[p].r) dr=getDistMax(tr[p].r,qx,qy);
    //下面的代码用了启发式搜索的思想，先找更容易使mx变大的那一侧子树
    if (dl>dr) {
        if (q.size()<k||mp(-dl,tr[tr[p].l].mnd)<q.top()) queryMax(tr[p].l);
        if (q.size()<k||mp(-dr,tr[tr[p].r].mnd)<q.top()) queryMax(tr[p].r);
    }
    else {
        if (q.size()<k||mp(-dr,tr[tr[p].r].mnd)<q.top()) queryMax(tr[p].r);
        if (q.size()<k||mp(-dl,tr[tr[p].l].mnd)<q.top()) queryMax(tr[p].l);
    }
}
pair<ll,int> a[100];
void show()
{
    int t=0;
    while (q.size()) {
        a[++t]=q.top(); q.pop();
    }
    rep(i,1,t+1) {
        printf("debug %lld %d\n",a[i].first,a[i].second);
    }
    rep(i,1,t+1) q.push(a[i]);
}
int main()
{
    scanf("%d",&n);
    rep(i,1,n+1) {
        scanf("%d%d",&tr[i].d[0],&tr[i].d[1]);
        tr[i].id=i;
    }
    int root=build(1,n,0);
    scanf("%d",&m);
    rep(_,0,m) {
        scanf("%d%d%d",&qx,&qy,&k);
        while (q.size()) q.pop();
        queryMax(root);
        printf("%d\n",q.top().second);
        //show();
    }
    return 0;
}

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
const ll INF=1e18;
int n,cmpd,qid;
db qx,qy,mx,mn,ans0,ans1;
struct node
{
    int l,r;
    db mx[2],mn[2];
    db d[2];
}tr[maxn];
bool cmp(node a,node b)
{
    return a.d[cmpd]<b.d[cmpd]||(a.d[cmpd]==b.d[cmpd]&&a.d[cmpd^1]<b.d[cmpd^1]);
}
db getDist(db x0,db y0,db qx,db qy)
{
    return sqrt((x0-qx)*(x0-qx)+(y0-qy)*(y0-qy));
}
void updateMin(db &x,db y)
{
    x=min(x,y);
}
void updateMax(db &x,db y)
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
db getDistMin(int p,db qx,db qy)//统计某个点(qx,qy)到以p为根的矩形区域的最近距离
    //其中，如果查询点在矩形区域内部，则需要继续递归，当前返回值为0。
{
    db dist=0;
    if (qx>=tr[p].mn[0]&&qx<=tr[p].mx[0]&&qy>=tr[p].mn[1]&&qy<=tr[p].mx[1]) return 0.0;
    db l,r;
    l=min(abs(qx-tr[p].mn[0]),abs(qx-tr[p].mx[0]));
    r=min(abs(qy-tr[p].mn[1]),abs(qy-tr[p].mx[1]));
    if (qx>=tr[p].mn[0]&&qx<=tr[p].mx[0]) return r;
    if (qy>=tr[p].mn[1]&&qy<=tr[p].mx[1]) return l;
    dist=sqrt(l*l+r*r);
    return dist;
}
db getDistMax(int p,db qx,db qy)//统计某个点(qx,qy)到以p为根的矩形区域的最近距离
    //其中，如果查询点在矩形区域内部，则需要继续递归，当前返回值为0。
{
    db l,r;
    l=max(abs(qx-tr[p].mn[0]),abs(qx-tr[p].mx[0]));
    r=max(abs(qy-tr[p].mn[1]),abs(qy-tr[p].mx[1]));
    db dist=sqrt(l*l+r*r);
    return dist;
}
void queryMin(int p)
{
    if (!p) return ;
    db d=getDist(tr[p].d[0],tr[p].d[1],qx,qy);
    if (qid!=p) updateMin(mn,d);
    db dl=1.0*INF,dr=1.0*INF;
    if (tr[p].l) dl=getDistMin(tr[p].l,qx,qy);
    if (tr[p].r) dr=getDistMin(tr[p].r,qx,qy);
    //下面的代码用了启发式搜索的思想，先找更容易使mn变小的那一侧子树
    if (dl<dr) {
        if (dl<mn) queryMin(tr[p].l);
        if (dr<mn) queryMin(tr[p].r);
    }
    else {
        if (dr<mn) queryMin(tr[p].r);
        if (dl<mn) queryMin(tr[p].l);
    }
}
void queryMax(int p)
{
    if (!p) return ;
    db d=getDist(tr[p].d[0],tr[p].d[1],qx,qy);
    if (qid!=p) updateMax(mx,d);
    db dl=1.0*INF,dr=1.0*INF;
    if (tr[p].l) dl=getDistMax(tr[p].l,qx,qy);
    if (tr[p].r) dr=getDistMax(tr[p].r,qx,qy);
    //下面的代码用了启发式搜索的思想，先找更容易使mn变小的那一侧子树
    if (dl>dr) {
        if (dl>mx) queryMax(tr[p].l);
        if (dr>mx) queryMax(tr[p].r);
    }
    else {
        if (dr>mx) queryMax(tr[p].r);
        if (dl>mx) queryMax(tr[p].l);
    }
}
int main()
{
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%lf%lf",&tr[i].d[0],&tr[i].d[1]);
    int root=build(1,n,0);
    ans0=1.0*INF; ans1=0.0;
    rep(i,1,n+1) {
        qx=tr[i].d[0]; qy=tr[i].d[1]; qid=i;
        mn=1.0*INF; mx=0.0;
        queryMin(root); queryMax(root);
        updateMin(ans0,mn); updateMax(ans1,mx);
    }
    printf("%.4f %.4f\n",ans0,ans1);
    return 0;
}


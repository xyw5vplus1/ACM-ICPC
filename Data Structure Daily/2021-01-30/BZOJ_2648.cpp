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
const int maxn=1e6+10;
const int INF=0x3f3f3f3f;
const db alpha=0.725;
int n,m,cmpd,root,op;
int cur=0,n0=0;
int qx,qy,mn;
struct node
{
    int l,r;
    int mx[2],mn[2];
    int d[2];
    int sum;
    int val,sz;
}tr[maxn];
int g[maxn],dim[maxn];
bool cmp(int a,int b)
{
    return tr[a].d[cmpd]<tr[b].d[cmpd]||(tr[a].d[cmpd]==tr[b].d[cmpd]&&tr[a].d[cmpd^1]<tr[b].d[cmpd^1]);
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
    tr[p].sum=tr[p].val; tr[p].sz=1;
    tr[p].mx[0]=tr[p].mn[0]=tr[p].d[0];
    tr[p].mx[1]=tr[p].mn[1]=tr[p].d[1];
    if (l) {
        updateMax(tr[p].mx[0],tr[l].mx[0]);
        updateMax(tr[p].mx[1],tr[l].mx[1]);
        updateMin(tr[p].mn[0],tr[l].mn[0]);
        updateMin(tr[p].mn[1],tr[l].mn[1]);
        tr[p].sum+=tr[l].sum;
        tr[p].sz+=tr[l].sz;
    }
    if (r) {
        updateMax(tr[p].mx[0],tr[r].mx[0]);
        updateMax(tr[p].mx[1],tr[r].mx[1]);
        updateMin(tr[p].mn[0],tr[r].mn[0]);
        updateMin(tr[p].mn[1],tr[r].mn[1]);
        tr[p].sum+=tr[r].sum;
        tr[p].sz+=tr[r].sz;
    }
}
int build(int l,int r,int d) //建K-D tree的过程，l,r为数组下标，d为当前划分的维度
{
    int mid=(l+r)>>1;
    cmpd=d;
    nth_element(g+l,g+mid,g+r+1,cmp); //能够按照第d维的大小对区间进行划分
    int p=g[mid]; dim[p]=d;
    tr[p].l=tr[p].r=0;
    if (l<mid) tr[p].l=build(l,mid-1,d^1);
    if (mid<r) tr[p].r=build(mid+1,r,d^1);
    pushup(p);
    return p;
}
void dfs(int p)
{
    if (!p) return ;
    if (tr[p].l) dfs(tr[p].l);
    g[++n0]=p;
    if (tr[p].r) dfs(tr[p].r);
}
void rebuild(int &p)
{
    n0=0;
    dfs(p);
    p=build(1,n0,0);
}
bool isBad(int x)
{
    return tr[x].sz*alpha<max(tr[tr[x].l].sz,tr[tr[x].r].sz);
}
void insertK_D(int &p,int x,int d)
{
    if (!p) {
        p=x;
        tr[p].mx[0]=tr[p].mn[0]=tr[p].d[0];
        tr[p].mx[1]=tr[p].mn[1]=tr[p].d[1];
        tr[p].sum=tr[p].val; tr[p].sz=1; dim[p]=d;
        return ;
    }
    cmpd=dim[p];
    if (tr[x].d[cmpd]<=tr[p].d[cmpd]) insertK_D(tr[p].l,x,d^1);
    else insertK_D(tr[p].r,x,d^1);
    pushup(p);
    if (isBad(p)) rebuild(p);
}
int getDistMin(int p,int qx,int qy)//统计某个点(qx,qy)到以p为根的矩形区域的最近距离
    //其中，如果查询点在矩形区域内部，则需要继续递归，当前返回值为0。
{
    int dist=0;
    if (qx<tr[p].mn[0]) dist+=abs(qx-tr[p].mn[0]);
    if (qx>tr[p].mx[0]) dist+=abs(qx-tr[p].mx[0]);
    if (qy<tr[p].mn[1]) dist+=abs(qy-tr[p].mn[1]);
    if (qy>tr[p].mx[1]) dist+=abs(qy-tr[p].mx[1]);
    return dist;
}
void queryMin(int p)
{
    if (!p) return ;
    int d=abs(qx-tr[p].d[0])+abs(qy-tr[p].d[1]);
    updateMin(mn,d);
    //这里的前提条件是不存在坐标相同的点，否则需要判断一下当前查询点是否是p点本身。
    int dl=INF,dr=INF;
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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
int main()
{
    n=read(); m=read();
    rep(i,1,n+1) {
        cur++; tr[cur].d[0]=read(); tr[cur].d[1]=read();
        insertK_D(root,cur,0);
    }
    while (m--) {
        op=read();
        if (op==1) {
            cur++; tr[cur].d[0]=read(); tr[cur].d[1]=read();
            insertK_D(root,cur,0);
        }
        else if (op==2) {
            qx=read(); qy=read();
            mn=INF;
            queryMin(root);
            printf("%d\n",mn);
        }
    }
    return 0;
}

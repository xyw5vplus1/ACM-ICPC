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
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
int xl,xr,yl,yr,cmpd,qnode;
int T,n,m,q,v,x,l,u;
int in[maxn],out[maxn],dim[maxn],ID[maxn];
struct edge
{
    int to,_next;
}G[maxn<<1];
int num=0,tim=0;
int head[maxn],dep[maxn];
void add(int u,int v)
{
    G[++num].to=v;
    G[num]._next=head[u];
    head[u]=num;
}
struct node
{
    int l,r;
    int mx[2],mn[2];
    int d[2];
    int id;
    int color,lazy;
}tr[maxn];
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
    dim[p]=d; tr[p].lazy=0;
    if (l<mid) tr[p].l=build(l,mid-1,d^1);
    if (mid<r) tr[p].r=build(mid+1,r,d^1);
    pushup(p);
    return p;
}
void pushdown(int p)
{
    if (tr[p].lazy) {
        int l=0,r=0;
        l=tr[p].l; r=tr[p].r;
        if (l) {
            tr[l].color=tr[p].lazy; tr[l].lazy=tr[p].lazy;
        }
        if (r) {
            tr[r].color=tr[p].lazy; tr[r].lazy=tr[p].lazy;
        }
        tr[p].lazy=0;
    }
}
void modify(int p,int c)
{
    if (!p||tr[p].mx[0]<xl||tr[p].mn[0]>xr||tr[p].mx[1]<yl||tr[p].mn[1]>yr) return ;
    if (tr[p].mn[0]>=xl&&tr[p].mx[0]<=xr&&tr[p].mn[1]>=yl&&tr[p].mx[1]<=yr) {
        tr[p].color=c; tr[p].lazy=c;
        return ;
    }
    pushdown(p);
    if (tr[p].d[0]>=xl&&tr[p].d[0]<=xr&&tr[p].d[1]>=yl&&tr[p].d[1]<=yr) {
        tr[p].color=c;
    }
    modify(tr[p].l,c); modify(tr[p].r,c);
}
int query(int p)
{
    cmpd=dim[p];
    if (p==qnode) {
        return tr[p].color;
    }
    pushdown(p);
    if (cmp(tr[qnode],tr[p])) return query(tr[p].l);
    else return query(tr[p].r);
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    ++tim; in[u]=tim;
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa) continue;
        dfs(v,u);
    }
    out[u]=tim;
}
void show(int p)
{
    pushdown(p);
    if (tr[p].l) show(tr[p].l);
    if (tr[p].r) show(tr[p].r);
}
void Init()
{
    num=0; tim=0;
    memset(head,0,sizeof(int)*(n+5));
    memset(dim,-1,sizeof(int)*(n+5));
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&n,&m,&q);
        Init();
        rep(i,2,n+1) {
            scanf("%d",&u);
            add(u,i); add(i,u);
        }
        dfs(1,0);
        rep(i,1,n+1){
            tr[i].d[0]=in[i]; tr[i].d[1]=dep[i]; tr[i].color=1; tr[i].l=tr[i].r=0;
            tr[i].id=i;
        }
        int root=build(1,n,0);
        rep(i,1,n+1) ID[tr[i].id]=i;
        int ans=0;
        rep(i,1,q+1) {
            scanf("%d%d%d",&x,&l,&v);
            if (v!=0) {
                xl=in[x]; xr=out[x]; yl=dep[x]; yr=dep[x]+l;
                modify(root,v);
            }
            else {
                qnode=ID[x];
                ans=(ans+1LL*i*query(root)%mod)%mod;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

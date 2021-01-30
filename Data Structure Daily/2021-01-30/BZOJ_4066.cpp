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
const db alpha=0.725;
int n,cmpd,root,op;
int cur=0,n0=0;
int xl,yl,xr,yr;
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
int query(int p)
{
    if (!p||tr[p].mx[0]<xl||tr[p].mn[0]>xr||tr[p].mx[1]<yl||tr[p].mn[1]>yr) return 0;
    if (tr[p].mn[0]>=xl&&tr[p].mx[0]<=xr&&tr[p].mn[1]>=yl&&tr[p].mx[1]<=yr) return tr[p].sum;
    int ans=0;
    if (tr[p].d[0]>=xl&&tr[p].d[0]<=xr&&tr[p].d[1]>=yl&&tr[p].d[1]<=yr) ans=tr[p].val;
    return query(tr[p].l)+query(tr[p].r)+ans;
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
    int lastans=0;
    n=read();
    while (scanf("%d",&op)!=EOF) {
        if (op==1) {
            cur++;
            tr[cur].d[0]=read(); tr[cur].d[1]=read(); tr[cur].val=read();
            tr[cur].d[0]^=lastans; tr[cur].d[1]^=lastans; tr[cur].val^=lastans;
            insertK_D(root,cur,0);
        }
        else if (op==2) {
            xl=read(); yl=read(); xr=read(); yr=read();
            xl^=lastans; yl^=lastans; xr^=lastans; yr^=lastans;
            lastans=query(root);
            printf("%d\n",lastans);
        }
        else break;
    }
    return 0;
}

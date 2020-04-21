#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef double db;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5;
int head[maxn+5],dfn[maxn+5],id[maxn+5],sz[maxn+5],a[maxn+5],e[maxn+5],root[maxn+5];
db ans[maxn+5];
int T,n,m,u,v;
struct edge
{
    int to,_next;
}G[2*maxn+5];
int num=0,cur=0,tot=0;
void add(int u,int v)
{
    G[++num].to=v;
    G[num]._next=head[u];
    head[u]=num;
}
void dfs(int u,int fa)
{
    sz[u]=1; dfn[u]=++cur; id[cur]=u;
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
struct SegmentTree
{
    int lc,rc;
    int cnt;
}b[maxn*40];
int build(int l,int r)
{
    int p=++tot;
    if (l==r) {
        b[p].cnt=0; return p;
    }
    int mid=(l+r)>>1;
    b[p].lc=build(l,mid);
    b[p].rc=build(mid+1,r);
    b[p].cnt=b[b[p].lc].cnt+b[b[p].rc].cnt;
    return p;
}
int update(int pre,int l,int r,int pos,int val)
{
    int cur=++tot;
    b[cur]=b[pre];
    if (l==r) {
        b[cur].cnt+=val; return cur;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) b[cur].lc=update(b[pre].lc,l,mid,pos,val);
    else b[cur].rc=update(b[pre].rc,mid+1,r,pos,val);
    b[cur].cnt=b[b[cur].lc].cnt+b[b[cur].rc].cnt;
    return cur;
}
int kth(int cur,int pre,int l,int r,int k)
{
    if (l==r) return l;
    int mid=(l+r)>>1;
    if (b[b[cur].lc].cnt-b[b[pre].lc].cnt>=k) return kth(b[cur].lc,b[pre].lc,l,mid,k);
    else return kth(b[cur].rc,b[pre].rc,mid+1,r,k-(b[b[cur].lc].cnt-b[b[pre].lc].cnt));
}
void Init()
{
    memset(head,0,sizeof(head));
    num=0; cur=0; tot=0;
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        Init();
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            e[i]=a[i];
        }
        sort(e+1,e+n+1);
        int q=unique(e+1,e+n+1)-(e+1);
        for (int i=0;i<n-1;i++) {
            scanf("%d%d",&u,&v);
            add(u,v); add(v,u);
        }
        dfs(1,0);
        //for (int i=1;i<=n;i++) printf("debug %d %d %d\n",i,dfn[i],dfn[i]+sz[i]-1);
        root[0]=build(1,q);
        for (int i=1;i<=n;i++) {
            int v=lower_bound(e+1,e+q+1,a[id[i]])-e;
            root[i]=update(root[i-1],1,q,v,1);
        }
        for (int u=1;u<=n;u++){
            int l=dfn[u],r=dfn[u]+sz[u]-1;
            int k=(r-l+1);
            if (k&1) {
                int k0=(k+1)/2;
                //printf("debug %d %d\n",u,k0);
                ans[u]=1.0*e[kth(root[r],root[l-1],1,q,k0)];
            }
            else {
                int k1=k/2,k2=k/2+1;
                ans[u]=(e[kth(root[r],root[l-1],1,q,k1)]+e[kth(root[r],root[l-1],1,q,k2)])/2.0;
            }
        }
        //for (int i=1;i<=n;i++) printf("debug %d %.2f\n",i,ans[i]);
        db res=0;
        for (int i=1;i<=m;i++) {
            scanf("%d",&u);
            //printf("debug %.2f\n",ans[u]);
            res=fmod(res*10+ans[u],1.0*mod);
        }
        printf("%.1f\n",res);
    }
    return 0;
}

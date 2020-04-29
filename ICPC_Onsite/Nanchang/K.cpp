#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
const int maxtot=3e6;
struct edge
{
    int to,_next;
}G[2*maxn+5];
int num=0;
int head[maxn+5],son[maxn+5],dep[maxn+5],sz[maxn+5];
int root[maxn+5];
int a[maxn+5];
int n,k,x;
ll ans=0;
int flag;
void add(int u,int v)
{
    G[++num].to=v;
    G[num]._next=head[u];
    head[u]=num;
}
void dfs(int u,int fa)
{
    sz[u]=1; dep[u]=dep[fa]+1;
    son[u]=-1;
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if (son[u]==-1||sz[son[u]]<sz[v]) son[u]=v;
    }
}
struct node
{
    int lc,rc;
    int cnt;
}b[maxtot+5];
int tot=0;
int build()
{
    int p=++tot;
    b[p].lc=b[p].rc=0;
    b[p].cnt=0;
    return p;
}
void pushup(int p)
{
    b[p].cnt=b[b[p].lc].cnt+b[b[p].rc].cnt;
}
void modify(int cur,int l,int r,int pos,int val)
{
    if (l==r) {
        b[cur].cnt+=val;
        return ;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) {
        if (!b[cur].lc) b[cur].lc=build();
        modify(b[cur].lc,l,mid,pos,val);
    }
    else {
        if (!b[cur].rc) b[cur].rc=build();
        modify(b[cur].rc,mid+1,r,pos,val);
    }
    pushup(cur);
}
int getLess(int cur,int l,int r,int val)
{
    if (cur==0) return 0;
    if (l==r) {
        if (l<=val) return b[cur].cnt;
        else return 0;
    }
    int mid=(l+r)>>1;
    if (val<=mid) return getLess(b[cur].lc,l,mid,val);
    else return b[b[cur].lc].cnt+getLess(b[cur].rc,mid+1,r,val);
}
void calc(int u,int fa,int lca)
{
    int need=2*a[lca]-a[u];
    if (need>=0&&need<=n) ans+=getLess(root[need],1,n,k+2*dep[lca]-dep[u]);
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa||v==flag) continue;
        calc(v,u,lca);
    }
}
void modify(int u,int fa,int val)
{
    modify(root[a[u]],1,n,dep[u],val);
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa||v==flag) continue;
        modify(v,u,val);
    }
}
void dfs(int u,int fa,bool keep)
{
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa||v==son[u]) continue;
        dfs(v,u,false);
    }
    if (son[u]!=-1) {
        dfs(son[u],u,true);
        flag=son[u];
    }
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa||v==flag) continue;
        calc(v,u,u); modify(v,u,1);
    }
    modify(root[a[u]],1,n,dep[u],1);
    flag=-1;
    if (!keep) {
        modify(u,fa,-1);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=2;i<=n;i++) {
        scanf("%d",&x);
        add(x,i); add(i,x);
    }
    dfs(1,0);
    for (int i=0;i<=n;i++) root[i]=build();
    flag=-1;
    dfs(1,0,false);
    printf("%lld\n",2*ans);
    return 0;
}

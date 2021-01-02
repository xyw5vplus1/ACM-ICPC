#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
int head[maxn],dep[maxn],in[maxn],out[maxn];
int n,q,op,t,val;
int num=0,tim=0;
int ex[maxn],ey[maxn];
struct node
{
    ll sum;
    ll lazy;
}b[maxn<<2];
void updatePoint(int p,int l,int r,ll v)
{
    b[p].sum+=(r-l+1)*1LL*v;
    b[p].lazy+=v;
}
void pushdown(int p,int l,int r)
{
    if (b[p].lazy!=0) {
        int mid=(l+r)>>1;
        updatePoint(lson(p),l,mid,b[p].lazy);
        updatePoint(rson(p),mid+1,r,b[p].lazy);
        b[p].lazy=0;
    }
}
void update(int p,int l,int r,int L,int R,ll v)
{
    if (L<=l&&r<=R) {
        updatePoint(p,l,r,v);
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(p,l,r);
    if (L<=mid) update(lson(p),l,mid,L,R,v);
    if (R>mid) update(rson(p),mid+1,r,L,R,v);
}
struct edge
{
    int to,_next;
}G[maxn<<1];
void add(int u,int v)
{
    G[++num].to=v;
    G[num]._next=head[u];
    head[u]=num;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    in[u]=++tim;
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa) continue;
        dfs(v,u);
    }
    out[u]=tim;
}
ll dfs(int p,int l,int r,int pos)
{
    if (l==r) {
        return b[p].sum;
    }
    int mid=(l+r)>>1;
    pushdown(p,l,r);
    if (pos<=mid) return dfs(lson(p),l,mid,pos);
    else return dfs(rson(p),mid+1,r,pos);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n-1;i++) {
        scanf("%d%d",&ex[i],&ey[i]);
        add(ex[i],ey[i]); add(ey[i],ex[i]);
    }
    dfs(1,0);
    ll totVal=0;
    scanf("%d",&q);
    while (q--) {
        scanf("%d%d%d",&op,&t,&val);
        if (op==1) {
            if (dep[ex[t]]>dep[ey[t]]) {
                update(1,1,n,in[ex[t]],out[ex[t]],val);
            }
            else {
                update(1,1,n,in[ey[t]],out[ey[t]],-val);
                totVal+=val;
            }
        }
        else {
            if (dep[ey[t]]>dep[ex[t]]) {
                update(1,1,n,in[ey[t]],out[ey[t]],val);
            }
            else {
                update(1,1,n,in[ex[t]],out[ex[t]],-val);
                totVal+=val;
            }
        }
        //for (int i=1;i<=n;i++) printf("%lld\n",dfs(1,1,n,in[i],in[i])+totVal);
    }
    for (int i=1;i<=n;i++) printf("%lld\n",dfs(1,1,n,in[i])+totVal);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int maxn=1e5+10;
int c[maxn];
ll ans=0;
int n,L,W;
int fa,w;
int tot,mn,root;
bool vis[maxn];
vector<pair<int,int> > vec;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int v)
{
    while (x<=L+2) {
        c[x]+=v;
        x+=lowbit(x);
    }
}
int getSum(int x)
{
    if (x<=0) return 0;
    int ans=0;
    while (x) {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
struct edge
{
    int to,_next,val;
}G[2*maxn];
int num=0;
int head[maxn];
int sz[maxn];
int dep[maxn],dist[maxn];
void add(int u,int v,int w)
{
    G[++num].to=v;
    G[num]._next=head[u];
    G[num].val=w;
    head[u]=num;
}
void findrt(int u,int fa)
{
    int num=0;
    sz[u]=1;
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa||vis[v]) continue;
        findrt(v,u);
        sz[u]+=sz[v];
        if (num<sz[v]) num=sz[v];
    }
    if (tot-sz[u]>num) num=tot-sz[u];
    if (num<mn) {
        mn=num; root=u;
    }
}
void getVal(int u,int fa,int w)
{
    dep[u]=dep[fa]+1;
    dist[u]=dist[fa]+w;
    vec.push_back(make_pair(dist[u],dep[u]));
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (vis[v]||v==fa) continue;
        getVal(v,u,G[i].val);
    }
}
void addToAns(int op)
{
    sort(vec.begin(),vec.end());
    int l=0,r=vec.size()-1;
    //printf("A\n");
    for (int i=0;i<vec.size();i++) add(vec[i].second,1);
    //printf("B\n");
    add(vec[0].second,-1);
    while (l<r) {
        //printf("L,R %d %d\n",l,r);
        while (l<r&&vec[l].first+vec[r].first>W) {
            add(vec[r].second,-1);
            r--;
        }
        if (l==r) return ;
        ans+=op*getSum(L+2-vec[l].second);
        l++; add(vec[l].second,-1);
    }
    assert(l==r);
}
void calc(int u)
{
    vec.clear();
    dep[u]=1; dist[u]=0; vec.push_back(make_pair(0,1));
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (vis[v]) continue;
        getVal(v,u,G[i].val);
    }
    addToAns(1);
    //printf("lalala\n");
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (vis[v]) continue;
        vec.clear();
        getVal(v,u,G[i].val);
        addToAns(-1);
    }
}
void divide(int u)
{
    //printf("debug %d\n",u);
    calc(u);
    //printf("after %d\n",u);
    vis[u]=true;
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (vis[v]) continue;
        tot=sz[v]; mn=INF; findrt(v,0); divide(root);
    }
}
int main()
{
    scanf("%d%d%d",&n,&L,&W);
    for (int i=2;i<=n;i++) {
        scanf("%d%d",&fa,&w);
        add(i,fa,w); add(fa,i,w);
    }
    tot=n; mn=INF; findrt(1,0); divide(root);
    printf("%I64d\n",ans);
    return 0;
}

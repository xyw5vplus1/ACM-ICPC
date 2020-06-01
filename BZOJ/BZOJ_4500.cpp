#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2000+10;
const int maxm=5000+10;
const int INF=0x3f3f3f3f;
struct edge
{
    int to,_next,val;
}G[maxm];
int head[maxn],num=0;
bool vis[maxn];
int in[maxn],dist[maxn];
int T,n,m,k,x,y,w;
queue<int> q;
void add(int u,int v,int w)
{
    G[++num].to=v;
    G[num]._next=head[u];
    G[num].val=w;
    head[u]=num;
}
void dfs(int u)
{
    vis[u]=true;
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (!vis[v]) dfs(v);
    }
}
bool SPFA(int root,int cnt)
{
    memset(vis,false,sizeof(vis));
    memset(in,0,sizeof(in));
    rep(i,0,cnt+1) dist[i]=INF;
    dist[root]=0; in[root]=1; q.push(root);
    while (q.size()) {
        int u=q.front(); q.pop(); vis[u]=false;
        for (int i=head[u];i;i=G[i]._next) {
            int v=G[i].to;
            if (dist[v]>dist[u]+G[i].val) {
                dist[v]=dist[u]+G[i].val;
                if (!vis[v]) {
                    vis[v]=true; in[v]++; q.push(v);
                    if (in[v]>cnt) return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        memset(head,0,sizeof(head)); num=0;
        scanf("%d%d%d",&n,&m,&k);
        rep(i,0,k) {
            scanf("%d%d%d",&x,&y,&w);
            add(x,n+y,-w); add(n+y,x,w);
        }
        memset(vis,false,sizeof(vis));
        rep(i,1,n+1)
        if (!vis[i]) {
            dfs(i); add(0,i,0);
        }
        if (SPFA(0,n+m+1)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

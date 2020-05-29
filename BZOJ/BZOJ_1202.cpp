#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
const int maxn=100+10;
const int INF=0x3f3f3f3f;
const int maxm=2000+10;
queue<int> q;
struct edge
{
    int to,_next,val;
}G[maxm];
int head[maxn],num=0;
bool vis[maxn];
int dist[maxn],in[maxn];
int T,n,m,x,y,w;
void add(int u,int v,int w)
{
    G[++num].to=v;
    G[num].val=w;
    G[num]._next=head[u];
    head[u]=num;
}
bool SPFA(int root)
{
    memset(vis,false,sizeof(vis));
    memset(in,0,sizeof(in));
    rep(i,1,n+1) dist[i]=INF;
    dist[root]=0;
    vis[root]=true; q.push(root); in[root]=1;
    int v;
    while (q.size()) {
        int u=q.front(); q.pop(); vis[u]=false;
        for (int i=head[u];i;i=G[i]._next) {
            v=G[i].to;
            if (dist[u]+G[i].val<dist[v]) {
                dist[v]=dist[u]+G[i].val;
                if (!vis[v]) {
                    q.push(v); vis[v]=true;
                    in[v]++;
                    if (in[v]>n) return false;
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
        scanf("%d%d",&n,&m);
        memset(head,0,sizeof(head)); num=0;
        rep(i,0,m) {
            scanf("%d%d%d",&x,&y,&w);
            add(x-1,y,w); add(y,x-1,-w);
        }
        if (SPFA(0)) printf("true\n");
        else printf("false\n");
    }
    return 0;
}

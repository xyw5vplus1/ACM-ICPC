#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
const int maxn=2e5+10;
const int maxm=4e6+10;
const int INF=0x3f3f3f3f;
int n,m,s,t,x,y,w,k;
struct edge
{
    int to,_next,val;
}G[maxm];
int num=0;
int head[maxn];
int dist[maxn];
bool vis[maxn];
void add(int u,int v,int w)
{
    G[++num].to=v;
    G[num].val=w;
    G[num]._next=head[u];
    head[u]=num;
}
priority_queue<pair<int,int> > q;
void dijkstra(int root)
{
    rep(i,1,n*(k+1)+1) dist[i]=INF;
    memset(vis,false,sizeof(vis));
    dist[root]=0;
    q.push(make_pair(0,root));
    while (q.size()) {
        pair<int,int> e=q.top(); q.pop();
        int u=e.second;
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=head[u];i;i=G[i]._next) {
            int v=G[i].to;
            if (dist[u]+G[i].val<dist[v]) {
                dist[v]=dist[u]+G[i].val;
                q.push(make_pair(-dist[v],v));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&s,&t); s++; t++;
    rep(i,1,m+1) {
        scanf("%d%d%d",&x,&y,&w); x++; y++;
        rep(j,0,k+1) {
            add(j*n+x,j*n+y,w); add(j*n+y,j*n+x,w);
            if (j<k) {
                add(j*n+x,(j+1)*n+y,0); add(j*n+y,(j+1)*n+x,0);
            }
        }
    }
    dijkstra(s);
    int ans=INF;
    rep(i,0,k+1) ans=min(ans,dist[i*n+t]);
    printf("%d\n",ans);
    return 0;
}

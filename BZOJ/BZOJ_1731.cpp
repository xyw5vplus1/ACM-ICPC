#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int INF=0x3f3f3f3f;
const int maxm=2e4+10;
const int maxn=1000+10;
int head[maxn],num=0;
int n,n0,n1,x,y,w;
int dist[maxn],in[maxn];
bool vis[maxn];
struct edge
{
    int to,_next,val;
}G[maxm];
void add(int u,int v,int w)
{
    G[++num].to=v;
    G[num]._next=head[u];
    G[num].val=w;
    head[u]=num;
}
queue<int> q;
bool SPFA(int root)
{
    memset(vis,false,sizeof(vis));
    rep(i,1,n+1) dist[i]=INF;
    memset(in,0,sizeof(in));
    dist[root]=0;
    q.push(root); vis[root]=true; in[root]=1;
    while (q.size()) {
        int u=q.front(); q.pop(); vis[u]=false;
        for (int i=head[u];i;i=G[i]._next) {
            int v=G[i].to;
            if (G[i].val+dist[u]<dist[v]) {
                dist[v]=dist[u]+G[i].val;
                if (!vis[v]) {
                    q.push(v); vis[v]=true; in[v]++;
                    if (in[v]>n) return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d%d%d",&n,&n0,&n1);
    rep(i,0,n0) {
        scanf("%d%d%d",&x,&y,&w);
        if (x>y) swap(x,y);
        add(x,y,w);
    }
    rep(i,0,n1) {
        scanf("%d%d%d",&x,&y,&w);
        if (x>y) swap(x,y);
        add(y,x,-w);
    }
    if (!SPFA(1)) printf("-1\n");
    else if (dist[n]==INF) printf("-2\n");
    else printf("%d\n",dist[n]);
    return 0;
}

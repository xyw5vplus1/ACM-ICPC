#include<cstdio>
#include<cstring>
#include<queue>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
const int maxn=5e4+10;
const int INF=0x3f3f3f3f;
struct edge
{
    int to,_next,val;
}G[4*maxn];
int head[maxn],num=0;
int dist[maxn];
bool vis[maxn];
int n,x,y;
void add(int u,int v,int w)
{
    G[++num].to=v;
    G[num].val=w;
    G[num]._next=head[u];
    head[u]=num;
}
queue<int> q;
void SPFA(int root)
{
    memset(vis,false,sizeof(vis));
    rep(i,0,maxn) dist[i]=-INF;
    while (q.size()) q.pop();
    dist[root]=0;
    q.push(root); vis[root]=true;
    int v;
    while (q.size()) {
        int u=q.front(); q.pop();
        vis[u]=false;
        for (int i=head[u];i;i=G[i]._next) {
            v=G[i].to;
            if (G[i].val+dist[u]>dist[v]) {
                dist[v]=dist[u]+G[i].val;
                if (!vis[v]) {
                    q.push(v); vis[v]=true;
                }
            }
        }
    }
}
int main()
{
    while (scanf("%d",&n)!=EOF) {
        memset(head,0,sizeof(head));
        num=0;
        rep(i,0,n) {
            scanf("%d%d",&x,&y);
            if (x>y) swap(x,y);
            x++; y++; add(x-1,y,2);
        }
        rep(i,0,maxn-1) {
            add(i+1,i,-1); add(i,i+1,0);
        }
        SPFA(0);
        printf("%d\n",dist[maxn-1]);
    }
    return 0;
}

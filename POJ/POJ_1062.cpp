#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=b;i>a;i--)
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=200;
const int maxm=1e5;
struct edge
{
    int to,_next;
    int val;
}G[maxm];
int head[maxn],num=0;
bool vis[maxn];
int dist[maxn],level[maxn],e[maxn];
int n,m,k,x,y,w;
void add(int u,int v,int w)
{
    G[++num].to=v;
    G[num].val=w;
    G[num]._next=head[u];
    head[u]=num;
}
void dijkstra(int L,int R)
{
    memset(vis,false,sizeof(vis));
    dist[1]=0;
    rep(i,2,n+2) dist[i]=INF;
    rep(i,0,n+1) {
        int mn=INF,mnx=-1;
        rep(j,1,n+2) {
            if (j==n+1||(level[j]>=L&&level[j]<=R)) {
                if (!vis[j]&&mn>dist[j]) {
                    mn=dist[j]; mnx=j;
                }
            }
        }
        if (mn==INF) break;
        vis[mnx]=true;
        for (int j=head[mnx];j;j=G[j]._next) {
            int v=G[j].to;
            if (v==n+1||(level[v]>=L&&level[v]<=R)) {
                if (dist[mnx]+G[j].val<dist[v]) dist[v]=dist[mnx]+G[j].val;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&m,&n);
    int t=n+1;
    rep(i,1,n+1) {
        scanf("%d%d%d",&x,&level[i],&k);
        add(i,t,x);
        rep(j,0,k) {
            scanf("%d%d",&y,&w);
            add(i,y,w);
        }
    }
    rep(i,1,n+1) e[i]=level[i];
    sort(e+1,e+n+1);
    int n0=unique(e+1,e+n+1)-(e+1);
    int ans=INF;
    rep(i,1,n0+1){
        dijkstra(e[i],e[i]+m);
        if (dist[n+1]<ans) ans=dist[n+1];
    }
    printf("%d\n",ans);
    return 0;
}

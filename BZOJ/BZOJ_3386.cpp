/**************************************************************
    Problem: 3386
    User: xyw5vplus1
    Language: C++
    Result: Accepted
    Time:88 ms
    Memory:4812 kb
****************************************************************/
 
#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e3+10;
int dist[maxn];
bool vis[maxn];
int a[maxn][maxn];
int m,n,u,v,w;
void dijkstra(int root)
{
    rep(i,1,n+1) dist[i]=INF;
    memset(vis,false,sizeof(vis));
    dist[root]=0;
    rep(l,1,n+1) {
        int mn=INF,k=-1;
        rep(i,1,n+1)
        if (!vis[i]&&mn>dist[i]) {
            mn=dist[i]; k=i;
        }
        if (k==-1) break;
        vis[k]=true;
        rep(i,1,n+1)
        if (dist[k]+a[k][i]<dist[i]) dist[i]=dist[k]+a[k][i];
    }
}
int main()
{
    scanf("%d%d",&m,&n);
    rep(i,1,n+1)
        rep(j,1,n+1)
        if (i!=j) a[i][j]=INF;
    rep(i,1,m+1) {
        scanf("%d%d%d",&u,&v,&w);
        a[u][v]=min(a[u][v],w);
        a[v][u]=a[u][v];
    }
    dijkstra(n);
    printf("%d\n",dist[1]);
    return 0;
}

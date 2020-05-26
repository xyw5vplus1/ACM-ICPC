#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef double db;
const int maxn=200+10;
const db INF=1e9;
struct node
{
    int x,y;
}a[maxn];
db g[maxn][maxn];
db dist[maxn];
int cnt;
bool vis[maxn];
int x,y;
db dis(node a,node b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}
void dijkstra(int root)
{
    rep(i,1,cnt+1) dist[i]=INF;
    memset(vis,false,sizeof(vis));
    dist[root]=0;
    rep(l,0,cnt) {
        db mn=INF;
        int k=-1;
        rep(i,1,cnt+1)
        if (!vis[i]&&mn>dist[i]) {
            mn=dist[i]; k=i;
        }
        if (k==-1) break;
        vis[k]=true;
        rep(i,1,cnt+1)
        if (dist[k]+g[k][i]<dist[i]) dist[i]=dist[k]+g[k][i];
    }
}
int main()
{
    rep(i,1,maxn)
        rep(j,1,maxn)
        if (i!=j) g[i][j]=INF;
    scanf("%d%d",&a[1].x,&a[1].y);
    scanf("%d%d",&a[2].x,&a[2].y);
    cnt=2;
    int lastx=-1;
    while (scanf("%d%d",&x,&y)!=EOF) {
        if (x!=-1&&y!=-1) {
            ++cnt; a[cnt].x=x; a[cnt].y=y;
        }
        if (x!=-1&&lastx!=-1) {
            g[cnt-1][cnt]=min(g[cnt-1][cnt],dis(a[cnt-1],a[cnt])*3.0/2000.0);
            g[cnt][cnt-1]=g[cnt-1][cnt];
        }
        lastx=x;
    }
    rep(i,1,cnt+1)
        rep(j,i+1,cnt+1) {
            g[i][j]=min(g[i][j],dis(a[i],a[j])*3.0/500.0);
            g[j][i]=g[i][j];
        }
    dijkstra(1);
    printf("%.0f\n",dist[2]);
    return 0;
}

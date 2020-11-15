#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
int T;
priority_queue<pair<int,int> > q;
struct edge
{
    int to,_next,val;
}G[maxn*30];
int head[maxn];
int dist[27][maxn];
bool vis[maxn];
int u,v,n,q0;
char s[30];
int num=0;
void add(int u,int v,int w)
{
    G[++num].to=v;
    G[num]._next=head[u];
    G[num].val=w;
    head[u]=num;
}
void dijkstra(int root)
{
    int id=n+root;
    for (int i=1;i<=n+26;i++) dist[root][i]=INF;
    memset(vis,false,sizeof(vis));
    dist[root][id]=0;
    q.push(make_pair(-dist[root][id],id));
    while (q.size()) {
        pair<int,int> e=q.top(); q.pop();
        int u=e.second;
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=head[u];i;i=G[i]._next) {
            int v=G[i].to;
            if (vis[v]) continue;
            if (dist[root][u]+G[i].val<dist[root][v]) {
                dist[root][v]=dist[root][u]+G[i].val;
                q.push(make_pair(-dist[root][v],v));
            }
        }
    }
}
void Init()
{
    memset(head,0,sizeof(head));
    num=0;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        Init();
        scanf("%d%d",&n,&q0);
        for (int i=1;i<=n;i++) {
            scanf("%s",s);
            int len=strlen(s);
            for (int j=0;j<len;j++) {
                add(i,n+s[j]-'A'+1,1);
                add(n+s[j]-'A'+1,i,1);
            }
        }
        //printf("lalala\n");
        for (int i=1;i<=26;i++) dijkstra(i);
        printf("Case #%d:",kase);
        while (q0--) {
            scanf("%d%d",&u,&v);
            int tem=INF;
            for (int j=1;j<=26;j++)
                if (dist[j][u]+dist[j][v]<=tem) tem=dist[j][u]+dist[j][v];
            if (tem!=INF) printf(" %d",tem/2+1);
            else printf(" -1");
        }
        printf("\n");
    }
    return 0;
}
/*
2
5 2
LIZZIE KEVIN BOHDAN LALIT RUOYU
1 2
1 3
2 2
KICK START
1 2
1 2
*/

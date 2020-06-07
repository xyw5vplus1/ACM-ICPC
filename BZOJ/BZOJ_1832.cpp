#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
const int maxn=5e5+10;
struct edge
{
    int to,_next;
}G[2*maxn];
int num=0;
int head[maxn];
int lg[maxn];
int dep[maxn],father[maxn][20];
int n,q,x,y,w;
void add(int u,int v)
{
    G[++num].to=v;
    G[num]._next=head[u];
    head[u]=num;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    father[u][0]=fa;
    for (int i=1;(1<<i)<=dep[u];i++) father[u][i]=father[father[u][i-1]][i-1];
    int v;
    for (int i=head[u];i;i=G[i]._next) {
        v=G[i].to;
        if (v==fa) continue;
        dfs(v,u);
    }
}
int lca(int x,int y)
{
    if (dep[x]<dep[y]) swap(x,y);
    while (dep[x]>dep[y]) x=father[x][lg[dep[x]-dep[y]]];
    if (x==y) return x;
    per(k,lg[dep[x]],-1)
    if (father[x][k]!=father[y][k]) {
        x=father[x][k]; y=father[y][k];
    }
    return father[x][0];
}
int dist(int x,int y)
{
    int t=lca(x,y);
    return dep[x]+dep[y]-2*dep[t];
}
int main()
{
    lg[0]=-1;
    rep(i,1,maxn)
        if (i&(i-1)) lg[i]=lg[i-1];
        else lg[i]=lg[i-1]+1;
    scanf("%d%d",&n,&q);
    rep(i,1,n) {
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    dfs(1,0);
    int ans1,ans2;
    rep(i,0,q) {
        scanf("%d%d%d",&x,&y,&w);
        int t=lca(x,y);
        int p=lca(w,t);
        if (p==t) {
            int t1=lca(x,w),t2=lca(y,w);
            if (dep[t1]>=dep[t2]) ans1=t1;
            else ans1=t2;
            ans2=dist(x,ans1)+dist(y,ans1)+dist(w,ans1);
        }
        else {
            ans1=t;
            ans2=dist(x,ans1)+dist(y,ans1)+dist(w,ans1);
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
int sz[maxn],dep[maxn];
int n,u,v;
int head[maxn];
int num=0,mn,tot,root;
bool vis[maxn];
struct edge
{
    int to,_next;
}G[maxn<<1];
void add(int u,int v)
{
    G[++num].to=v;
    G[num]._next=head[u];
    head[u]=num;
}
void findrt(int u,int fa)
{
    int num=0;
    sz[u]=1;
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa||vis[v]) continue;
        findrt(v,u);
        sz[u]+=sz[v];
        if (num<sz[v]) num=sz[v];
    }
    if (tot-sz[u]>num) num=tot-sz[u];
    if (num<mn) {
        mn=num; root=u;
    }
}
void divide(int u)
{
    vis[u]=true;
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (vis[v]) continue;
        tot=sz[v]; mn=INF; findrt(v,0); dep[root]=dep[u]+1;
        divide(root);
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n-1;i++) {
        scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    tot=n; mn=INF; findrt(1,0); dep[root]=1;
    divide(root);
    for (int i=1;i<=n;i++) printf("%c ",'A'+dep[i]-1);
    return 0;
}

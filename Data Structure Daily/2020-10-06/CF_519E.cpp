/*
题意：
给定n个点的一棵树，无边权，q次询问，每次询问以(x,y)的形式给出，询问树上到x和y的距离相等的点的个数。
思路：
树上距离，一般必然会想到LCA。
首先手玩几个样例可以看出（当然也可以脑补证明）如果x和y之间距离为奇数必无解。
距离为偶数的情况下，分类讨论，判断x和y的树上中点是否是x和y的lca。
如果不是lca，那么我们不妨设x的深度较大，我们记x和y的树上中点为p，那么对落在以p为根的子树内，但是没有落在p的包含x的儿子节点为根的子树内的点均满足题意。
如果是lca，那么所有落在p的子树内，但没有落在以（p的包含x的儿子节点）和（p的包含y的儿子节点）为根的子树内的点均满足题意。
因此整道题，只需要快速在线求出lca即可，剩下的部分只需要维护子树大小计算，以及写一个在树上快速找某一级祖先的跳转函数即可。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int father[maxn][20];
int num=0;
int head[maxn];
int dep[maxn],sz[maxn];
int lg[maxn];
int n,q,x,y;
struct edge
{
    int to,_next;
}G[2*maxn];
void add(int u,int v)
{
    G[++num].to=v;
    G[num]._next=head[u];
    head[u]=num;
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    sz[u]=1;
    father[u][0]=fa;
    for (int i=1;(1<<i)<=dep[u];i++)
        father[u][i]=father[father[u][i-1]][i-1];
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        if (v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int lca(int x,int y)
{
    if (dep[x]<dep[y]) swap(x,y);
    while (dep[x]>dep[y]) x=father[x][lg[dep[x]-dep[y]]];
    if (x==y) return x;
    for (int k=lg[dep[x]];k>=0;k--)
    if (father[x][k]!=father[y][k]) {
        x=father[x][k]; y=father[y][k];
    }
    return father[x][0];
}
int distOnTree(int x,int y)
{
    int t=lca(x,y);
    return dep[x]+dep[y]-2*dep[t];
}
void Init()
{
    lg[0]=-1;
    for (int i=1;i<maxn;i++)
        if (i&(i-1)) lg[i]=lg[i-1];
        else lg[i]=lg[i-1]+1;
    memset(head,0,sizeof(head));
    num=0;
}
int getFather(int x,int k)
{
    if (k==0) return x;
    int t=lg[k];
    return getFather(father[x][t],k-(1<<t));
}
int main()
{
    Init();
    scanf("%d",&n);
    for (int i=0;i<n-1;i++) {
        scanf("%d%d",&x,&y);
        add(x,y); add(y,x);
    }
    dfs(1,0);
    scanf("%d",&q);
    while (q--) {
        scanf("%d%d",&x,&y);
        if (dep[x]<dep[y]) swap(x,y);
        int t=distOnTree(x,y);
        if (t&1) printf("0\n");
        else if (t==0) printf("%d\n",n);
        else {
            int p=getFather(x,t/2);
            if (p==lca(x,y)) {
                printf("%d\n",sz[p]-sz[getFather(x,t/2-1)]-sz[getFather(y,t/2-1)]+n-sz[p]);
            }
            else {
                printf("%d\n",sz[p]-sz[getFather(x,t/2-1)]);
            }
        }
    }
    return 0;
}

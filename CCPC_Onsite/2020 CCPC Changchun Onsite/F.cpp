#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int maxm=11e5+10;
int head[maxn];
int cnt[maxm][18][2],sz[maxn],son[maxn],a[maxn],col[maxn][18];
bool vis[maxn];
int num=0;
int n,u,v;
ll tot=0,ans=0;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
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
void dfs1(int u,int fa)
{
    sz[u]=1;
    son[u]=-1;
    int v;
    for (int i=head[u];i;i=G[i]._next) {
        v=G[i].to;
        if (v==fa) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if (son[u]==-1||sz[v]>sz[son[u]]) son[u]=v;
    }
}
void calc(int u,int fa,int up)
{
    for (int l=0;l<=17;l++)
        ans+=1LL*cnt[up^a[u]][l][col[u][l]^1]*(1<<l);
    int v;
    for (int i=head[u];i;i=G[i]._next) {
        v=G[i].to;
        if (v==fa||vis[v]) continue;
        calc(v,u,up);
    }
}
void update(int u,int fa,int val)
{
    for (int l=0;l<=17;l++)
        cnt[a[u]][l][col[u][l]]+=val;
    int v;
    for (int i=head[u];i;i=G[i]._next) {
        v=G[i].to;
        if (v==fa||vis[v]) continue;
        update(v,u,val);
    }
}
void dfs2(int u,int fa,bool keep)
{
    int v;
    for (int i=head[u];i;i=G[i]._next) {
        v=G[i].to;
        if (v==fa||v==son[u]) continue;
        dfs2(v,u,0);
    }
    if (son[u]!=-1) {
        dfs2(son[u],u,1);
        vis[son[u]]=true;
    }
    for (int l=0;l<=17;l++)
        cnt[a[u]][l][col[u][l]]++;
    for (int i=head[u];i;i=G[i]._next) {
        v=G[i].to;
        if (v==fa||vis[v]) continue;
        calc(v,u,a[u]);
        update(v,u,1);
    }
    if (son[u]!=-1) vis[son[u]]=false;
    if (!keep) {
        update(u,fa,-1);
    }
    //printf("After %d %lld\n",u,ans);
}
mt19937 myrand(time(0));
int _rand(int x)
{
    int t=myrand();
    return (t%x+x)%x;
}
int main()
{
    //scanf("%d",&n);
    //for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    /*for (int i=1;i<n;i++) {
        scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }*/
    //freopen("output.txt","r",stdin);
    /*n=100000;
    printf("%d\n",n);
    for (int i=1;i<=n;i++) {
        a[i]=_rand(100000)+1;
        printf("%d ",a[i]);
    }
    printf("\n");
    for (int i=2;i<=n;i++) {
        int fa=rand()%(i-1)+1;
        add(i,fa); add(fa,i);
        printf("%d %d\n",i,fa);
    }*/
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<n;i++) {
        u=read(); v=read();
        add(u,v); add(v,u);
    }
    dfs1(1,0);
    for (int l=0;l<=17;l++) {
        for (int i=1;i<=n;i++)
            if (i&(1<<l)) col[i][l]=1;
            else col[i][l]=0;
    }
    dfs2(1,0,0);
    printf("%lld\n",ans);
    //printf("Time used =%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

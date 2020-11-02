#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
vector<int> G[maxn];
bool vis[maxn];
int deg[maxn];
int cnt,sum;
int T,n,m,u,v;
void dfs(int u)
{
    vis[u]=true; cnt++; sum+=deg[u];
    for (int i=0;i<(int)G[u].size();i++) {
        int v=G[u][i];
        if (!vis[v]) {
            dfs(v);
        }
    }
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) G[i].clear(),deg[i]=0;
        for (int i=1;i<=m;i++) {
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
            deg[u]++; deg[v]++;
        }
        for (int i=1;i<=n;i++) vis[i]=false;
        int ans=0;
        for (int i=1;i<=n;i++)
        if (!vis[i]) {
            cnt=0; sum=0; dfs(i);
            sum/=2;
            if (sum>=cnt) ans+=sum-cnt;
        }
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}

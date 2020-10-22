#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int INF=1e9;
typedef long long ll;
struct node
{
    int x,y,r,c;
}a[maxn];
bool vis[maxn];
int cur_cc;
int n;
vector<int> G[maxn],G2[maxn],s;
int cc[maxn],in[maxn],pval[maxn];
int mn;
bool contain(int p,int q)
{
    if (1LL*(a[p].x-a[q].x)*(a[p].x-a[q].x)+1LL*(a[p].y-a[q].y)*(a[p].y-a[q].y)<=1LL*a[p].r*a[p].r) return true;
    return false;
}
void dfs1(int u)
{
    vis[u]=true;
    for (int i=0;i<(int)G[u].size();i++) {
        int v=G[u][i];
        if (!vis[v]) dfs1(v);
    }
    s.push_back(u);
}
void dfs2(int u)
{
    cc[u]=cur_cc; mn=min(mn,a[u].c);
    for (int i=0;i<G2[u].size();i++) {
        int v=G2[u][i];
        if (!cc[v]) dfs2(v);
    }
}
void find_scc()
{
    cur_cc=0; s.clear();
    memset(vis,false,sizeof(vis));
    memset(cc,0,sizeof(cc));
    for (int i=1;i<=n;i++)
        if (!vis[i]) dfs1(i);
    for (int i=n-1;i>=0;i--) {
        if (!cc[s[i]]) {
            mn=INF; cur_cc++; dfs2(s[i]); pval[cur_cc]=mn;
        }
    }
}
int T;
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            G[i].clear(); G2[i].clear();
        }
        for (int i=1;i<=n;i++) scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].r,&a[i].c);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
        if (i!=j) {
            if (contain(i,j)) {
                G[i].push_back(j);
                G2[j].push_back(i);
            }
        }
        find_scc();
        for (int i=1;i<=cur_cc;i++) in[i]=0;
        for (int i=1;i<=n;i++)
            for (int j=0;j<G[i].size();j++)
            if (cc[i]!=cc[G[i][j]]) in[cc[G[i][j]]]++;
        ll sum=0;
        for (int i=1;i<=cur_cc;i++) {
            if (in[i]==0) sum+=pval[i];
        }
        printf("Case #%d: %lld\n",kase,sum);
    }
    return 0;
}


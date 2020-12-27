#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=3e5+10;
int n,m;
int ex[maxn],ey[maxn];
int x,p;
int in[maxn];
int head[maxn];
int num=0;
int belong[maxn];
int fa[maxn];
bool vis[maxn];
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
vector<int> vec[maxn];
queue<int> q;
vector<int> ans;
bool topu()
{
    for (int i=1;i<=n;i++) in[i]=0;
    for (int i=1;i<=n;i++)
    for (int j=head[i];j;j=G[j]._next) {
        int v=G[j].to;
        in[v]++;
    }
    for (int i=1;i<=n;i++)
        if (!in[i]) q.push(i);
    int cnt=0;
    while (q.size()) {
        int u=q.front(); q.pop();
        cnt++;
        for (int i=head[u];i;i=G[i]._next) {
            int v=G[i].to;
            in[v]--;
            if (in[v]==0) q.push(v);
        }
    }
    if (cnt<n) return false;
    return true;
}
bool topu_2()
{
    for (int i=1;i<=p;i++) in[i]=0;
    for (int i=1;i<=p;i++)
    for (int j=head[i];j;j=G[j]._next) {
        int v=G[j].to;
        in[v]++;
    }
    for (int i=1;i<=p;i++)
        if (!in[i]) q.push(i);
    int cnt=0;
    while (q.size()) {
        int u=q.front(); q.pop();
        ans.push_back(u);
        cnt++;
        for (int i=head[u];i;i=G[i]._next) {
            int v=G[i].to;
            in[v]--;
            if (in[v]==0) q.push(v);
        }
    }
    if (cnt<p) return false;
    return true;
}
void clearGraph()
{
    for (int i=1;i<=n;i++) head[i]=0;
    num=0;
}
void dfs(int u)
{
    belong[u]=p; vis[u]=true;
    vec[p].pb(u);
    for (int i=head[u];i;i=G[i]._next) {
        int v=G[i].to;
        dfs(v);
    }

}
map<pair<int,int>,bool> mp;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        if (x) add(x,i);
        fa[i]=x;
    }
    for (int i=1;i<=m;i++) {
        scanf("%d%d",&ex[i],&ey[i]);
        add(ex[i],ey[i]);
    }
    if (!topu()) printf("0\n");
    else {
        clearGraph();
        for (int i=1;i<=n;i++) in[i]=0;
        for (int i=1;i<=n;i++) {
            add(ex[i],ey[i]); in[ey[i]]++;
        }
        for (int i=1;i<=n;i++) vis[i]=false;
        p=0;
        for (int i=1;i<=n;i++) {
            if (!vis[i]&&!in[i]) {
                ++p; dfs(i);
            }
        }
        /*for (int i=1;i<=p;i++) {
            for (int j=0;j<vec[i].size();j++) printf("%d ",vec[i][j]); printf("\n");
        }*/
        clearGraph();
        mp.clear();
        for (int i=1;i<=n;i++)
            if (fa[i]!=0) {
                int x=belong[fa[i]],y=belong[i];
                if (mp[make_pair(x,y)]) continue;
                if (x==y) continue;
                //printf("debug %d %d\n",x,y);
                add(x,y); mp[make_pair(x,y)]=true;
            }
        if (!topu_2()) {
            printf("0\n");
            return 0;
        }
        //for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
        for (int i=0;i<p;i++) {
            int t=ans[i];
            for (int j=0;j<vec[t].size();j++) printf("%d ",vec[t][j]);
        }
        printf("\n");
    }
    return 0;
}


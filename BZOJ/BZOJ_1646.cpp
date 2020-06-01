#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e6+10;
queue<int> q;
bool vis[maxn];
int n,k;
int dist[maxn];
int main()
{
    scanf("%d%d",&n,&k);
    q.push(n); vis[n]=true; dist[n]=0;
    while (q.size()) {
        int u=q.front(); q.pop();
        if (u==k) break;
        if (2*u<maxn&&!vis[2*u]) {
            vis[2*u]=true; dist[2*u]=dist[u]+1; q.push(2*u);
        }
        if (u+1<maxn&&!vis[u+1]) {
            vis[u+1]=true; dist[u+1]=dist[u]+1; q.push(u+1);
        }
        if (u-1>=0&&!vis[u-1]) {
            vis[u-1]=true; dist[u-1]=dist[u]+1; q.push(u-1);
        }
    }
    printf("%d\n",dist[k]);
    return 0;
}

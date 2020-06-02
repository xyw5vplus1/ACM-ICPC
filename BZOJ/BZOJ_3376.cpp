#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5;
int father[maxn],d[maxn],sz[maxn];
int n,x,y;
char s[10];
int _find(int x)
{
    if (x==father[x]) return x;
    int u=_find(father[x]);
    d[x]+=d[father[x]];
    father[x]=u;
    return u;
}
void _merge(int u,int v)
{
    u=_find(u); v=_find(v);
    if (u==v) return ;
    d[u]=sz[v];
    sz[v]+=sz[u];
    father[u]=v;
}
int main()
{
    scanf("%d",&n);
    rep(i,1,n+1) {
    	father[i]=i; sz[i]=1; d[i]=0;
    }
    rep(i,1,n+1) {
        scanf("%s",s);
        if (s[0]=='M') {
            scanf("%d%d",&x,&y);
            _merge(x,y);
        }
        else {
            scanf("%d",&x);
            _find(x);
            printf("%d\n",d[x]);
        }
    }
    return 0;
}

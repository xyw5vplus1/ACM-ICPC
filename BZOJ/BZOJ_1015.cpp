#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
const int maxn=4e5+10;
int father[maxn],ans[maxn],a[maxn],b[maxn],c[maxn];
int n,m,q;
bool vis[maxn];
int _find(int x)
{
    return (x==father[x])?x:father[x]=_find(father[x]);
}
bool _merge(int u,int v)
{
    u=_find(u); v=_find(v);
    if (u==v) return false;
    father[u]=v;
    return true;
}
vector<int> v[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,m+1) {
        scanf("%d%d",&a[i],&b[i]);
        a[i]++; b[i]++;
        v[a[i]].push_back(i);
        v[b[i]].push_back(i);
    }
    scanf("%d",&q);
    rep (i,1,q+1) {
        scanf("%d",&c[i]); c[i]++;
        vis[c[i]]=true;
    }
    rep(i,1,n+1) father[i]=i;
    int cnt=n-q;
    rep(i,1,m+1) {
        if (!vis[a[i]]&&!vis[b[i]]) {
            if (_merge(a[i],b[i])) cnt--;
        }
    }
    per(i,q,0) {
        ans[i]=cnt;
        cnt++; vis[c[i]]=false;
        for (int j=0;j<v[c[i]].size();j++) {
            int e=v[c[i]][j];
            if (!vis[a[e]]&&!vis[b[e]]&&_merge(a[e],b[e])) cnt--;
        }
    }
    ans[0]=cnt;
    rep(i,0,q+1) printf("%d\n",ans[i]);
    return 0;
}

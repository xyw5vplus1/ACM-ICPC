#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5;
typedef double db;
vector<int> v[maxn+5];
int T,n;
int cnt,ans;
bool vis[maxn+5];
int a[maxn+5],c[maxn+5],p[maxn+5];
void dfs(int u)
{
    a[++cnt]=c[u]; vis[u]=true;
    if (!vis[p[u]]) dfs(p[u]);
}
bool check(int st,int d)
{
    for (int i=st;i+d<=2*cnt;i+=d)
        if (a[i]!=a[i+d]) return false;
    return true;
}
void calc()
{
    for (int i=1;i<=cnt;i++) a[cnt+i]=a[i];
    for (int i=1;i*i<=cnt;i++) {
        if (cnt%i==0) {
            for (int j=1;j<=i;j++) {
                if (check(j,i)) {
                    ans=min(ans,i); break;
                }
            }
            for (int j=1;j<=cnt/i;j++) {
                if (check(j,cnt/i)) {
                    ans=min(ans,cnt/i); break;
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        memset(vis,false,sizeof(bool)*(n+1));
        ans=n;
        for (int i=1;i<=n;i++) scanf("%d",&p[i]);
        for (int i=1;i<=n;i++) scanf("%d",&c[i]);
        for (int i=1;i<=n;i++)
            if (!vis[i]) {
                cnt=0;
                dfs(i);
                calc();
            }
        printf("%d\n",ans);
    }
    return 0;
}


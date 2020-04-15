/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
typedef double db;
int T;
int n,x,y;
bool vis[maxn+5],p[maxn+5];
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        memset(vis,false,sizeof(bool)*(n+1));
        memset(p,false,sizeof(bool)*(n+1));
        int cnt=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&x);
            bool bo=false;
            for (int j=1;j<=x;j++) {
                scanf("%d",&y);
                if (!bo&&!vis[y]) {
                    vis[y]=true; cnt++; p[i]=true; bo=true;
                }
            }
        }
        if (cnt==n) printf("OPTIMAL\n");
        else {
            int vx,vy;
            for (int i=1;i<=n;i++)
                if (!p[i]) {
                    vx=i; break;
                }
            for (int i=1;i<=n;i++)
            if (!vis[i]) {
                vy=i; break;
            }
            printf("IMPROVE\n");
            printf("%d %d\n",vx,vy);
        }
    }
    return 0;
}*/

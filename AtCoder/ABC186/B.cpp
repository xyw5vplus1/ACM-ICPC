#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define first fi
#define second se
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=105;
int a[maxn][maxn];
int n,m;
int ans;
int mn;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    mn=a[1][1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) mn=min(mn,a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) ans+=a[i][j]-mn;
    printf("%d\n",ans);
    return 0;
}


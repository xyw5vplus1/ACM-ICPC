#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const ll INF=1e18;
const int maxn=1e5+10;
int T;
int a[maxn],b[maxn],sum1[maxn],sum2[maxn];
int n,m;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        scanf("%d",&m);
        for (int i=1;i<=m;i++) scanf("%d",&b[i]);
        for (int i=1;i<=n;i++) sum1[i]=sum1[i-1]+a[i];
        for (int i=1;i<=m;i++) sum2[i]=sum2[i-1]+b[i];
        ll ans=-INF;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++) ans=max(ans,1LL*(sum1[i]+sum2[j]));
        printf("%lld\n",ans);
    }
    return 0;
}

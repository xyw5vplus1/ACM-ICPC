#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define first fi
#define second se
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
int a[maxn];
int n;
ll sum[maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ll ans=0;
    for (int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+a[i];
        ans+=1LL*a[i]*i-sum[i];
    }
    printf("%lld\n",ans);
    return 0;
}


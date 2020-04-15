/*#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5;
const int mod=998244353;
int n,k;
int v[maxn+5];
int a[maxn+5],pos[maxn+6];
int main()
{
    scanf("%d%d",&n,&k);
    ll ans1=0;
    for (int i=n-k+1;i<=n;i++) ans1+=i;
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    int num=0;
    for (int i=n-k+1;i<=n;i++) v[++num]=pos[i];
    sort(v+1,v+k+1);
    ll ans2=1;
    for (int i=2;i<=k;i++)
        ans2=1LL*ans2*(v[i]-v[i-1])%mod;
    printf("%lld %lld\n",ans1,ans2);
    return 0;
}*/

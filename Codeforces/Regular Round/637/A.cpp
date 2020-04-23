#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
typedef long long ll;
typedef double db;
int gcd(int n,int m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
int quick_pow(int a,int b,int mod)
{
    int ans=1;
    while (b) {
        if (b&1LL) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans%mod;
}
inline ll quick_mul(ll x,ll y,ll mod)
{
    return (x*y-(ll)((long double)x/mod*y)*mod+mod)%mod;
}
int T,n;
int a[maxn],l[maxn],r[maxn];
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cur=1;
        int cnt=0;
        while (cur<=n) {
            int nxt=cur;
            while (nxt<=n&&a[nxt]-a[cur]==nxt-cur) nxt++;
            ++cnt;
            l[cnt]=cur; r[cnt]=nxt-1;
            cur=nxt;
        }
        //for (int i=1;i<=cnt;i++) printf("debug %d %d\n",l[i],r[i]);
        bool ans=true;
        for (int i=cnt;i-1>=1;i--)
            if (a[r[i]]+1!=a[l[i-1]]) {
                ans=false; break;
            }
        if (ans) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

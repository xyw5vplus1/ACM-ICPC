#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a-1;i>=b;i--)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int maxn=2e6+10;
const int mod=1e9+7;
struct node
{
    int val;
    int ch[2];
    int fa;
}a[maxn];
int s[maxn];
int n;
int inv[maxn];
int sz[maxn];
void setInv(int n)
{
    inv[0]=inv[1]=1;
    rep(i,2,n)
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}
void dfs(int u)
{
    if (u==0) return ;
    dfs(a[u].ch[0]); dfs(a[u].ch[1]);
    sz[u]=sz[a[u].ch[0]]+sz[a[u].ch[1]]+1;
}
int quick_pow(int a,int b)
{
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans;
}
int T;
int main()
{
    setInv(maxn);
    //for (int i=1;i<maxn;i++) printf("%d %d\n",i,inv[i]);
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        rep(i,1,n+1) {
            scanf("%d",&a[i].val);
            a[i].ch[0]=a[i].ch[1]=0; a[i].fa=0;
        }
        int h=0;
        rep(i,1,n+1) {
            int last=0;
            while (h>0&&a[s[h-1]].val<a[i].val) {
                last=s[h-1]; h--;
            }
            if (h>0) a[i].fa=s[h-1];
            a[i].ch[0]=last; a[last].fa=i;
            if (h>0) a[s[h-1]].ch[1]=i;
            s[h++]=i;
        }
        int root=0;
        rep(i,1,n+1)
            if (a[i].fa==0) root=i;
        dfs(root);
        ll tot=1;
        rep(i,1,n+1) tot=1LL*tot*inv[sz[i]]%mod;
        tot=quick_pow(tot,mod-2);
        printf("%d\n",1LL*quick_pow(tot,mod-2)*n%mod*inv[2]%mod);
    }
    return 0;
}

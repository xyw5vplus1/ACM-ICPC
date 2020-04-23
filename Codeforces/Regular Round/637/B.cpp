#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
using namespace std;
const int maxn=2e3+10;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
typedef long long ll;
typedef double db;
bool bo[maxn][maxn];
int f[150][10];
int a[maxn];
char s[maxn];
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
int mp[1000];
int getCnt(int x)
{
    int ans=0;
    while (x) {
        ans++;
        x=(x&(x-1));
    }
    return ans;
}
vector<int> ans;
int n,k;
int dp[maxn][maxn];
int main()
{
    memset(mp,-1,sizeof(mp));
    mp[119]=0; mp[18]=1; mp[93]=2; mp[91]=3; mp[58]=4; mp[107]=5; mp[111]=6;
    mp[82]=7; mp[127]=8; mp[123]=9;
    memset(f,-1,sizeof(f));
    for (int i=0;i<=127;i++)
        for (int j=0;j<=127;j++)
        if ((i&j)==0) f[i][getCnt(j)]=max(f[i][getCnt(j)],mp[i^j]);
    scanf("%d",&n);
    scanf("%d",&k);
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++) {
        scanf("%s",s+1);
        int len=strlen(s+1);
        for (int j=1;j<=len;j++) a[i]=a[i]*2+s[j]-'0';
        //printf("%d\n",a[i]);
    }
    //printf("%d %d\n",f[18][4],f[18][5]);
    bo[n+1][0]=true;
    for (int i=n;i>=1;i--)
    for (int j=k;j>=0;j--)
    if (bo[i+1][j])
    for (int p=0;p<=7;p++){
        if (j+p<=k&&f[a[i]][p]!=-1) bo[i][j+p]|=bo[i+1][j];
    }
    int last=k;
    int cur=1;
    //printf("%d %d\n",bo[2][1],bo[2][0]);
    while (cur<=n) {
        //printf("debug %d %d\n",cur,last);
        int mx=-1; int mxd=-1;
        for (int j=0;j<=7;j++)
        if (last>=j&&bo[cur+1][last-j]) {
            if (f[a[cur]][j]>mx) {
                mx=f[a[cur]][j]; mxd=j;
            }
        }
        //printf("%d %d\n",mx,mxd);
        if (mx!=-1) {
            ans.pb(mx);
            cur++; last-=mxd;
        }
        else {
            printf("-1\n");
            return 0;
        }
    }
    for (int i=0;i<ans.size();i++) printf("%d",ans[i]);
    return 0;
}

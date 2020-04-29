#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
const int maxn=1e6;
int inv[maxn+5],fac[maxn+5],facInv[maxn+5];
void setInv(int n)
{
    inv[0]=inv[1]=1;
    for (int i=2;i<=n;i++) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}
void setFac(int n)
{
    fac[0]=facInv[0]=1;
    for (int i=1;i<=n;i++) {
        fac[i]=1LL*fac[i-1]*i%mod;
        facInv[i]=1LL*facInv[i-1]*inv[i]%mod;
    }
}
int C(int n,int m)
{
    if (n<m) return 0;
    if (n<0||m<0) return 0;
    int ans=fac[n];
    ans=1LL*ans*facInv[m]%mod;
    ans=1LL*ans*facInv[n-m]%mod;
    return ans;
}
int T,n,m;
int main()
{
    setInv(maxn); setFac(maxn);
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        if (n>m) swap(n,m);
        if (n==1&&m==1) printf("%d\n",1);
        else if (n==1) printf("%d\n",2);
        else printf("%d\n",4LL*C(n+m-2,n-1)%mod);
    }
    return 0;
}

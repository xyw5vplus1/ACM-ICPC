#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const int mod=1e9+7;
int f[maxn],sum[maxn];
int fac[maxn],inv[maxn],facInv[maxn],suf[maxn],pre[maxn];
int t;
ll x,y;
int quick_pow(ll a,int b)
{
    a%=mod;
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans;
}
int calc(int f[],int n,ll X)
{
    if (X>=0&&X<=n) return f[X];
    X%=mod;
    pre[0]=(X%mod+mod)%mod; suf[n]=((X-n)%mod+mod)%mod;
    for (int i=1;i<=n;i++) pre[i]=1LL*pre[i-1]*(X-i)%mod;
    for (int i=n-1;i>=0;i--) suf[i]=1LL*suf[i+1]*(X-i)%mod;
    int res=0;
    for (int i=0;i<=n;i++) {
        int tem=1;
        if (i!=0) tem=1LL*tem*pre[i-1]%mod;
        if (i!=n) tem=1LL*tem*suf[i+1]%mod;
        if ((n-i)&1) tem=(mod-tem);
        res=(res+1LL*tem*f[i]%mod*facInv[i]%mod*facInv[n-i]%mod)%mod;
    }
    return (res%mod+mod)%mod;
}
void setInv(int n)
{
    inv[0]=inv[1]=1;
    for (int i=2;i<=n;i++)
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}
void setFac(int n)
{
    fac[0]=1; facInv[0]=1;
    for (int i=1;i<=n;i++) {
        fac[i]=1LL*fac[i-1]*i%mod;
        facInv[i]=1LL*facInv[i-1]*inv[i]%mod;
    }
}
int getSum(ll X)
{
    ll x1=X/4;
    int ans1=calc(sum,t+2,x1);
    for (ll i=4*x1+1;i<=X;i++) {
        if (i%4==1) ans1=(ans1+t)%mod;
        else if (i%4==2) ans1=(ans1+(1LL*(quick_pow(i,t+1)-i%mod+mod)%mod*quick_pow(i-1,mod-2)%mod+1)%mod)%mod;
        else if (i%4==3) ans1=(ans1+(t/2))%mod;
        else ans1=(ans1+(1LL*(quick_pow(i,t+1)-i%mod+mod)%mod*quick_pow(i-1,mod-2)%mod)%mod)%mod;
    }
    return ans1;
}
int main()
{
    scanf("%d%lld%lld",&t,&x,&y);
    setInv(maxn-1); setFac(maxn-1);
    for (int i=1;i<=4*(t+2);i++) {
        if (i%4==1) f[i]=t;
        else if (i%4==2) f[i]=(1LL*(quick_pow(i,t+1)-i+mod)%mod*inv[i-1]%mod+1)%mod;
        else if (i%4==3) f[i]=(t/2);
        else f[i]=(1LL*(quick_pow(i,t+1)-i+mod)%mod*inv[i-1]%mod)%mod;
    }
    for (int i=1;i<=4*(t+2);i++) f[i]=(f[i]+f[i-1])%mod;
    for (int i=0;i<=t+2;i++) sum[i]=f[4*i];
    //for (int i=1;i<=7;i++) printf("%d %d\n",i,f[i]);
    int ans1=getSum(x-1),ans2=getSum(y);
    printf("%d\n",(ans2-ans1+mod)%mod);
    return 0;
}

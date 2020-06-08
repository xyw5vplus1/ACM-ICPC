#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=5e5+10;
const int mod=998244353;
int inv[maxn],fac[maxn],facInv[maxn];
int n,k;
void setInv(int n)
{
	inv[0]=inv[1]=1;
	rep(i,2,n) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}
void setFac(int n)
{
	fac[0]=facInv[0]=1;
	rep(i,1,n) {
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
int main()
{
	setInv(maxn); setFac(maxn);
	scanf("%d%d",&n,&k);
	if (n<k) printf("0\n");
	else {
		int ans=0;
		rep(i,1,n+1) {
			ans=(ans+C(n/i-1,k-1))%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
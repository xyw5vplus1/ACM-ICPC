#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e7+10;
int num=0;
int T,mod,n,m;
int primes[maxn],inv[maxn],fac[maxn],ans[maxn];
bool is_prime[maxn];
void Sieve(int n)
{
	primes[0]=0;
	for (int i=2;i<n;i++) is_prime[i]=true;
	for (int i=2;i<n;i++) {
		if (is_prime[i]) primes[++num]=i;
		for (int j=1;j<=num&&primes[j]*i<n;j++) {
			is_prime[i*primes[j]]=false;
			if (i%primes[j]==0) break;
		} 
	}
}
int main()
{
	Sieve(maxn);
	scanf("%d%d",&T,&mod);
	fac[0]=1;
	for (int i=1;i<maxn;i++) fac[i]=1LL*fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for (int i=2;i<maxn;i++) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	ans[0]=1;
	for (int i=1;i<=num;i++) ans[i]=1LL*ans[i-1]*(1-inv[primes[i]]+mod)%mod;
	while (T--) {
		scanf("%d%d",&n,&m);
		int l=0,r=num;
		while (l<r) {
			int mid=(l+r+1)>>1;
			if (primes[mid]<=m) l=mid;
			else r=mid-1;
		}
		printf("%d\n",1LL*ans[l]*fac[n]%mod);
	}
	return 0;
}

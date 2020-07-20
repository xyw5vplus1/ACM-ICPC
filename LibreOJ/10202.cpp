#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int mod=1e9+7;
const int maxn=1e6+10;
int n;
int primes[maxn];
int num=0;
bool is_prime[maxn];
void Sieve(int n)
{
	primes[0]=0;
	for (int i=2;i<=n;i++) is_prime[i]=true;
	for (int i=2;i<=n;i++) {
		if (is_prime[i]) primes[++num]=i;
		for (int j=1;j<=num&&primes[j]*i<=n;j++) {
			is_prime[i*primes[j]]=false;
			if (i%primes[j]==0) break;
		} 
	}
}
int main()
{
	scanf("%d",&n);
	Sieve(n);
	int ans=1;
	for (int i=1;i<=num;i++) {
		int tem=0;
		int n0=n;
		while (n0) {
			tem+=(n0/primes[i]); n0/=primes[i]; 
		}
		ans=1LL*ans*(2*tem+1)%mod;
	}
	printf("%d\n",ans);
	return 0;
}

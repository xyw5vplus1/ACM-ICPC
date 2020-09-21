#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n;
bool is_prime[maxn];
int primes[maxn];
int n0,x;
void setPrime(int n)
{
    for (int i=2;i<=n;i++) is_prime[i]=true;
    for (int i=2;i<=n;i++) {
        if (is_prime[i]) primes[++n0]=i;
        for (int j=1;j<=n0&&1LL*primes[j]*i<=n;j++) {
            is_prime[i*primes[j]]=false;
            if (i%primes[j]==0) break;
        }
    }
}
int divide(int x)
{
	int ans=0,cnt;
	for (int i=1;i<=n0&&1LL*primes[i]*primes[i]<=x;i++) {
		cnt=0;
		while (x%primes[i]==0) {
			cnt++; x/=primes[i];
		}
		if (i==1) ans+=min(1,cnt);
		else ans+=cnt;
	}
	if (x>1) ans++;
	return ans;
}
int main()
{
	setPrime(maxn);
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		int ans=0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&x);
			//printf("debug %d\n",divide(x));
			ans^=divide(x);
		}
		if (ans) printf("W\n");
		else printf("L\n");
	}
	return 0;
}
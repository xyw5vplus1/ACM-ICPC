#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=3e4+10;
ll a[maxn];
int T,n;
ll k;
bool check(ll len)
{
	ll cnt=0,last=0;
	if (len==0) return true;
	for (int i=1;i<=n;i++) {
		if (last+a[i]<len) last=a[i];
		else {
			cnt+=(last+a[i])/len; last=(last+a[i])%len;
			if (cnt>=k) return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d%I64d",&n,&k);
		for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
		ll l=0,r=1e18;
		while (l<r) {
			ll mid=(l+r+1)>>1LL;
			if (check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%I64d\n",l*k);
	}
	return 0;
}
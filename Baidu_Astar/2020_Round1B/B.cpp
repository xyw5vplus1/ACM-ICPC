#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+10;
int a[maxn];
int T,n;
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		ll sum=0,ans=0;
		for (int i=1;i<=n;i++) {
			ans=ans+1LL*a[i]*(i-1)-sum;
			sum+=a[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
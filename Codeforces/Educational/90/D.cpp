#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
int a[maxn];
int T;
int n;
ll sum1[maxn],sum2[maxn];
int b1[maxn],b2[maxn];
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		ll sum=0;
		int n1=0,n2=0;
		for (int i=0;i<n;i++) {
			if (i%2==0) {
				b1[n1]=a[i]-a[i-1];
				sum+=a[i];
				n1++;
			}
		}
		ll ans=0;
		for (int i=0;i<n1;i++) {
			if (i==0) sum1[i]=b1[i];
			else sum1[i]=sum1[i-1]+b1[i];
		} 
		int mn=0;
		for (int i=0;i<n1;i++) {
			ans=max(ans,sum+sum1[i]-mn);
			mn=min(mn,sum1[i]);
		}
		for (int i=0;i<n;i++) {
			if (i%2==1) {
				b2[n2]=a[i]-a[i-1];
				n2++;
			}
		}
		for (int i=0;i<n2;i++) {
			if (i==0) sum2[i]=b2[i];
			else sum2[i]=sum2[i-1]+b2[i];
		}
		int mx=0;
		for (int i=0;i<n2;i++) {
			ans=max(ans,sum-(sum2[i]-mx));
			mx=max(mx,sum2[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
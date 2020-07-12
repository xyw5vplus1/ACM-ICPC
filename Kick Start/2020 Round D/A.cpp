#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
int T;
const int maxn=2e5+10;
int a[maxn];
int n;
int main()
{
	scanf("%d",&T);
	for (int kase=1;kase<=T;kase++) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		int cnt=0,mx=-1;
		for (int i=1;i<=n;i++) {
			if (a[i]>mx) {
				if (i==n||a[i]>a[i+1]) cnt++;
			}
			mx=max(mx,a[i]);
		}
		printf("Case #%d: %d\n",kase,cnt);
	}
	return 0;
}

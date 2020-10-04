#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=3e5+10;
int a[maxn];
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	bool bo=true;
	for (int i=1;i<=n;i++)
		if (a[i]>i) {
			bo=false; break;
		}
	if (!bo) printf("-1\n");
	else {
		db mn=1.0;
		for (int i=1;i<=n;i++) 
			mn=min(mn,1.0*a[i]/i);
		printf("%.12f\n",mn);
	}
	return 0;
}
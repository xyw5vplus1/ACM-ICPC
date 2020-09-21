#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+10;
int T,n;
int a[maxn];
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		bool bo=true;
		for (int i=1;i<n;i++)
			if (a[i]==a[i+1]) bo=false;
		if (bo) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
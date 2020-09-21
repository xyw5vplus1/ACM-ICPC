#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n;
int a[maxn];
bool bo[maxn];
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) 
			scanf("%d",&a[i]);
		if (n<=3) printf("0\n");
		else {
			int cnt=0;
			for (int i=1;i<=n;i++)
				bo[i]=false;
			for (int i=2;i<n;i++)
				if (a[i]>a[i-1]&&a[i]>a[i+1]) {
					bo[i]=true; cnt++;
				}
			int tem;
			int ans=cnt;
			for (int i=1;i<=n;i++) {
				tem=cnt;
				if (i!=1&&i!=n) {
					if (bo[i]) tem--;
					if (bo[i-1]&&a[i-1]<=a[i+1]) tem--;
					if (!bo[i-1]&&i-2>=1&&a[i-1]>a[i-2]&&a[i-1]>a[i+1]) tem++;
					if (bo[i+1]&&a[i+1]<=a[i-1]) tem--;
					if (!bo[i+1]&&i+2<=n&&a[i+1]>a[i-1]&&a[i+1]>a[i+2]) tem++;
				}
				else if (i==1) {
					if (bo[i+1]) tem--;
				}
				else if (i==n) {
					if (bo[i-1]) tem--;
				}
				if (tem<ans) ans=tem;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
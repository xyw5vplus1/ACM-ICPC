#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=100+10;
int a[maxn][maxn];
int b[maxn][maxn];
int T,n;
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		}
		for (int i=1;i<=3;i++) {
			for (int j=1;j<=3;j++) scanf("%d",&b[i][j]);
		}
		int cnt=0;
		for (int i=1;i<=3;i++) {
			for (int j=1;j<=3;j++)
				if (b[i][j]>0) cnt++;
		}
		if (cnt>1) {
			for (int i=1;i<=n;i++) {
				for (int j=1;j<n;j++) printf("%d ",0);
				printf("0\n");
			}
		}
		else {
			if (b[1][1]==0) {
				for (int i=1;i<=n;i++) {
					for (int j=1;j<n;j++) printf("%d ",0);
					printf("0\n");
				}
			}
			else {
				for (int i=1;i<=n;i++) {
					for (int j=1;j<n;j++) printf("%d ",a[i][j]);
					printf("%d\n",a[i][n]);
				}
			}
		}
	}
	return 0;
}
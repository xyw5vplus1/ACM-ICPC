#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=5e5+10;
int n,n0,m,x;
int a[maxn],sum[maxn];
int main()
{
	scanf("%d%d%d",&n,&n0,&m);
	memset(a,-1,sizeof(a));
	for (int i=1;i<=m;i++) {
		scanf("%d",&x);
		a[x]=0;
	}	
	sum[0]=0;
	for (int i=1;i<=n;i++) {
		if (a[i]==0) sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	for (int i=n;i>=1;i--) 
		if (a[i]==0) {
			if (i+1<=n&&a[i]!=a[i+1]) n0--;
		}
		else {
			if (sum[i]==0) {
				if (n0) {
					a[i]=1-a[i+1]; n0--;
				}
				else {
					a[i]=a[i+1]; 
				}
			} 
			else {
				if (n0>=2) {
					a[i]=1-a[i+1]; n0--;
				}
				else a[i]=a[i+1];
			}
		}
	for (int i=1;i<=n;i++) printf("%d",a[i]); printf("\n");
	return 0;
}
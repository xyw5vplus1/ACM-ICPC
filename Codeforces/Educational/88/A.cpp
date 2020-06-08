#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
int T,n,m,k;
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&n,&m,&k);
		int t=n/k;
		if (m<=t) printf("%d\n",m);
		else {
			int p=(m-t)/(k-1);
			if ((m-t)%(k-1)) p++;
			printf("%d\n",t-p);
		} 
	}
	return 0;
}
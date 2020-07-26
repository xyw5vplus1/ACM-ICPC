#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
int T,n,m,p,down;
bool check(int k)
{
	if (k==0) return true;
	if (n-(k-1)*down-m<0) return false;
	return true;
}
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&n,&m,&p);
		int get=(int)(m-m*p/100.0);
		down=m-get;
		if (n<m) printf("0\n");
		else {
			int l=0,r=n/down+1;
			while (l<r) {
				int mid=(l+r+1)>>1;
				if (check(mid)) l=mid;
				else r=mid-1;
			}
			printf("%d\n",l);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
int T,h,c,t;
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&h,&c,&t);
		if (h+c>=2*t) printf("2\n");
		else {
			int l=0,r=1e6;
			while (l<r) {
				int mid=(l+r+1)>>1;
				if (1LL*(mid+1)*h+1LL*mid*c>=1LL*(2*mid+1)*t) l=mid;
				else r=mid-1;
			}
			if (1LL*(1LL*(l+1)*h+1LL*l*c)*(2*l+3)+1LL*(1LL*(l+2)*h+1LL*(l+1)*c)*(2*l+1)<=2LL*t*(2*l+1)*(2*l+3)) printf("%d\n",2*l+1);
			else printf("%d\n",2*l+3); 
		}	
	}
	return 0;
}
#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
int T,a,b,c;
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&a,&b,&c);
		int ans1=-1,ans2=-1;
		if (a<c) ans1=1;
		if (1LL*a*b>c) ans2=b;
		printf("%d %d\n",ans1,ans2); 
	}
	return 0;
}
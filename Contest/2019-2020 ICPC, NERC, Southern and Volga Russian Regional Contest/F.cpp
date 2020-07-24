#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
int n;
int main()
{
	scanf("%d",&n);
	int ans=n*4;
	for (int i=1;i<=n;i++)
		if (n%i==0) ans=min(ans,2*(i+n/i));
	printf("%d\n",ans); 
	return 0;
}
#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%s",s+1);
		int len=strlen(s+1);
		for (int i=1;i<=len;i++) 
			if (s[i]=='+') sum[i]=sum[i-1]+1;
			else sum[i]=sum[i-1]-1;
		int mn=0;
		ll ans=0;
		for (int i=1;i<=len;i++) {
			if (sum[i]<mn) {
				ans+=i; mn=sum[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
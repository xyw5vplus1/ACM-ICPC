#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
char s[1005];
int T;
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%s",s);
		int len=strlen(s);
		int sum=0,ans=0;
		rep(i,0,len) {
			if (s[i]=='1'&&sum>0) {
				sum--; ans++;
			} 
			else if (s[i]=='0') sum++;
		}
		if (ans%2==0) printf("NET\n");
		else printf("DA\n");
	}
	return 0;
}
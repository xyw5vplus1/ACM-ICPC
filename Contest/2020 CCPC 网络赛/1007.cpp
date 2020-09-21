#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
int num[30];
int T;
char s[maxn];
int main()
{
	scanf("%d",&T);
	for (int kase=1;kase<=T;kase++){
		scanf("%s",s);
		for (int i=0;i<26;i++) num[i]=0;
		int ans=0;
		int len=strlen(s);
		for (int i=0;i<len;i++) {
			num[s[i]-'a']++;
		}
		for (int i=0;i<26;i++)
			if (num[i]>ans) ans=num[i];
		printf("Case #%d: %d\n",kase,ans);
	}
	return 0;
}
#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
int T,n,m,p,down;
bool isOk;
bool vis[15];
int cnt[15];
char s[100];
void dfs(int last,int num,int pre,int need)
{
	if (isOk) return ;
	if (num>=5) {
		isOk=true; return ;
	}
	for (int i=pre+1;i<=9;i++) 
		if (!vis[i]) {
			if (last+cnt[i]>=need) {
				vis[i]=true; dfs(0,num+1,-1,need); vis[i]=false;
			}
			else {
				vis[i]=true; dfs(last+cnt[i],num,i,need); vis[i]=false;
			}
		}
}
bool check(int k)
{
	for (int i=0;i<=9;i++) vis[i]=false;
	int cnt0=0;
	for (int i=0;i<=9;i++)
	if (cnt[i]>=k) {
		vis[i]=true; cnt0++;
	}
	if (cnt0>=5) return true;
	isOk=false;
	dfs(0,cnt0,-1,k);
	return isOk;
}
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=0;i<=9;i++) cnt[i]=0;
		for (int i=0;i<n;i++) {
			scanf("%s",s);
			cnt[s[4]-'0']++;
		}
		int l=0,r=n/5;
		while (l<r) {
			int mid=(l+r+1)>>1;
			if (check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",n-l);
	}
	return 0;
}
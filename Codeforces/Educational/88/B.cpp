#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
char s[105][1005];
int T,n,m,x,y;
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d%d",&n,&m,&x,&y);
		int ans=0;
		rep(i,1,n+1) scanf("%s",s[i]+1);
		if (2*x<=y) {
			rep(i,1,n+1) {
				rep(j,1,m+1) 
				if (s[i][j]=='.') ans+=x;
			}
		}
		else {
			rep(i,1,n+1) {
				int last=0;
				bool bo=false;
				rep(j,1,m+1) 
				if (s[i][j]=='.') {
					if (bo) last++;
					else {
						bo=true; last=1;
					}
				}
				else {
					ans+=(last/2)*y+(last%2)*x;
					bo=false; last=0;
				}
				ans+=(last/2)*y+(last%2)*x;			
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
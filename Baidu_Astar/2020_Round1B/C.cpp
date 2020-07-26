#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e4+10;
int T,n,len,x,t;
bool vis[maxn];
std::vector<int> v[105][15];
std::vector<int> ans;
int main()
{
	scanf("%d",&T);
	while (T--) {
		for (int i=1;i<=100;i++)
			for (int j=1;j<=10;j++) v[i][j].clear();
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&len);
			for (int j=1;j<=len;j++) {
				scanf("%d%d",&t,&x);
				v[t][x].push_back(i);
			}
		}
		for (int i=1;i<=n;i++) vis[i]=false;
		vis[1]=true;
		for (int j=1;j<=100;j++) 
			for (int p=1;p<=10;p++) {
				bool bo=false;
				for (int i=0;i<(int)v[j][p].size();i++) {
					int people=v[j][p][i];
					if (vis[people]) bo=true;
				}
				if (bo) {
					for (int i=0;i<(int)v[j][p].size();i++) {
						int people=v[j][p][i];
						vis[people]=true;
					}
				}
			}
		ans.clear();
		for (int i=1;i<=n;i++)
			if (vis[i]) ans.push_back(i);
		for (int i=0;i<(int)ans.size()-1;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[ans.size()-1]);
	}
	return 0;
}

#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
int num=0;
int head[maxn];
int deg[maxn],ex[maxn],ey[maxn],e[maxn],vis[maxn];
bool findPos;
int mn;
int n,root,T;
std::vector<int> ans;
vector<pair<int,int> > ansp;
struct edge
{
	int to,_next,id;
}G[2*maxn];
void add(int u,int v,int w)
{
	G[++num].to=v;
	G[num]._next=head[u];
	G[num].id=w;
	head[u]=num;
}
void dfs(int u)
{
	vis[u]=1; 
	int v;
	for (int i=head[u];i;i=G[i]._next) {
		v=G[i].to;
		if (vis[v]) continue;
		dfs(v);
	}
}
void getAns(int u)
{
	vis[u]=2;
	int v;
	bool bo=false;
	for (int i=head[u];i;i=G[i]._next) {
		v=G[i].to;
		if (vis[v]!=2) {
			getAns(v); bo=true;
		}
	}
	if (findPos) return ;
	if (!bo) {
		for (int i=head[u];i;i=G[i]._next) {
			v=G[i].to;
			ans.push_back(G[i].id); ansp.push_back(make_pair(u,root));
			findPos=true;
			break;
		}
	}
}
void Init()
{
	memset(head,0,sizeof(int)*(2*n+1));
	memset(vis,0,sizeof(int)*(2*n+1));
	num=0;
	ans.clear(); ansp.clear();
}
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		Init();
		for (int i=1;i<=n;i++) {
			scanf("%d%d",&ex[i],&ey[i]);
			e[2*i-1]=ex[i]; e[2*i]=ey[i];
		}
		sort(e+1,e+2*n+1);
		int n0=unique(e+1,e+2*n+1)-(e+1);
		for (int i=1;i<=n;i++) {
			ex[i]=lower_bound(e+1,e+n0+1,ex[i])-e;
			ey[i]=lower_bound(e+1,e+n0+1,ey[i])-e;
		}
		for (int i=1;i<=n0;i++) {
			vis[i]=0; head[i]=0; //deg[i]=0;
		}
		for (int i=1;i<=n;i++) {
			add(ex[i],ey[i],i); add(ey[i],ex[i],i); //deg[ex[i]]++; deg[ey[i]]++;
		}
		int cnt=0;
		for (int i=1;i<=n0;i++) 
			if (!vis[i]) {
				cnt++; dfs(i);
			}
		if (cnt==1) printf("0\n");
		else {
			cnt=0;
			for (int i=1;i<=n0;i++) vis[i]=0;
			root=-1;
			for (int i=1;i<=n0;i++) 
			if (!vis[i]) {
				cnt++; 
				if (cnt==1) {
					root=i; dfs(i);
				}
				else {
					dfs(i); findPos=false; getAns(i);
				}
			}
			printf("%d\n",(int)ans.size());
			for (int i=0;i<(int)ans.size();i++) {
				printf("%d ",ans[i]);
				printf("%d %d\n",e[ansp[i].first],e[ansp[i].second]);
			}
		}
	}
	return 0;
}
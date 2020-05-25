#include<bits/stdc++.h>
using namespace std;
const int maxn=50+10;
const int INF=0x3f3f3f3f;
class SalesmansDilemma
{
	public:
	int head[maxn];
	struct edge
	{
		int to,_next,val;
	}G[maxn];
	int num;
	void add(int u,int v,int w)
	{
		G[++num].to=v;
		G[num]._next=head[u];
		G[num].val=w;
		head[u]=num;
	}
	int getNum(string s)
	{
		int x=0;
		for (int i=0;i<s.length();i++) x=(x*10+s[i]-'0');
		return x;
	}
	queue<int> q;
	int dist[maxn];
	int in[maxn];
	bool vis[maxn];
	string SPFA(int n,int s,int t,vector <int> profits)
	{
		memset(vis,false,sizeof(vis));
		memset(in,0,sizeof(in));
		for (int i=0;i<n;i++) dist[i]=INF;
		dist[s]=0-profits[s]; vis[s]=true; in[s]=1;
		while (q.size()) q.pop();
		q.push(s);
		while (q.size()) {
			int u=q.front(); q.pop(); vis[u]=false;
			for (int i=head[u];i;i=G[i]._next) {
				int v=G[i].to;
				if (!vis[v]&&dist[u]+G[i].val-profits[v]<dist[v]) {
					in[v]++;
					if (in[v]>n) return "ENDLESS PROFIT";
					dist[v]=dist[u]+G[i].val-profits[v];
					q.push(v);
					vis[v]=true;
				}
			}
		}
		if (dist[t]==INF) return "IMPOSSIBLE";
		return "BEST PROFIT: "+to_string(-dist[t]);
	}
	string bestRoute(int towns, int origin, int destination, vector <string> travelCosts, vector <int> profits)
	{
		for (auto e:travelCosts) {
			int pos1=e.find(" ");
			int u=getNum(e.substr(0,pos1));
			int pos2=e.find(" ",pos1+1);
			int v=getNum(e.substr(pos1+1,pos2-pos1-1));
			int w=getNum(e.substr(pos2+1,e.length()-pos2-1));
			add(u,v,w);
			//printf("%d %d %d\n",u,v,w);
		}
		return SPFA(towns,origin,destination,profits);
	}
};

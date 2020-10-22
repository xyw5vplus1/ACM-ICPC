#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1.0);
const db eps=1e-8;
const db eps1=1e-4;
const int maxn=1e3+10;
const int mod=1e9+7;
int head[maxn];
int num=0;
db px[maxn],py[maxn];
int sz[maxn];
int n,x,y;
db dist(int a,int b)
{
	return sqrt(1.0*(px[a]-px[b])*(px[a]-px[b])+1.0*(py[a]-py[b])*(py[a]-py[b]));
}
struct edge
{
	int to,_next;
}G[2*maxn];
void add(int u,int v)
{
	G[++num].to=v;
	G[num]._next=head[u];
	head[u]=num;
}
void dfs1(int u,int fa)
{
	sz[u]=1;
	for (int i=head[u];i;i=G[i]._next) {
		int v=G[i].to;
		if (v==fa) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int fa,db angL,db angR)
{
	//printf("debug %d %d %.2f %.2f\n",u,fa,angL,angR);
	if (fa!=0) {
		px[u]=px[fa]+cos((angL+angR)/2);
		py[u]=py[fa]+sin((angL+angR)/2);
	}
	if (sz[u]==1) return ;
	db theta=angR-angL;
	db newL=angL-theta/2,newR=angR+theta/2;
	if (!(newR-newL>=0&&newR-newL<=pi)) {
		db mid=(newL+newR)/2;
		newL=mid-pi/2; newR=mid+pi/2;
	}
	int sum=sz[u]-1;
	int cur=0;
	db tot=newR-newL;
	for (int i=head[u];i;i=G[i]._next) {
		int v=G[i].to;
		if (v==fa) continue;
		dfs2(v,u,newL+1.0*cur/sum*tot,newL+1.0*(cur+sz[v])/sum*tot);
		cur+=sz[v];
	}
}
bool check()
{
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (dist(i,j)<=eps1) {
				return false;
			}
	for (int i=1;i<=n;i++)
		for (int j=head[i];j;j=G[j]._next) {
			int v=G[j].to;
			if (abs(dist(i,v)-1)>1e-6) return false;
		}
	return true;
}
int main()
{
	scanf("%d",&n);
	//n=1000;
	//srand(time(NULL));
	for (int i=2;i<=n;i++) {
		scanf("%d%d",&x,&y);
		//x=(i&1)+1;
		add(x,y); add(y,x);
	}
	dfs1(1,0);
	px[1]=0.0; py[1]=0.0;
	dfs2(1,0,0.0,0.75*pi);
	//if (check()) printf("Yes\n");
	//else printf("No\n");
	for (int i=1;i<=n;i++) printf("%.12f %.12f\n",px[i],py[i]);
	return 0;
}

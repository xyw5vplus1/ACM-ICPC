//This amazing code is written by Primo.Jay.Pan From CUC

//Any questions please contact me
//QQ:898021802
//Mail: primojpan@gmail.com
//.    primojaypan@cuc.edu.cn


// Untitled 2.cpp
// Created by Primo Jay Pan on 2020/10/31.
//While (true) RP++;


//head
#include <iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstdio>
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 0x3f3f3f3f
#define maxlongint 2147483647
#define maxint 32767
#define pi(double)acos(-1.0)
#define eps 1e-9
#define MID ((l+r)>>1)
#define lson (o<<1)
#define rson (o<<1|1)
//clear the array
#define cla(a) memset(a,0,sizeof(a))
#define clb(a) memset(a,INF,sizeof(a))
#define clc(a) memset(a,-1,sizeof(a))
#define maxn 200010

struct Edge{
	int to,next,w;
}edges[maxn*2];
int head[maxn];

int cnt[4];
int is[4][maxn];
ll sz[4][maxn];
int b_cnt=0;


using namespace std;



//var

inline void addedge(int u,int v,int w)
{
	edges[++b_cnt].next=head[u];
	edges[b_cnt].to=v;
	edges[b_cnt].w=w;
	head[u]=b_cnt;
}
inline void dfs1(int u,int fa)
{
	for (int i=0;i<3;i++)
		if (is[i][u]) sz[i][u]++;
	for (int i=head[u];i;i=edges[i].next)
	{
		int v=edges[i].to;
		if (v==fa) continue;
		dfs1(v,u);
		for (int i=0;i<3;i++)
			sz[i][u]+=sz[i][v];
	}
}
ll ans1,ans2,ans3;

inline void dfs2(int u,int fa)
{
	for (int i=head[u];i;i=edges[i].next)
	{
		int v=edges[i].to;
		if (v==fa)
			continue;
		int w=edges[i].w;
		ans1+=w*sz[0][v]*(cnt[1]-sz[1][v])+w*sz[1][v]*(cnt[0]-sz[0][v]);
		ans2+=w*sz[1][v]*(cnt[2]-sz[2][v])+w*sz[2][v]*(cnt[1]-sz[1][v]);
		ans3+=w*sz[0][v]*(cnt[2]-sz[2][v])+w*sz[2][v]*(cnt[0]-sz[0][v]);
		dfs2(v,u);
	}
}
//main
int n;
int main()
{
	//freopen("Untitled 2.cpp.in","r",stdin);
	//freopen("Untitled 2.cpp.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n ;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for (int i=0;i<3;i++)
	{
		scanf("%d",&cnt[i]);
		for (int j=1;j<=cnt[i];j++)
		{
			int x;
			scanf("%d",&x);
			is[i][x]=1;
		}
	}
	dfs1(1,0);
	/*for (int i=0;i<3;i++) cout<<sz[i][1]<<" ";
	puts("");
	for (int i=0;i<3;i++) cout<<sz[i][2]<<" ";
	puts("");
	for (int i=0;i<3;i++) 	cout<<sz[i][3]<<" ";
	puts("");*/
    dfs2(1,0);
	double x1=(double)ans1/(double)(1LL*cnt[0]*cnt[1]);
	double x2=(double)ans2/(double)(1LL*cnt[1]*cnt[2]);
	double x3=(double)ans3/(double)(1LL*cnt[0]*cnt[2]);

	double ANS=(double)(x1+x2+x3)/2;
	printf("%.9f\n",ANS);
	return 0;
}



/*
Test Data1:
Test Data2:
*/

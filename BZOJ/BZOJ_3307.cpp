#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
const int maxn=1e5+10;
const int maxm=2e5+10;
const int maxtot=5e6+10;
typedef long long ll;
typedef double db;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
struct edge
{
	int to,_next;
}G[maxm];
int num=0;
int head[maxn],dep[maxn],father[maxn][20],lg[maxn],ans[maxn];
int qx[maxn],qy[maxn],qz[maxn],e[maxn];
int root[maxn],n,m,n0,x,y;
bool vis[maxn];
void add(int u,int v)
{
	G[++num].to=v;
	G[num]._next=head[u];
	head[u]=num;
}
void dfs(int u,int fa)
{
	//printf("dfs %d %d\n",u,fa);
	dep[u]=dep[fa]+1;
	father[u][0]=fa;
	rep(i,1,lg[dep[u]]+1) father[u][i]=father[father[u][i-1]][i-1];
	int v;
	for (int i=head[u];i;i=G[i]._next) {
		v=G[i].to;
		if (v==fa) continue;
		dfs(v,u);
	}
}
void setLg(int n)
{
	lg[0]=-1;
	rep(i,1,n) 
	if (i&(i-1)) lg[i]=lg[i-1];
	else lg[i]=lg[i-1]+1;
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	while (dep[x]>dep[y]) x=father[x][lg[dep[x]-dep[y]]];
	if (x==y) return x;
	per(k,lg[dep[x]],-1) 
	if (father[x][k]!=father[y][k]) {
		x=father[x][k]; y=father[y][k];
	} 
	return father[x][0];
}
struct node
{
	int mx,mxp;
	int lc,rc;
}b[maxtot];
int tot=0;
int build()
{
	int p=++tot;
	b[p].mx=b[p].mxp=0;
	b[p].lc=b[p].rc=0;
	return p;
}
void modify(int p,int l,int r,int pos,int val)
{
	if (l==r) {
		b[p].mx+=val; 
		if (b[p].mx>0) b[p].mxp=pos; 
		return ;
	}
	int mid=(l+r)>>1;
	if (pos<=mid) {
		if (!b[p].lc) b[p].lc=build();
		modify(b[p].lc,l,mid,pos,val);
	}
	else {
		if (!b[p].rc) b[p].rc=build();
		modify(b[p].rc,mid+1,r,pos,val);
	}
	if (b[b[p].lc].mx>=b[b[p].rc].mx) {
		b[p].mx=b[b[p].lc].mx;
		b[p].mxp=b[b[p].lc].mxp;
	}
	else {
		b[p].mx=b[b[p].rc].mx;
		b[p].mxp=b[b[p].rc].mxp;
	}
}
int mergeNode(int p,int q,int l,int r)
{
	if (!p) return q;
	if (!q) return p;
	if (l==r) {
		b[p].mx+=b[q].mx;
		if (b[p].mx>0) b[p].mxp=l;
		return p;
	}
	int mid=(l+r)>>1;
	b[p].lc=mergeNode(b[p].lc,b[q].lc,l,mid);
	b[p].rc=mergeNode(b[p].rc,b[q].rc,mid+1,r);
	if (b[b[p].lc].mx>=b[b[p].rc].mx) {
		b[p].mx=b[b[p].lc].mx; b[p].mxp=b[b[p].lc].mxp;
	}
	else {
		b[p].mx=b[b[p].rc].mx; b[p].mxp=b[b[p].rc].mxp;
	}
	return p;
}
void dfs(int u)
{
	vis[u]=true;
	int v;
	for (int i=head[u];i;i=G[i]._next) {
		v=G[i].to;
		if (vis[v]) continue;
		dfs(v);
		root[u]=mergeNode(root[u],root[v],1,n0);
	}
	ans[u]=b[root[u]].mxp;
}
int main()
{
	setLg(maxn);
	//rep(i,1,20) printf("lg[%d]=%d\n",i,lg[i]);
	//scanf("%d%d",&n,&m);
	n=read(); m=read();
	rep(i,0,n-1) {
		//scanf("%d%d",&x,&y);
		x=read(); y=read();
		add(x,y); add(y,x);
	}
	dfs(1,0);
	rep(i,1,n+1) root[i]=build();
	rep(i,1,m+1) {
		//scanf("%d%d%d",&qx[i],&qy[i],&qz[i]);
		qx[i]=read(); qy[i]=read(); qz[i]=read();
		e[i]=qz[i];
	}
	sort(e+1,e+m+1);
	n0=unique(e+1,e+m+1)-(e+1);
	rep(i,1,m+1) qz[i]=lower_bound(e+1,e+n0+1,qz[i])-e;
	int t;
	rep(i,1,m+1) {
		t=lca(qx[i],qy[i]);
		modify(root[qx[i]],1,n0,qz[i],1); modify(root[qy[i]],1,n0,qz[i],1);
		modify(root[t],1,n0,qz[i],-1); 
		if (father[t][0]!=0) modify(root[father[t][0]],1,n0,qz[i],-1);
	}
	dfs(1);
	rep(i,1,n+1) printf("%d\n",e[ans[i]]);
	return 0;
}
/*
4 3
1 2
2 3
2 4
1 4 1
2 2 2
2 3 2
*/

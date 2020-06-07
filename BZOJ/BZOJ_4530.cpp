#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+10;
const int maxtot=2e6+10;
int father[maxn],dep[maxn],in[maxn],out[maxn],root[maxn];
bool vis[maxn];
int n,q;
char s[10];
struct query
{
	int op,x,y;
}a[maxn];
struct edge
{
	int to,_next;
}G[2*maxn];
int head[maxn],num=0,tim=0;
void add(int u,int v)
{
	G[++num].to=v;
	G[num]._next=head[u];
	head[u]=num;
}
struct node
{
	int lc,rc;
	int cnt;
}b[maxtot];
int tot=0;
int build()
{
	int p=++tot;
	b[p].lc=b[p].rc=b[p].cnt=0;
	return p;
}
void pushup(int p)
{
	b[p].cnt=b[b[p].lc].cnt+b[b[p].rc].cnt;
}
void modify(int p,int l,int r,int pos,int val)
{
	if (l==r) {
		b[p].cnt+=val;
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
	pushup(p);
}
int getCnt(int p,int l,int r,int L,int R)
{
	if (L>R) return 0;
	if (!p) return 0;
	if (L<=l&&r<=R) return b[p].cnt;
	int mid=(l+r)>>1;
	int ans=0;
	if (L<=mid) ans+=getCnt(b[p].lc,l,mid,L,R);
	if (R>mid) ans+=getCnt(b[p].rc,mid+1,r,L,R);
	return ans;
}
int mergeNode(int p,int q,int l,int r)
{
	if (!p) return q;
	if (!q) return p;
	if (l==r) {
		b[p].cnt+=b[q].cnt;
		return p;
	}
	int mid=(l+r)>>1;
	b[p].lc=mergeNode(b[p].lc,b[q].lc,l,mid);
	b[p].rc=mergeNode(b[p].rc,b[q].rc,mid+1,r);
	pushup(p);
	return p;
}
void dfs(int u,int fa)
{
	vis[u]=true;
	in[u]=++tim;
	dep[u]=dep[fa]+1;
	int v;
	for (int i=head[u];i;i=G[i]._next) {
		v=G[i].to;
		if (vis[v]) continue;
		dfs(v,u);
	}
	out[u]=tim;
}
int findRoot(int x)
{
	return x==father[x]?x:father[x]=findRoot(father[x]);
}
void setMerge(int u,int v)
{
	u=findRoot(u); v=findRoot(v);
	if (u==v) return ;
	father[u]=v;
	root[v]=mergeNode(root[u],root[v],1,n);
}
int main()
{
	scanf("%d%d",&n,&q);
	rep(i,1,q+1) {
		scanf("%s",s);
		scanf("%d%d",&a[i].x,&a[i].y);
		if (s[0]=='A') {
			a[i].op=0;
			add(a[i].x,a[i].y); add(a[i].y,a[i].x);
		}
		else {
			a[i].op=1;
		}
	}
	rep(i,1,n+1) 
	if (!vis[i]) dfs(i,0);
	rep(i,1,n+1) {
		father[i]=i; root[i]=build(); modify(root[i],1,n,in[i],1);
	}
	int u,v,sz;
	rep(i,1,q+1) {
		if (a[i].op==0) {
			if (dep[a[i].x]<dep[a[i].y]) swap(a[i].x,a[i].y);
			setMerge(a[i].x,a[i].y);
			//printf("%d\n",b[root[a[i].y]].cnt);
		}
		else {
			if (dep[a[i].x]<dep[a[i].y]) swap(a[i].x,a[i].y);
			u=findRoot(a[i].y); sz=b[root[u]].cnt;
			v=getCnt(root[u],1,n,in[a[i].x],out[a[i].x]);
			//printf("debug %d %d\n",sz,v);
			printf("%lld\n",1LL*v*(sz-v));
		}
	}
	return 0;
}

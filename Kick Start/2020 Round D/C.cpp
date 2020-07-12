#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=5e5+10;
const int maxtot=1e7+10;
int num=0,tot=0;
int head[maxn];
int dep[maxn],p1[maxn],p2[maxn],pro[maxn],root[maxn];
int T;
struct edge
{
	int to,_next;
}G[maxn];
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
int build()
{
	int p=++tot;
	b[p].lc=b[p].rc=0;
	b[p].cnt=0;
	return p;
}
void modify(int p,int l,int r,int pos,int val)
{
	//printf("debug %d %d %d %d %d\n",p,l,r,pos,val);
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
}
int getNum(int p,int l,int r,int pos)
{
	if (l==r) return b[p].cnt;
	int mid=(l+r)>>1;
	if (pos<=mid) return getNum(b[p].lc,l,mid,pos);
	else return getNum(b[p].rc,mid+1,r,pos);
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
	return p;
}
void dfs(int u,int fa,int mod)
{
	//printf("dfs %d %d\n",u,fa);
	dep[u]=dep[fa]+1;
	for (int i=head[u];i;i=G[i]._next) {
		int v=G[i].to;
		dfs(v,u,mod);
		root[u]=mergeNode(root[u],root[v],0,mod-1);
	}
	modify(root[u],0,mod-1,dep[u]%mod,1);
	pro[u]=getNum(root[u],0,mod-1,dep[u]%mod);
}
int n,a0,b0,x;
int main()
{
	scanf("%d",&T);
	//T=100;
	for (int kase=1;kase<=T;kase++) {
		scanf("%d%d%d",&n,&a0,&b0);
		//n=5e5; a0=5e5; b0=5e5;
		num=0; tot=0;
		memset(head,0,sizeof(head));
		for (int i=2;i<=n;i++) {
			scanf("%d",&x);
			add(x,i);
		}
		for (int i=1;i<=n;i++) root[i]=build();
		dfs(1,0,a0);
		for (int i=1;i<=n;i++) p1[i]=pro[i];
		tot=0;
		for (int i=1;i<=n;i++) root[i]=build();
		dfs(1,0,b0);
		for (int i=1;i<=n;i++) p2[i]=pro[i];
		double ans=0;
		for (int i=1;i<=n;i++) {
			/*if (i==1) {
				ans+=1; continue;
			}*/
			double pro1=1.0*p1[i]/n,pro2=1.0*p2[i]/n;
			ans+=pro1+pro2-pro1*pro2;
		}
		printf("Case #%d: %.12f\n",kase,ans);
	}
	return 0;
}

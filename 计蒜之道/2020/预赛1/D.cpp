#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=3e5+10;
const ll INF=1e18;
int a0[maxn],a1[maxn];
ll sum0[maxn],sum1[maxn];
ll f[maxn];
int n,m;
struct seg
{
	int l,r,t,c;
}e[maxn];
std::vector<int> v[maxn];
struct node
{
	ll mx[2];
	ll add[2];
}b[4*maxn];
void pushup(int p)
{
	b[p].mx[0]=max(b[lson(p)].mx[0],b[rson(p)].mx[0]);
	b[p].mx[1]=max(b[lson(p)].mx[1],b[rson(p)].mx[1]);
}
void build(int p,int l,int r)
{
	b[p].add[0]=b[p].add[1]=0;
	if (l==r) {
		b[p].mx[0]=b[p].mx[1]=-INF;
		return ;
	}
	int mid=(l+r)>>1;
	build(lson(p),l,mid);
	build(rson(p),mid+1,r);
	pushup(p);
}
void pushdown(int p)
{
	if (b[p].add[0]) {
		b[lson(p)].mx[0]+=b[p].add[0]; b[lson(p)].add[0]+=b[p].add[0];
		b[rson(p)].mx[0]+=b[p].add[0]; b[rson(p)].add[0]+=b[p].add[0];
		b[p].add[0]=0;
	}
	if (b[p].add[1]) {
		b[lson(p)].mx[1]+=b[p].add[1]; b[lson(p)].add[1]+=b[p].add[1];
		b[rson(p)].mx[1]+=b[p].add[1]; b[rson(p)].add[1]+=b[p].add[1];
		b[p].add[1]=0;
	}
}
void modify(int p,int l,int r,int pos,int op,ll val)
{
	if (l==r) {
		b[p].mx[op]=val; return ;
	}
	int mid=(l+r)>>1;
	pushdown(p);
	if (pos<=mid) modify(lson(p),l,mid,pos,op,val);
	else modify(rson(p),mid+1,r,pos,op,val);
	pushup(p);
}
ll getMx(int p,int l,int r,int L,int R,int op)
{
	if (L<=l&&r<=R) return b[p].mx[op];
	int mid=(l+r)>>1;
	ll ans=-INF;
	pushdown(p);
	if (L<=mid) ans=max(ans,getMx(lson(p),l,mid,L,R,op));
	if (R>mid) ans=max(ans,getMx(rson(p),mid+1,r,L,R,op));
	return ans;
}
void modifySeg(int p,int l,int r,int L,int R,int op,ll val)
{
	if (L<=l&&r<=R) {
		b[p].mx[op]+=val; b[p].add[op]+=val;
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(p);
	if (L<=mid) modifySeg(lson(p),l,mid,L,R,op,val);
	if (R>mid) modifySeg(rson(p),mid+1,r,L,R,op,val);
	pushup(p);
}
void dfs(int p,int l,int r)
{
	printf("dfs %d %d %d %I64d %I64d %I64d %I64d\n",p,l,r,b[p].mx[0],b[p].mx[1],b[p].add[0],b[p].add[1]);
	if (l==r) return ;
	int mid=(l+r)>>1;
	dfs(lson(p),l,mid);
	dfs(rson(p),mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a0[i]);
	sum0[0]=0;
	for (int i=1;i<=n;i++) sum0[i]=sum0[i-1]+a0[i];
	for (int i=1;i<=n;i++) scanf("%d",&a1[i]);
	sum1[0]=0;
	for (int i=1;i<=n;i++) sum1[i]=sum1[i-1]+a1[i];
	for (int i=1;i<=m;i++) {
		scanf("%d%d%d%d",&e[i].t,&e[i].l,&e[i].r,&e[i].c); 
		v[e[i].r].pb(i);
	}
	build(1,0,n);
	modify(1,0,n,0,0,0); modify(1,0,n,0,1,0);
	int x;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<(int)v[i].size();j++) {
			x=v[i][j];	
			if (e[x].t==1) {
				modifySeg(1,0,n,0,e[x].l-1,e[x].t-1,e[x].c);
			}
			else {
				//printf("modifySeg %d %d %d\n",0,e[x].l-1,e[x].c);
				modifySeg(1,0,n,0,e[x].l-1,e[x].t-1,e[x].c);
			}
		}
		//dfs(1,0,n);
		ll ans1=getMx(1,0,n,0,i-1,0)+sum0[i];
		ll ans2=getMx(1,0,n,0,i-1,1)+sum1[i];
		//printf("debug %d %I64d %I64d\n",i,ans1,ans2);
		if (ans1>=ans2) f[i]=ans1;
		else f[i]=ans2;
		modify(1,0,n,i,0,f[i]-sum0[i]); modify(1,0,n,i,1,f[i]-sum1[i]);
	}
	printf("%lld\n",f[n]);
	//for (int i=1;i<=n;i++) printf("debug %d %I64d\n",i,f[i]);
	return 0;
}

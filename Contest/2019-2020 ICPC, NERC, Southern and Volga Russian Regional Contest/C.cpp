#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
std::vector<pair<int,ll> > v[maxn];
std::vector<int> ans;
int n;
ll m;
int l,r; 
ll d;
int pl[maxn],pr[maxn];
ll pd[maxn];
struct node
{
	ll sum,rmx;
	int rmxpos;
}b[4*maxn];
void pushup(int p)
{
	b[p].sum=b[lson(p)].sum+b[rson(p)].sum;
	if (b[lson(p)].rmx+b[rson(p)].sum>b[rson(p)].rmx) {
		b[p].rmx=b[lson(p)].rmx+b[rson(p)].sum;
		b[p].rmxpos=b[lson(p)].rmxpos;
	}
	else {
		b[p].rmx=b[rson(p)].rmx;
		b[p].rmxpos=b[rson(p)].rmxpos;
	}
}
void modify(int p,int l,int r,int pos,ll val)
{
	if (l==r) {
		b[p].sum+=val; b[p].rmx+=val; b[p].rmxpos=pos;
		return ;
	}
	int mid=(l+r)>>1;
	if (pos<=mid) modify(lson(p),l,mid,pos,val);
	else modify(rson(p),mid+1,r,pos,val);
	pushup(p);
}
node getMx(int p,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return b[p];
	int mid=(l+r)>>1;
	if (R<=mid) return getMx(lson(p),l,mid,L,R);
	else if (L>mid) return getMx(rson(p),mid+1,r,L,R);
	else {
		node e1=getMx(lson(p),l,mid,L,R);
		node e2=getMx(rson(p),mid+1,r,L,R);
		node e;
		e.sum=e1.sum+e2.sum;
		if (e1.rmx+e2.sum>e2.rmx) {
			e.rmx=e1.rmx+e2.sum;
			e.rmxpos=e1.rmxpos;
		}
		else {
			e.rmx=e2.rmx;
			e.rmxpos=e2.rmxpos;
		}
		return e;
	}
}
void build(int p,int l,int r)
{
	if (l==r) {
		b[p].rmx=b[p].sum=0;
		b[p].rmxpos=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(lson(p),l,mid);
	build(rson(p),mid+1,r);
	pushup(p);
}
int main()
{
	scanf("%d%I64d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d%d%I64d",&l,&r,&d);
		pl[i]=l; pr[i]=r; pd[i]=d;
		v[r].push_back(make_pair(l,d));
	}
	build(1,1,maxn);
	ll mxpro=0;
	int ansL,ansR;
	for (int i=1;i<maxn;i++) {
		for (int j=0;j<(int)v[i].size();j++) {
			int pos=v[i][j].first;ll val=v[i][j].second;
			modify(1,1,maxn,pos,val);
		}
		modify(1,1,maxn,i,-m);
		node e=getMx(1,1,maxn,1,i);
		if (e.rmx>mxpro) {
			mxpro=e.rmx; ansL=e.rmxpos; ansR=i;
		}
	}
	if (mxpro!=0) {
		printf("%I64d %d %d ",mxpro,ansL,ansR);
		for (int i=1;i<=n;i++)
			if (pl[i]>=ansL&&pr[i]<=ansR) ans.push_back(i);
		printf("%d\n",ans.size());
		for (int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
	}
	else printf("0\n");
	return 0;
}
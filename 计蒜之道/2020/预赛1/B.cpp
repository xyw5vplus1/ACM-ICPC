#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const ll INF=1e18;
const int maxn=3e5+10;
int n,m;
int a[maxn],b[maxn];
ll suma[maxn],sumb[maxn];
int bo[maxn];
ll dp[maxn];
struct seg
{
	int l,r,t;
	int c;
}e[maxn];
bool cmp(seg a,seg b)
{
	return a.l<b.l;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	suma[0]=0; sumb[0]=0;
	for (int i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
	for (int i=1;i<=n;i++) sumb[i]=sumb[i-1]+b[i];
	for (int i=1;i<=m;i++) scanf("%d%d%d%d",&e[i].t,&e[i].l,&e[i].r,&e[i].c);
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++) 
		for (int j=e[i].l;j<=e[i].r;j++) bo[j]=i;
	ll ans=0;
	int cur=1;
	while (cur<=n) {
		if (bo[cur]) {
			int x=bo[cur];
			ll tem0=0;
			for (int i=e[x].l;i<=e[x].r;i++)
				tem0+=max(a[i],b[i]);
			ll tem1=0;
			if (e[x].t==1) tem1=suma[e[x].r]-suma[e[x].l-1]+e[x].c;
			else tem1=sumb[e[x].r]-sumb[e[x].l-1]+e[x].c;
			ans+=max(tem0,tem1);
			cur=e[x].r+1;
		}
		else {
			ans+=max(a[cur],b[cur]);
			cur++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

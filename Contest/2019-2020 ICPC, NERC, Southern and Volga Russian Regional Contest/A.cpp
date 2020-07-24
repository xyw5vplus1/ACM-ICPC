#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=5e5+10;
int n,m;
int a[maxn],pos[maxn],fp[maxn],mn[maxn],mx[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) {
		pos[i]=i; fp[i]=i; mx[i]=i; mn[i]=i;
	}
	//pos[i] i在哪一位 fp[i] 第i位是什么
	int pre,p;
	for (int i=1;i<=m;i++) {
		if (pos[a[i]]==1) continue;
		p=pos[a[i]];
		pre=fp[p-1];
		pos[pre]=p; pos[a[i]]=p-1;
		fp[p-1]=a[i]; fp[p]=pre;
		mx[a[i]]=max(mx[a[i]],pos[a[i]]);
		mn[a[i]]=min(mn[a[i]],pos[a[i]]);
		mx[pre]=max(mx[pre],pos[pre]);
		mn[pre]=min(mn[pre],pos[pre]);
	}
	for (int i=1;i<=n;i++) printf("%d %d\n",mn[i],mx[i]);
	return 0;
}
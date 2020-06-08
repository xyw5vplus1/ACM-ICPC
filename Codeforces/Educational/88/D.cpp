#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
int a[maxn],l[maxn],r[maxn];
int sum[maxn];
int s[maxn];
int n;
int lg[maxn];
int dp1[maxn][20],dp2[maxn][20];
int rmqMx(int l,int r)
{
	if (l>r) return -INF;
	int k=lg[r-l+1];
	return max(dp1[l][k],dp1[r-(1<<k)+1][k]);
}
int rmqMn(int l,int r)
{
	if (l>r) return INF;
	int k=lg[r-l+1];
	return min(dp2[l][k],dp2[r-(1<<k)+1][k]);
}
int main()
{
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	rep(i,1,n+1) {
		sum[i]=sum[i-1]+a[i];
	}
	int h=0;
	rep(i,1,n+1) {
		while (h>0&&a[s[h-1]]<a[i]) {
			r[s[h-1]]=i-1;
			h--;
		}
		s[h++]=i;
	}
	while (h>0) {
		r[s[h-1]]=n; h--;
	}
	per(i,n,0) {
		while (h>0&&a[s[h-1]]<a[i]) {
			l[s[h-1]]=i+1;
			h--;
		} 
		s[h++]=i;
	}
	while (h>0) {
		l[s[h-1]]=1; h--;
	}
	lg[0]=-1;
	rep(i,1,n+2) 
	if (i&(i-1)) lg[i]=lg[i-1];
	else lg[i]=lg[i-1]+1;
	rep(i,0,n+1) {
		dp1[i][0]=sum[i]; dp2[i][0]=sum[i];
	}
	rep(j,1,lg[n+1]+1) 
		for (int i=0;i+(1<<j)-1<=n;i++) {
			dp1[i][j]=max(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
			dp2[i][j]=min(dp2[i][j-1],dp2[i+(1<<(j-1))][j-1]);
		}
	int ans=0;
	rep(i,1,n+1) {
		int p1=rmqMx(i+1,r[i]);
		if (p1-sum[i]>0) p1=p1-sum[i];
		else p1=0;
		int p2=rmqMn(l[i]-1,i-2);
		if (sum[i-1]-p2>0) p2=sum[i-1]-p2;
		else p2=0;
		ans=max(ans,p1+p2);
		//printf("%d %d %d\n",i,p1,p2);
	}
	printf("%d\n",ans);
	return 0;
}
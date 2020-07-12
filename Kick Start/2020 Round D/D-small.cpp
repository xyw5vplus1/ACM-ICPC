#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
int T,n,q,pos,k;
int a[maxn];
int getAns(int pos,int k)
{
	int l=pos,r=pos,last=pos; k--;
	//printf("debug %d",last);
	while (k--) {
		if (l==1) {
			r++; last=r;
		}
		else if (r==n) {
			l--; last=l;
		}
		else if (a[l-1]<a[r]) {
			l--; last=l;
		}
		else {
			r++; last=r;
		}
		//printf(" %d",last);
	}
	//printf("\n");
	return last;
}
int main()
{
	scanf("%d",&T);
	for (int kase=1;kase<=T;kase++) {
		scanf("%d%d",&n,&q);
		for (int i=1;i<n;i++) {
			scanf("%d",&a[i]);
		}
		printf("Case #%d:",kase);
		while (q--) {
			scanf("%d%d",&pos,&k);
			printf(" %d",getAns(pos,k));
		}
		printf("\n");
	}
	return 0;
}

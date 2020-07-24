#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
int T,a,b,c;
bool check(int k)
{
	int cnt=0;
	int a0=a,b0=b,c0=c;
	cnt+=(a0/k)+(a0%k!=0);
	cnt+=(c0/k)+(c0%k!=0);
	if (a0%k!=0) b0-=(k-a0%k);
	if (c0%k!=0) b0-=(k-c0%k);
	if (b0>=0) cnt+=(b0/k)+(b0%k!=0);
	//if (k==5) printf("debug %d\n",cnt);
	return cnt<=3;
}
int main()
{
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&a,&b,&c);
		int l=1,r=1000;
		while (l<r) {
			int mid=(l+r)>>1;
			if (check(mid)) r=mid;
			else l=mid+1;
		}
		//printf("debug %d\n",check(5));
		printf("%d\n",l);
	}
	return 0;
}
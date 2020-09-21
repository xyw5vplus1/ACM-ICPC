#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int T;
int n;
ll x,y;
int b[maxn],a0[maxn],b0[maxn];
std::vector<int> v[maxn];
int main()
{
	//scanf("%d",&T);
	T=1000;
	srand(time(NULL));
	while (T--) {
		n=200;
		for (int i=1;i<=n;i++) a0[i]=rand()%100+1;
		for (int i=1;i<=n;i++) b0[i]=a0[i];
		int p1=rand()%n+1,p2=rand()%n+1;
		while (p1==p2) {
			p1=rand()%n+1,p2=rand()%n+1;
		}
		swap(b0[p1],b0[p2]);
		x=0; y=0;
		for (int i=1;i<=n;i++) {
			x=(x+1LL*i*a0[i]);
			y=(y+1LL*i*a0[i]*a0[i]);
		}
		//scanf("%d%I64d%I64d",&n,&x,&y);
		for (int i=1;i<=n;i++){
			//scanf("%d",&b[i]);
			b[i]=b0[i];
		}
		ll x0=0,y0=0;
		for (int i=1;i<=n;i++) {
			x0=(x0+1LL*i*b[i]);
			y0=(y0+1LL*i*b[i]*b[i]);
		}
		ll dx=-(x-x0),dy=-(y-y0);
		//printf("debug %lld %lld\n",dx,dy);
		ll cnt=0;
		if (dx) { 
			if (dy%dx) {
				cnt=0;
				printf("0\n");
			}
			else {
				ll d=dy/dx;
				//printf("debug %lld\n",d);
				ll p;
				for (int j=1;j<=n;j++) {
					if (d-2*b[j]==0) continue;
					if (dx%(d-2*b[j])) continue;
					p=dx/(d-2*b[j]);
					//printf("%d need p=%lld %lld %lld %d\n",j,p,j+p,ai,a[j+p]);
					if (j+p>=1&&j+p<j&&b[j+p]==d-b[j]) cnt++;   
				}
				printf("%I64d\n",cnt);
			}
		}
		else {
			if (dy) {
				printf("0\n");
				cnt=0;
			}
			else {
				for (int i=1;i<=n;i++) v[b[i]].clear();
				for (int i=1;i<=n;i++) {
					cnt+=v[b[i]].size();
					v[b[i]].push_back(i);
				}
				printf("%I64d\n",cnt);
			}
		}
		ll cnt1=0;
		for (int i=1;i<=n;i++) {
			for (int j=i+1;j<=n;j++) {
				swap(b[i],b[j]);
				ll x1=0,y1=0;
				for (int p=1;p<=n;p++) {
					x1=(x1+1LL*p*b[p]);
					y1=(y1+1LL*p*b[p]*b[p]);
				}
				if (x1==x&&y1==y) cnt1++;

				swap(b[i],b[j]);
			}
		}
		printf("debug %I64d\n",cnt1);
		if (cnt!=cnt1) {
			printf("%d %lld %lld\n",n,x,y);
			for (int i=1;i<=n;i++) printf("%d ",b[i]); printf("\n");
			break;
		}
	}
	return 0;
}
/*
100 28525 198785
7 10 4 7 9 5 5 9 2 1 1 5 3 3 3 4 3 6 7 10 1 1 7 2 10 9 2 6 2 3 8 2 6 3 6 10 8 10 3 9 8 4 10 10 9 5 9 2 9 9 5 1 3 7 7 7 9 7 4 6 1 10 3 3 2 7 5 6 5 3 4 5 8 6 9 2 7 8 2 1 3 2 3 2 6 5 10 4 8 7 6 6 3 7 8 5 10 4 10 7

*/
/*
10 244 1438
10 8 10 3 8 3 2 6 4 2
*/
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int T;
int n;
ll x,y;
int b[maxn];
std::vector<int> v[maxn];
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d%lld%lld",&n,&x,&y);
		for (int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		ll x0=0,y0=0;
		for (int i=1;i<=n;i++) {
			x0=(x0+1LL*i*b[i]);
			y0=(y0+1LL*i*b[i]*b[i]);
		}
		ll dx=-(x-x0),dy=-(y-y0);
		//printf("debug %lld %lld\n",dx,dy);
		ll cnt=0;
		if (dx) { 
			if (dy%dx) printf("0\n");
			else {
				ll d=dy/dx;
				//printf("debug %lld\n",d);
				ll p;
				for (int j=1;j<=n;j++) {
					if (d-2*b[j]==0) continue;
					if (dx%(d-2*b[j])) continue;
					p=dx/(d-2*b[j]);
					//printf("%d need p=%lld %lld %lld %d\n",j,p,j+p,ai,a[j+p]);
					if (j+p>=1&&j+p<j&&b[j+p]==d-b[j]) cnt++;   
				}
				printf("%lld\n",cnt);
			}
		}
		else {
			if (dy) printf("0\n");
			else {
				for (int i=1;i<=n;i++) v[b[i]].clear();
				for (int i=1;i<=n;i++) {
					cnt+=v[b[i]].size();
					v[b[i]].push_back(i);
				}
				printf("%lld\n",cnt);
			}
		}
	}
	return 0;
}*/
/*
1
10 244 1438
10 8 10 3 8 3 2 6 4 2
*/
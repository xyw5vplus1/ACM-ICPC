#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long ll;
typedef double db;
int T;
int a[15];
int main()
{
	scanf("%d",&T);
	while (T--) {
		int mn=INF;
		for (int i=0;i<=9;i++) scanf("%d",&a[i]);
		for (int i=1;i<=9;i++) mn=min(mn,a[i]);
		mn=min(mn,a[0]+1);
		int len=mn+1;
		if (a[0]<len-1) {
			printf("1");
			for (int i=1;i<=len-1;i++) printf("0"); printf("\n");
		}
		else {
			int k=-1;
			for (int i=1;i<=9;i++)
				if (a[i]==mn) {
					k=i; break;
				} 
			for (int i=1;i<=len;i++) printf("%d",k);
			printf("\n");
		}
	}
	return 0;
}
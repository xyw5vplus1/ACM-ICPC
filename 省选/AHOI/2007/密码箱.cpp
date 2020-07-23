#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
set<int> s;
int n;
int main()
{
	scanf("%d",&n);
	if (n==1) {
		printf("None\n");
		return 0;
	}
	for (ll i=1;i*i<=n;i++) 
		if (n%i==0) {
			for (ll j=(n/i)-1;j<n;j+=(n/i)) 
				if ((j-1)%i==0) s.insert(j);
		}
	for (ll i=1;1LL*i*i<=n;i++) 
		if (n%i==0) {
			for (ll j=1;j<n;j+=(n/i)) 
				if ((j+1)%i==0) s.insert(j);
		}
	if (!s.size()) printf("None\n");
	else for (set<int>::iterator iter=s.begin();iter!=s.end();iter++) printf("%d\n",(*iter)); 
	return 0;
}

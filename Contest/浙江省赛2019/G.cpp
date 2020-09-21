#include<bits/stdc++.h>
using namespace std;
int T,n;
bool check(int x)
{
	if (x%7) return false;
	if (x%4==0) return false;
	return true;
}
int main()
{
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		while (!check(n)) {
			n++;
		}
		printf("%d\n",n);
	}
	return 0;
}
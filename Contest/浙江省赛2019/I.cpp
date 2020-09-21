#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int pw[maxn];
char s1[maxn],s2[maxn];
int T;
int main()
{
	scanf("%d",&T);
	pw[0]=1;
	for (int i=1;i<maxn;i++) pw[i]=pw[i-1]*10%3;
	while (T--) {
		scanf("%s",s1);
		scanf("%s",s2);
		int len1=strlen(s1);
		int len2=strlen(s2);
		int r1=0,r2=0;
		for (int i=0;i<len1;i++) {
			r1=(r1+(s1[i]-'0')*pw[len1-1-i])%3;
		}
		for (int i=0;i<len2;i++) {
			r2=(r2+(s2[i]-'0')*pw[len2-1-i])%3;
		}
		r2=(r2+2)%3; r1=(r1+1)%3;
		if (r1==2) r1=1;
		if (r2==2) r2=1;
		if (r1!=r2) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
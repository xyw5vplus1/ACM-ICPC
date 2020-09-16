#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
char s[30][30];
bool check0()
{
	for (int i=1;i<=25;i++)
		for (int j=1;j<=25;j++) 
			if (s[i][j]=='x') {
				int x=i,y=j;
				while (x<=25&&s[x][y]=='x') x++;
				if (x-i>=5) return true;
				x=i; y=j;
				while (y<=25&&s[x][y]=='x') y++;
				if (y-j>=5) return true;
				x=i; y=j;
				while (x<=25&&y<=25&&s[x][y]=='x') {
					x++; y++;
				}
				if (x-i>=5) return true;
				x=i; y=j;
				while (x<=25&&y>=1&&s[x][y]=='x') {
					x++; y--;
				}
				if (x-i>=5) return true;
			}
	return false;
}
bool check1()
{
	for (int i=1;i<=25;i++)
		for (int j=1;j<=25;j++) 
			if (s[i][j]=='o') {
				int x=i,y=j;
				while (x<=25&&s[x][y]=='o') x++;
				if (x-i>=5) return true;
				x=i; y=j;
				while (y<=25&&s[x][y]=='o') y++;
				if (y-j>=5) return true;
				x=i; y=j;
				while (x<=25&&y<=25&&s[x][y]=='o') {
					x++; y++;
				}
				if (x-i>=5) return true;
				x=i; y=j;
				while (x<=25&&y>=1&&s[x][y]=='o') {
					x++; y--;
				}
				if (x-i>=5) return true;
			}
	return false;
}
int main()
{
	for (int i=1;i<=25;i++) scanf("%s",s[i]+1);
	int num0=0,num1=0;
	for (int i=1;i<=25;i++)
		for (int j=1;j<=25;j++)
			if (s[i][j]=='x') num0++;
			else if (s[i][j]=='o') num1++;
	bool bo=false;
	if (num1==num0) {
		for (int i=1;i<=25;i++)
			for (int j=1;j<=25;j++)
				if (s[i][j]=='.') {
					s[i][j]='x';
					if (check0()) {
						printf("%d %d\n",i-1,j-1); bo=true;
					}
					s[i][j]='.';
				}
	}
	else {
		for (int i=1;i<=25;i++)
			for (int j=1;j<=25;j++) 
				if (s[i][j]=='.') {
					s[i][j]='o';
					if (check1()) {
						printf("%d %d\n",i-1,j-1); bo=true;
					}
					s[i][j]='.';
				}
	}
	if (!bo) printf("tie\n");
	return 0;
}

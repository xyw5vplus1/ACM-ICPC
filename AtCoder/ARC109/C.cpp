#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxn=100+10;
typedef long long ll;
typedef double db;
char s[maxn];
char dp[maxn][maxn];
int n,k;
map<char,int> mp;
int pw[maxn];
char Fight(char cx,char cy)
{
    int x=mp[cx],y=mp[cy];
    if (x==y) return cx;
    if (x<y) {
        if (x==1&&y==3) return cy;
        return cx;
    }
    if (y<x) {
        if (y==1&&x==3) return cx;
        return cy;
    }
}
int main()
{
    mp['R']=1; mp['S']=2; mp['P']=3;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    pw[0]=1;
    for (int i=1;i<=n;i++) pw[i]=pw[i-1]*2%n;
    for (int i=0;i<n;i++) dp[i][0]=s[i];
    for (int j=1;j<=k;j++) {
        for (int i=0;i<n;i++) {
            dp[i][j]=Fight(dp[i][j-1],dp[(i+pw[j-1])%n][j-1]);
        }
    }
    printf("%c\n",dp[0][k]);
    return 0;
}


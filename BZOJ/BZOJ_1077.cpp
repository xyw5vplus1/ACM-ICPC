#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
const int maxn=100;
const int INF=0x3f3f3f3f;
typedef double db;
int d1[maxn][maxn],d2[maxn][maxn];
char s[maxn][maxn];
int n,x,y;
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    rep(i,1,n+1) scanf("%s",s[i]+1);
    rep(i,1,n+1)
        rep(j,1,n+1)
            if (i!=j) {
                d1[i][j]=-2,d2[i][j]=2;
            }
    rep(i,1,n+1)
        rep(j,1,n+1)
        if (s[i][j]=='+') d1[i][j]=1;
        else if (s[i][j]=='-') d2[i][j]=-1;
        else if (s[i][j]=='=') d1[i][j]=d2[i][j]=0;
    rep(k,1,n+1)
        rep(i,1,n+1)
        rep(j,1,n+1) {
            if (d1[i][k]+d1[k][j]>d1[i][j]) d1[i][j]=d1[i][k]+d1[k][j];
            if (d2[i][k]+d2[k][j]<d2[i][j]) d2[i][j]=d2[i][k]+d2[k][j];
        }
    int ans1=0,ans2=0,ans3=0;
    rep(i,1,n+1)
        rep(j,i+1,n+1) {
            if (i==x||i==y) continue;
            if (j==x||j==y) continue;
            if (d1[i][x]>d2[y][j]||d1[i][y]>d2[x][j]) ans3++;
            else if (d1[i][x]==d2[i][x]&&d2[i][x]==d1[y][j]&&d1[y][j]==d2[y][j]) ans2++;
            else if (d1[i][y]==d2[i][y]&&d2[i][y]==d1[x][j]&&d1[x][j]==d2[x][j]) ans2++;
            else if (d2[i][x]<d1[y][j]||d2[i][y]<d1[x][j]) ans1++;
        }
    printf("%d %d %d\n",ans1,ans2,ans3);
    return 0;
}

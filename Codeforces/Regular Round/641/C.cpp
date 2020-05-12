#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e3+10;
const int mod=1e9+7;
int t[maxn][maxn];
char s[maxn][maxn];
int n,m,T;
bool vis[maxn][maxn];
int a[maxn][maxn];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int x,y;
int quick_pow(int a,int b)
{
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans%mod;
}
int gcd(int n,int m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
int main()
{
    scanf("%d%d%d",&n,&m,&T);
    for (int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) {
        if (i>1&&s[i][j]==s[i-1][j]) a[i][j]=1;
        if (j>1&&s[i][j]==s[i][j-1]) a[i][j]=1;
        if (i<n&&s[i][j]==s[i+1][j]) a[i][j]=1;
        if (j<m&&s[i][j]==s[i][j+1]) a[i][j]=1;
    }
    queue<pair<int,int>> q;
    memset(t,-1,sizeof(t));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if (a[i][j]==1) {
            q.push(make_pair(i,j));
            t[i][j]=1; vis[i][j]=true;
        }
    while (q.size()) {
        pair<int,int> e=q.front(); q.pop();
        int x=e.first,y=e.second;
        for (int i=0;i<4;i++) {
            int x0=x+dx[i],y0=y+dy[i];
            if (x0>=1&&x0<=n&&y0>=1&&y0<=m&&!vis[x0][y0]) {
                vis[x0][y0]=true; t[x0][y0]=t[x][y]+1; q.push(make_pair(x0,y0));
            }
        }
    }
    ll tim;
    while (T--) {
        scanf("%d%d%lld",&x,&y,&tim);
        if (t[x][y]==-1||tim<t[x][y]) printf("%c\n",s[x][y]);
        else {
            ll p=tim-t[x][y];
            if (p%2==0) printf("%c\n",'0'+'1'-s[x][y]);
            else printf("%c\n",s[x][y]);
        }
    }
    return 0;
}

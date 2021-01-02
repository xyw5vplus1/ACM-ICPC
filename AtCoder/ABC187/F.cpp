#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e6+10;
const int INF=0x3f3f3f3f;
int n,m,x,y;
bool bo[50][50];
int dp[maxn];
bool p[maxn];
bool check(int x)
{
    vector<int> v;
    for (int i=0;i<n;i++)
        if (x&(1<<i)) v.push_back(i);
    int t=v.size();
    for (int i=0;i<t;i++)
        for (int j=i+1;j<t;j++)
        if (!bo[v[i]][v[j]]) return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        scanf("%d%d",&x,&y);
        x--; y--;
        bo[x][y]=bo[y][x]=true;
    }
    for (int i=0;i<(1<<n);i++) p[i]=check(i);
    dp[0]=0;
    for (int i=1;i<(1<<n);i++) dp[i]=INF;
    for (int s=1;s<(1<<n);s++) {
        for (int s0=s;s0;s0=(s0-1)&s)
        if (p[s^s0]) dp[s]=min(dp[s],dp[s0]+1);
        if (p[s]) dp[s]=1;
    }
    printf("%d\n",dp[(1<<n)-1]);
    return 0;
}


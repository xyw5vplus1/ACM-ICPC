#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
const int INF=0x3f3f3f3f;
int n,ans;
vector<int> v[maxn];
char mat[maxn][maxn],g[maxn][maxn];
int pw[maxn][5];
int fob[maxn];
int a[maxn],suf[maxn];
void dfs(int choseL,int choseR,int cur,int cost)
{
    if (cost>=ans) return ; //最优性剪枝
    if (choseR==(1<<n)-1) {
        ans=min(ans,cost);
        return ;
    }
    if (cur>=n) return ; //边界
    if (cur>0&&((choseR&((1<<(cur-1))-1))!=((1<<(cur-1))-1))) return ; //可行性剪枝
    if ((suf[cur]|choseR)!=(1<<n)-1) return ; //可行性剪枝
    if (!(choseL&fob[cur])) {
        int t=v[cur].size();
        bool bo;
        int cnt,newChoseR;
        for (int i=1;i<(1<<t);i++) {
            newChoseR=choseR; cnt=0; bo=true;
            for (int j=0;j<t;j++)
            if (i&(1<<j)) {
                cnt++;
                if (newChoseR&(1<<v[cur][j])) {
                    bo=false; break;
                }
                else newChoseR^=(1<<v[cur][j]);
            }
            if (bo) dfs(choseL^(1<<cur),newChoseR,cur+1,cost+pw[cur][cnt]);
        }
        dfs(choseL,choseR,cur+1,cost);
    }
    else dfs(choseL,choseR,cur+1,cost);
}
int T,x;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%s",g[i]);
        for (int i=0;i<n;i++) {
            a[i]=0; v[i].clear();
            for (int j=0;j<n;j++)
            if (g[i][j]=='1')  {
                v[i].push_back(j); a[i]^=(1<<j);
            }
        }
        suf[n-1]=a[n-1];
        for (int i=n-2;i>=0;i--) suf[i]=(suf[i+1]|a[i]);
        for (int i=0;i<n;i++) scanf("%s",mat[i]);
        for (int i=0;i<n;i++) {
            fob[i]=0;
            for (int j=0;j<n;j++)
                if (mat[i][j]=='1') fob[i]^=(1<<j);
        }
        for (int i=0;i<n;i++) {
            scanf("%d",&x);
            pw[i][0]=1; pw[i][1]=x; pw[i][2]=x*x; pw[i][3]=x*x*x;
        }
        ans=INF;
        dfs(0,0,0,0);
        if (ans!=INF) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10000;
const int maxm=75;
int n,m;
char s[maxn+5][maxm+5];
int pre1[maxn+5],pre2[maxm+5];
bool rcmp(int c1,int c2)
{
    for (int i=1;i<=m;i++)
        if (s[c1][i]!=s[c2][i]) return false;
    return true;
}
bool ccmp(int r1,int r2)
{
    for (int i=1;i<=n;i++)
        if (s[i][r1]!=s[i][r2]) return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
    pre1[1]=0;
    for (int i=2,j=0;i<=n;i++) {
        while (j>0&&!rcmp(i,j+1)) j=pre1[j];
        if (rcmp(i,j+1)) j++;
        pre1[i]=j;
    }
    pre2[1]=0;
    for (int i=2,j=0;i<=m;i++) {
        while (j>0&&!ccmp(i,j+1)) j=pre2[j];
        if (ccmp(i,j+1)) j++;
        pre2[i]=j;
    }
    int ans=(n-pre1[n])*(m-pre2[m]);
    printf("%d\n",ans);
    return 0;
}

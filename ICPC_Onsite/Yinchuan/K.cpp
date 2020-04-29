#include<cstdio>
using namespace std;
const int maxn=1000;
const int maxnum=1e6;
int a[maxn+5][maxn+5],b[maxn+5][maxn+5];
int right[maxn+5][maxn+5],down[maxn+5][maxn+5];
int n,m;
int px[maxnum+5],py[maxnum+5];
int l1[maxn+5],r1[maxn+5];
int q[maxn+5];
int ans=0;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            scanf("%d",&b[i][j]);
            px[b[i][j]]=i; py[b[i][j]]=j;
        }
    for (int j=1;j<=m;j++) down[n][j]=1;
    for (int i=n-1;i>=1;i--)
    for (int j=1;j<=m;j++) {
        int x1=px[a[i][j]],y1=py[a[i][j]];
        if (x1<n&&a[i+1][j]==b[x1+1][y1]) down[i][j]=down[i+1][j]+1;
        else down[i][j]=1;
    }
    for (int i=1;i<=n;i++) right[i][m]=1;
    for (int j=m-1;j>=1;j--)
    for (int i=1;i<=n;i++) {
        int x1=px[a[i][j]],y1=py[a[i][j]];
        if (y1<m&&a[i][j+1]==b[x1][y1+1]) right[i][j]=right[i][j+1]+1;
        else right[i][j]=1;
    }
    /*for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) printf("%d ",right[i][j]); printf("\n");
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) printf("%d ",down[i][j]); printf("\n");
    }*/
    for (int i=1;i<=n;i++) {
        int st=1;
        while (st<=m) {
            int ed=st+right[i][st]-1;
            int l=0,r=0;
            for (int j=st;j<=ed;j++) {
                while (l<r&&down[i][j]<down[i][q[r-1]]) {
                    r1[q[r-1]]=j-1; r--;
                }
                q[r++]=j;
            }
            while (l<r) {
                r1[q[r-1]]=ed; r--;
            }
            l=0; r=0;
            for (int j=ed;j>=st;j--) {
                while (l<r&&down[i][j]<down[i][q[r-1]]) {
                    l1[q[r-1]]=j+1; r--;
                }
                q[r++]=j;
            }
            while (l<r) {
                l1[q[r-1]]=st; r--;
            }
            for (int j=st;j<=ed;j++)
                if ((r1[j]-l1[j]+1)*down[i][j]>ans) ans=(r1[j]-l1[j]+1)*down[i][j];
            //printf("debug %d %d %d\n",i,st,ed);
            //for (int j=st;j<=ed;j++) printf("(%d %d) ",l1[j],r1[j]); printf("\n");
            st=ed+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}

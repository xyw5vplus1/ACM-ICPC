#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int a[maxn+5][maxn+5];
bool bo[maxn+5];
int T,n;
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
        int sum=0,num1=0,num2=0;
        for (int i=1;i<=n;i++) sum+=a[i][i];
        for (int i=1;i<=n;i++) {
            memset(bo,false,sizeof(bo));
            for (int j=1;j<=n;j++)
            if (bo[a[i][j]]) {
                num1++; break;
            }
            else bo[a[i][j]]=true;
        }
        for (int j=1;j<=n;j++) {
            memset(bo,false,sizeof(bo));
            for (int i=1;i<=n;i++)
            if (bo[a[i][j]]) {
                num2++; break;
            }
            else bo[a[i][j]]=true;
        }
        printf("Case #%d: %d %d %d\n",kase,sum,num1,num2);
    }
    return 0;
}

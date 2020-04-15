/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int n,m,k,x,y;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=k;i++) scanf("%d%d",&x,&y);
    for (int i=1;i<=k;i++) scanf("%d%d",&x,&y);
    if (n==1) {
        printf("%d\n",2*m);
        for (int i=1;i<=m;i++) printf("L");
        for (int i=1;i<=m;i++) printf("R");
    }
    else if (m==1) {
        printf("%d\n",2*n);
        for (int i=1;i<=n;i++) printf("U");
        for (int i=1;i<=n;i++) printf("D");
    }
    else {
        printf("%d\n",n+m-2+n*m);
        for (int i=1;i<m;i++) printf("L");
        for (int i=1;i<n;i++) printf("U");
        for (int i=1;i<=n;i++) {
            if (i&1) {
                for (int j=1;j<m;j++) printf("R");
                printf("D");
            }
            else {
                for (int j=1;j<m;j++) printf("L");
                printf("D");
            }
        }
    }
    return 0;
}*/

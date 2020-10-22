#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10;
int T,n,k;
int f[maxn];
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&k);
        printf("Case #%d:",kase);
        memset(f,0,sizeof(f));
        if (n>=2) {
            f[1]=2*k; f[2]=k;
            for (int i=3,j=k-1;j>=1;i++,j--) f[i]=j;
            for (int i=k+2,j=k+1;j<=2*k-1;i++,j++) f[i]=j;
            for (int i=n;i>=1;i--)
                if (f[i]!=0) break;
                else f[i]=i;
        }
        else {
            f[1]=1;
        }
        for (int i=1;i<=n;i++) printf(" %d",f[i]);
        printf("\n");
    }
    return 0;
}

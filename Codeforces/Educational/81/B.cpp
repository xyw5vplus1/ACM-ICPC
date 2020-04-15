/*#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int T,n,x;
char s[maxn+5];
int sum[maxn+5];
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&x);
        scanf("%s",s+1);
        sum[0]=0;
        for (int i=1;i<=n;i++) {
            if (s[i]=='0') sum[i]=sum[i-1]+1;
            else sum[i]=sum[i-1]-1;
        }
        int ans=0;
        if (sum[n]==0) {
            for (int i=1;i<=n;i++)
                if (sum[i]==x) ans++;
            if (ans) {
                printf("-1\n");
                continue;
            }
            else {
                printf("0\n");
                continue;
            }
        }
        for (int i=1;i<=n;i++) {
            if ((x-sum[i])%sum[n]==0) {
                int p=(x-sum[i])/sum[n];
                if (p>=0) ans++;
            }
        }
        if (x==0) ans++;
        printf("%d\n",ans);
    }
    return 0;
}*/



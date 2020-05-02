//只过了前两个部分
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int T,n;
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d",&n);
        printf("Case #%d:\n",kase);
        if (n<=500) {
            for (int i=1;i<=n;i++) printf("%d %d\n",i,1);
        }
        else if (n<=1000){
            int x=1;
            while (x*(x+1)/2+1<=n) x++;
            x--;
            printf("1 1\n");
            for (int i=2;i<=x+1;i++) printf("%d %d\n",i,2);
            int last=n-(1+x*(x+1)/2);
            for (int i=x+1;i>=1;i--) {
                if (!last) break;
                printf("%d %d\n",i,1);
                last--;
            }
        }
        else {

        }
    }
    return 0;
}

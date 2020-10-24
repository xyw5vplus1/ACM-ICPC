#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,d;
int a[maxn];
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&d);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int cnt=0;
        for (int i=1;i<=n;i++)
            if (a[i]>1) cnt++;
        if (d==1) {
            if (cnt==0) {
                if (n%3==0) printf("No\n");
                else printf("Yes\n");
            }
            else printf("Yes\n");
        }
        else {
            if (cnt>=2) printf("Yes\n");
            else if (cnt==1){
                if ((n-cnt)%3==0||n%3==0) printf("No\n");
                else printf("Yes\n");
            }
            else {
                if ((n-1)%3==0) printf("No\n");
                else printf("Yes\n");
            }
        }
    }
    return 0;
}
/*
2
3 1
1 1 2
3 2
1 1 2
*/

#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        if (n%2==0) {
            for (int i=1;i<=(n/2);i++) printf("1");
            printf("\n");
        }
        else {
            printf("%d",7);
            for (int i=1;i<=((n-3)/2);i++) printf("1");
            printf("\n");
        }
    }
    return 0;
}


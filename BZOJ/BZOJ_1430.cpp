#include<bits/stdc++.h>
using namespace std;
const int mod=9999991;
int n;
int quick_pow(int a,int b)
{
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    if (n==1) {
        printf("1\n");
        return 0;
    }
    int ans=quick_pow(n,n-2);
    for (int i=1;i<=n-1;i++) ans=1LL*ans*i%mod;
    printf("%d\n",ans);
    return 0;
}

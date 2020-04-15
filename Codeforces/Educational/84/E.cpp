#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
const int mod=998244353;
typedef long long ll;
typedef double db;
int pw[maxn+5];
int n;
int ans[maxn+5];
int main()
{
    scanf("%d",&n);
    if (n==1) {
        printf("10\n");
        return 0;
    }
    pw[0]=1;
    for (int i=1;i<=n;i++) pw[i]=1LL*pw[i-1]*10%mod;
    for (int i=1;i<n;i++) {
        int tem=0;
        tem=1LL*10*9*2*pw[n-i-1]%mod;
        int len=i+2;
        tem=(tem+1LL*810*(n-len+1)%mod*pw[n-len]%mod)%mod;
        ans[i]=tem;
    }
    ans[n]=10;
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}

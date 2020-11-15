#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
int T;
int n,k,s;
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d%d",&n,&k,&s);
        ll ans1=k-1;
        ans1++; ans1+=n;
        ll ans2=k-1;
        ans2+=(k-s);
        ans2+=(n-s+1);
        printf("Case #%d: %lld\n",kase,min(ans1,ans2));
    }
    return 0;
}

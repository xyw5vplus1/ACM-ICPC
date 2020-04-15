#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
const int maxn=2e5;
typedef double db;
int a[maxn+5];
ll b[maxn+5];
ll sum=0;
int n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) {
        if (a[i]>=0) {
            sum+=a[i];
            b[i]=sum;
        }
        else {
            b[i]=sum+a[i];
        }
    }
    for (int i=1;i<=n;i++) printf("%lld ",b[i]);
    return 0;
}

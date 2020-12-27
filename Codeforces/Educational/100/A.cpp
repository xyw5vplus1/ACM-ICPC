#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
int T,a,b,c;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&a,&b,&c);
        int l=1,r=1e8;
        while (l<r) {
            int mid=(l+r+1)>>1;
            if (mid<=a&&mid<=b&&mid<=c&&9*mid<=a+b+c) l=mid;
            else r=mid-1;
        }
        if ((9*l==a+b+c)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
int ans,x;
int main()
{
    ans=101;
    for (int i=0;i<4;i++) {
        scanf("%d",&x);
        ans=min(ans,x);
    }
    printf("%d\n",ans);
    return 0;
}

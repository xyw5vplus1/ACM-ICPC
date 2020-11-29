#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
int a,b,x,y;
int main()
{
    scanf("%d%d%d%d",&a,&b,&x,&y);
    int ans=abs(a-b)*y+x;
    if (a>b) ans=min(ans,(abs(a-b)-1)*y+x);
    if (a>b) ans=min(ans,(2*abs(a-b)-1)*x);
    else ans=min(ans,(2*abs(a-b)+1)*x);
    printf("%d\n",ans);
    return 0;
}


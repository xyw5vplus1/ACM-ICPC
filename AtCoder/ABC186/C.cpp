#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define first fi
#define second se
using namespace std;
typedef long long ll;
typedef double db;
int n,ans=0;
bool check(int x)
{
    int m=x;
    while (m) {
        if (m%10==7) return false;
        m/=10;
    }
    m=x;
    while (m) {
        if (m%8==7) return false;
        m/=8;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        if (check(i)) ans++;
    printf("%d\n",ans);
    return 0;
}

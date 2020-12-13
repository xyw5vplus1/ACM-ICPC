#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1000+10;
int n,m,t;
int a[maxn],b[maxn];
bool check()
{
    int cur=m;
    for (int i=1;i<=n;i++) {
        cur=cur-(a[i]-b[i-1]);
        if (cur<=0) return false;
        cur=(cur+b[i]-a[i]);
        cur=min(cur,m);
    }
    cur=cur-(t-b[n]);
    if (cur<=0) return false;
    return true;
}
int main()
{
    scanf("%d%d%d",&m,&n,&t);
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    if (check()) printf("Yes");
    else printf("No");
    return 0;
}


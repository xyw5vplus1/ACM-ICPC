#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
ll tot=0;
int a[maxn];
int m,n;
int main()
{
    scanf("%d%d",&m,&n);
    if (n==0) {
        printf("1\n");
        return 0;
    }
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int t=m+1;
    for (int i=2;i<=n;i++)
        if (a[i]!=a[i-1]+1) t=min(t,a[i]-a[i-1]-1);
    if (a[1]>1) t=min(t,a[1]-1);
    if (a[n]<m) t=min(t,m-a[n]);
    //printf("debug %d\n",t);
    for (int i=2;i<=n;i++)
    if (a[i]!=a[i-1]+1) {
        tot=tot+(a[i]-a[i-1]-1+(t-1))/t;
    }
    if (a[1]>1) tot=tot+(a[1]-1+(t-1))/t;
    if (a[n]<m) tot=tot+(m-a[n]+(t-1))/t;
    printf("%lld\n",tot);
    return 0;
}


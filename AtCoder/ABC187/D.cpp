#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
struct node{
    ll a,b;
    int id;
}c[maxn];
ll suma[maxn];
int n;
bool cmp(node x,node y)
{
    if (x.a*2+x.b==y.a*2+y.b) return x.id<y.id;
    return x.a*2+x.b>y.a*2+y.b;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%lld%lld",&c[i].a,&c[i].b);
        c[i].id=i;
    }
    sort(c+1,c+n+1,cmp);
    suma[n+1]=0;
    for (int i=n;i>=1;i--) suma[i]=suma[i+1]+c[i].a;
    ll sum=0;
    for (int i=1;i<=n;i++) {
        sum+=c[i].a+c[i].b;
        if (sum>suma[i+1]) {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}


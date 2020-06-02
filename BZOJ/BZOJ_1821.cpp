#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
typedef double db;
const db eps=1e-5;
const int maxn=1e5;
int n,k;
int father[maxn],x[maxn],y[maxn];
int _find(int x)
{
    return x==father[x]?x:father[x]=_find(father[x]);
}
bool _merge(int u,int v)
{
    u=_find(u); v=_find(v);
    if (u==v) return false;
    father[u]=v;
    return true;
}
int main()
{
    scanf("%d%d",&n,&k);
    rep(i,1,n+1) scanf("%d%d",&x[i],&y[i]);
    db l=0.0,r=20000.0;
    while (l+eps<r) {
        db mid=(l+r)/2.0;
        rep(i,1,n+1) father[i]=i;
        int last=n;
        rep(i,1,n+1)
            rep(j,i+1,n+1)
            if (mid*mid>=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) {
                if (_merge(i,j)) last--;
            }
        if (last>=k) l=mid;
        else r=mid;
    }
    printf("%.2f\n",l);
    return 0;
}

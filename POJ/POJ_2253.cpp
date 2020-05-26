#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef double db;
const db eps=1e-6;
const int maxn=300;
int father[maxn];
struct node
{
    int x,y;
}a[maxn];
db dist(node a,node b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}
int _find(int x)
{
    return (x==father[x])?x:father[x]=_find(father[x]);
}
void _merge(int u,int v)
{
    u=_find(u); v=_find(v);
    father[u]=v;
}
int main()
{
    int kase=0;
    int n;
    while (scanf("%d",&n)!=EOF&&n) {
        kase++;
        printf("Scenario #%d\n",kase);
        rep(i,1,n+1) scanf("%d%d",&a[i].x,&a[i].y);
        db l=0,r=2000.0;
        while (l+eps<r) {
            db mid=(l+r)/2.0;
            rep(i,1,n+1) father[i]=i;
            rep(i,1,n+1)
                rep(j,i+1,n+1)
                if (dist(a[i],a[j])<eps+mid) _merge(i,j);
            if (_find(1)==_find(2)) r=mid;
            else l=mid;
        }
        printf("Frog Distance = %.3f\n\n",l);
    }
    return 0;
}

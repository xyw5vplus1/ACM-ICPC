#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=100;
int T,n;
ll a[maxn];
int pw[55];
int main()
{
    scanf("%d",&T);
    pw[0]=1;
    for (int i=1;i<=50;i++) pw[i]=pw[i-1]*2;
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) {
            int l=0,r=40;
            while (l<r) {
                int mid=(l+r+1)>>1;
                if (pw[mid]<=a[i]) l=mid;
                else r=mid-1;
            }
            int ans1=pw[l],ans2=pw[l+1];
            if (a[i]-ans1<=ans2) printf("%d ",ans1);
            else printf("%d ",ans2);
        }
        printf("\n");
    }
    return 0;
}

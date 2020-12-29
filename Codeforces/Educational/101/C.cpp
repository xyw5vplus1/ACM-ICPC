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
int l[maxn],r[maxn];
int h[maxn];
int n,k;
int T;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",&h[i]);
        l[1]=h[1]; r[1]=h[1];
        bool bo=true;
        for (int i=2;i<=n;i++) {
            l[i]=max(h[i],l[i-1]-k+1);
            r[i]=min(h[i]+k-1,r[i-1]+k-1);
            if (l[i]>r[i]) bo=false;
        }
        if (l[n]>h[n]) bo=false;
        if (bo) printf("YES\n");
        else printf("NO\n");
    }
    //printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

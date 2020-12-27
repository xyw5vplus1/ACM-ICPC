#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
set<int> s;
const int maxn=2e5+10;
int T,n;
int a[maxn],b[maxn];
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        s.clear();
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]); s.insert(a[i]);
        }
        int t=1;
        int n0=0;
        while (t<=2*n) {
            if (!s.count(t)) b[++n0]=t;
            t++;
        }
        s.clear();
        for (int i=1;i<=n;i++) {
            s.insert(b[i]);
        }
        int up=0;
        for (int i=1;i<=n;i++) {
            set<int>::iterator iter=s.lower_bound(a[i]);
            if (iter==s.end()) continue;
            up++; s.erase(iter);
        }
        s.clear();
        for (int i=1;i<=n;i++) s.insert(b[i]);
        int down=n;
        for (int i=n;i>=1;i--) {
            set<int>::iterator iter=s.lower_bound(a[i]);
            if (iter==s.begin()) continue;
            iter--;
            down--; s.erase(iter);
        }
        printf("%d\n",up-down+1);
    }
    return 0;
}


#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a-1;i>=b;i--)
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
clock_t startTime;
const int maxn=100+10;
mt19937 mrand(random_device{}());
db getCurrentTime()
{
    return (db)(clock()-startTime)/CLOCKS_PER_SEC;
}
int T,n,k;
int a[maxn];
int main()
{
    startTime=clock();
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&k);
        rep(i,1,n+1) scanf("%d",&a[i]);
        int cur;
        while (k--) {
            cur=1;
            while (cur<n&&a[cur]>=a[cur+1]) cur++;
            if (cur==n) {
                break;
            }
            if (cur<n) {
                a[cur]++;
            }
        }
        if (cur==n) printf("-1\n");
        else printf("%d\n",cur);
    }
    return 0;
}


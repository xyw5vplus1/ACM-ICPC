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
const int maxn=1e5+10;
clock_t startTime;
mt19937 mrand(random_device{}());
db getCurrentTime()
{
    return (db)(clock()-startTime)/CLOCKS_PER_SEC;
}
set<int> s1[maxn],s2[maxn];
int T,n,m;
int a[maxn],b[maxn],c[maxn];
int ans[maxn];
bool isOK[maxn];
int main()
{
    startTime=clock();
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        rep(i,1,n+1) scanf("%d",&a[i]);
        rep(i,1,n+1) scanf("%d",&b[i]);
        rep(i,1,n+1) isOK[i]=false;
        rep(i,1,n+1) {
            s1[i].clear(); s2[i].clear();
        }
        rep(i,1,n+1) {
            if (a[i]!=b[i]) {
                s2[b[i]].insert(i);
                isOK[i]=false;
            }
            else {
                s1[b[i]].insert(i);
                isOK[i]=true;
            }
        }
        rep(i,1,m+1) scanf("%d",&c[i]);
        bool bo=true;
        per(j,m+1,1) {
            if (s2[c[j]].size()==0) {
                if (s1[c[j]].size()==0) {
                    if (j==m) {
                        bo=false; break;
                    }
                    else ans[j]=ans[j+1];
                }
                else {
                    auto e=s1[c[j]].begin();
                    ans[j]=(*e);
                }
            }
            else {
                auto e=s2[c[j]].begin();
                ans[j]=(*e); s2[c[j]].erase(*e);
                isOK[*e]=true;
            }
        }
        rep(i,1,n+1)
        if (!isOK[i]) bo=false;
        if (bo) {
            printf("YES\n");
            rep(i,1,m+1) printf("%d ",ans[i]); printf("\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}


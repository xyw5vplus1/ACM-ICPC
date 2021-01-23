#include<cstdio>
#include<algorithm>
#include<vector>
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
const int maxn=5e4+10;
struct node
{
    int num,val,id;
    int ch[2];
    int fa;
}a[maxn];
bool cmp(node a,node b)
{
    return a.num<b.num;
}
bool cmp1(node a,node b)
{
    return a.id<b.id;
}
int s[maxn];
int n;
int main()
{
    while (scanf("%d",&n)!=EOF) {
        rep(i,1,n+1) {
            scanf("%d%d",&a[i].num,&a[i].val);
            a[i].id=i;
            a[i].ch[0]=a[i].ch[1]=0; a[i].fa=0;
        }
        sort(a+1,a+n+1,cmp);
        int h=0;
        rep(i,1,n+1) {
            int last=0;
            while (h>0&&a[s[h-1]].val>a[i].val) {
                last=s[h-1]; h--;
            }
            if (h>0) a[i].fa=a[s[h-1]].id;
            a[i].ch[0]=a[last].id; a[last].fa=a[i].id;
            if (h>0) a[s[h-1]].ch[1]=a[i].id;
            s[h++]=i;
        }
        sort(a+1,a+n+1,cmp1);
        printf("YES\n");
        rep(i,1,n+1) printf("%d %d %d\n",a[i].fa,a[i].ch[0],a[i].ch[1]);
    }
    return 0;
}

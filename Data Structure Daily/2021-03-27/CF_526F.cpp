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
mt19937 mrand(random_device{}());
db getCurrentTime()
{
    return (db)(clock()-startTime)/CLOCKS_PER_SEC;
}
const int maxn=3e5+10;
int a[maxn],s1[maxn],s2[maxn];
int n,x,y;
struct node
{
    int mn,cnt;
    int lazy;
    void update(int v)
    {
        mn+=v;
        lazy+=v;
    }
}b[maxn<<2];
void pushup(int p)
{
    if (b[lson(p)].mn<b[rson(p)].mn) {
        b[p].mn=b[lson(p)].mn;
        b[p].cnt=b[lson(p)].cnt;
    }
    else if (b[rson(p)].mn<b[lson(p)].mn) {
        b[p].mn=b[rson(p)].mn;
        b[p].cnt=b[rson(p)].cnt;
    }
    else {
        b[p].mn=b[lson(p)].mn;
        b[p].cnt=b[lson(p)].cnt+b[rson(p)].cnt;
    }
}
void build(int p,int l,int r)
{
    b[p].lazy=0;
    if (l==r) {
        b[p].mn=l;
        b[p].cnt=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    pushup(p);
}
void pushdown(int p)
{
    if (b[p].lazy) {
        b[lson(p)].update(b[p].lazy);
        b[rson(p)].update(b[p].lazy);
        b[p].lazy=0;
    }
}
void updateSeg(int p,int l,int r,int L,int R,int v)
{
    if (L<=l&&r<=R) {
        b[p].update(v);
        return ;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if (L<=mid) updateSeg(lson(p),l,mid,L,R,v);
    if (R>mid) updateSeg(rson(p),mid+1,r,L,R,v);
    pushup(p);
}
node getMin(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) return b[p];
    int mid=(l+r)>>1;
    pushdown(p);
    if (R<=mid) return getMin(lson(p),l,mid,L,R);
    else if (L>mid) return getMin(rson(p),mid+1,r,L,R);
    else {
        node e1=getMin(lson(p),l,mid,L,R);
        node e2=getMin(rson(p),mid+1,r,L,R);
        node e;
        if (e1.mn<e2.mn) {
            e.mn=e1.mn;
            e.cnt=e1.cnt;
        }
        else if (e2.mn<e1.mn) {
            e.mn=e2.mn;
            e.cnt=e2.cnt;
        }
        else {
            e.mn=e1.mn;
            e.cnt=e1.cnt+e2.cnt;
        }
        return e;
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&x,&y);
        a[x]=y;
    }
    build(1,1,n);
    int h1=0,h2=0;
    ll ans=0;
    for (int i=1;i<=n;i++) {
        while (h1>0&&a[s1[h1]]>=a[i]) {
            h1--;
            updateSeg(1,1,n,s1[h1]+1,s1[h1+1],-a[i]+a[s1[h1+1]]);
        }
        while (h2>0&&a[s2[h2]]<=a[i]) {
            h2--;
            updateSeg(1,1,n,s2[h2]+1,s2[h2+1],a[i]-a[s2[h2+1]]);
        }
        s1[++h1]=i; s2[++h2]=i;
        node q=getMin(1,1,n,1,i);
        if (q.mn==i) ans+=q.cnt;
    }
    printf("%lld\n",ans);
    return 0;
}

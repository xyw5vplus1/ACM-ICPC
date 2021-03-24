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
const int maxn=1e5+10;
const int INF=1e5;
const ll INF1=0x3f3f3f3f3f3f3f3f;
int n,m,x0;
int a[maxn];
int x,v,l,r,a0,b0,c0;
db getCurrentTime()
{
    return (db)(clock()-startTime)/CLOCKS_PER_SEC;
}
int getRand()
{
    x0=(1LL*100000005*x0+20150609) % 998244353;
    return x0/100;
}
struct node
{
    int mx,mn;
    bool rev;
    int mxp,mnp;
    void update()
    {
        swap(mx,mn);
        swap(mxp,mnp);
        mx=INF-mx; mn=INF-mn;
        rev^=1;
    }
}b[maxn<<2];
void pushup(int p)
{
    b[p].mx=-INF;
    if (b[lson(p)].mx>b[p].mx) {
        b[p].mx=b[lson(p)].mx;
        b[p].mxp=b[lson(p)].mxp;
    }
    if (b[rson(p)].mx>b[p].mx) {
        b[p].mx=b[rson(p)].mx;
        b[p].mxp=b[rson(p)].mxp;
    }

    b[p].mn=INF;
    if (b[lson(p)].mn<b[p].mn) {
        b[p].mn=b[lson(p)].mn;
        b[p].mnp=b[lson(p)].mnp;
    }
    if (b[rson(p)].mn<b[p].mn) {
        b[p].mn=b[rson(p)].mn;
        b[p].mnp=b[rson(p)].mnp;
    }
}
void build(int p,int l,int r)
{
    if (l==r) {
        b[p].mx=b[p].mn=a[l];
        b[p].mxp=b[p].mnp=l;
        return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    pushup(p);
}
void pushdown(int p)
{
    if (b[p].rev) {
        b[lson(p)].update();
        b[rson(p)].update();
        b[p].rev=0;
    }
}
void modify(int p,int l,int r,int pos,int val)
{
    if (l==r) {
        b[p].mx=b[p].mn=val;
        return ;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if (pos<=mid) modify(lson(p),l,mid,pos,val);
    else modify(rson(p),mid+1,r,pos,val);
    pushup(p);
}
void coverSeg(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        b[p].update();
        return ;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if (L<=mid) coverSeg(lson(p),l,mid,L,R);
    if (R>mid) coverSeg(rson(p),mid+1,r,L,R);
    pushup(p);
}
node getMx(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) return b[p];
    int mid=(l+r)>>1;
    pushdown(p);
    if (R<=mid) return getMx(lson(p),l,mid,L,R);
    else if (L>mid) return getMx(rson(p),mid+1,r,L,R);
    else {
        node e1=getMx(lson(p),l,mid,L,R);
        node e2=getMx(rson(p),mid+1,r,L,R);
        node e;
        e.mx=-INF;
        if (e1.mx>e.mx) {
            e.mx=e1.mx;
            e.mxp=e1.mxp;
        }
        if (e2.mx>e.mx) {
            e.mx=e2.mx;
            e.mxp=e2.mxp;
        }
        return e;
    }
}
void updateVal(ll &ans,int a,int b,int c,int x,int y)
{
    ans=max(ans,1LL*a*x+1LL*b*y+1LL*c*x*y);
}
char s[10];
int main()
{
    scanf("%d%d%d",&n,&m,&x0);
    for (int i=1;i<=n;i++) a[i]=getRand()%100001;
    build(1,1,n);
    while (m--) {
        scanf("%s",s);
        if (s[0]=='C') {
            x=getRand()%n+1;
            v=getRand()%(INF+1);
            modify(1,1,n,x,v);
        }
        else if (s[0]=='R') {
            l=getRand()%n+1; r=getRand()%n+1;
            if (l>r) swap(l,r);
            coverSeg(1,1,n,l,r);
        }
        else {
            scanf("%d%d%d",&a0,&b0,&c0);
            l=getRand()%n+1; r=getRand()%n+1;
            if (l>r) swap(l,r);
            node e=getMx(1,1,n,l,r);
            int cur=e.mxp;
            ll ans=-INF1;
            updateVal(ans,a0,b0,c0,cur,e.mx);
            l=cur+1;
            while (l<=r) {
                e=getMx(1,1,n,l,r);
                cur=e.mxp;
                updateVal(ans,a0,b0,c0,cur,e.mx);
                l=cur+1;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

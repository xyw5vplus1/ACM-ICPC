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
const int INF=0x3f3f3f3f;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
clock_t startTime;
mt19937 mrand(random_device{}());
db getCurrentTime()
{
    return (db)(clock()-startTime)/CLOCKS_PER_SEC;
}
const int maxn=1e5+10;
int a[maxn];
int n,m,op;
int l,r,x,val,k;
struct node
{
    int lmx,lmn,rmx,rmn;
    int lmxp,lmnp,rmxp,rmnp;
    int sum;
    int mx,mn;
    int mxl,mxr,mnl,mnr;
    int lazy;
    void update()
    {
        swap(lmx,lmn); lmx=-lmx; lmn=-lmn;
        swap(lmxp,lmnp);
        swap(rmx,rmn); rmx=-rmx; rmn=-rmn;
        swap(rmxp,rmnp);
        sum=-sum;
        swap(mx,mn); mx=-mx; mn=-mn;
        swap(mxl,mnl);
        swap(mxr,mnr);
        lazy^=1;
    }
}b[maxn<<2];
void pushup(int p)
{
    b[p].lmx=max(b[lson(p)].lmx,b[lson(p)].sum+b[rson(p)].lmx);
    if (b[p].lmx==b[lson(p)].lmx) b[p].lmxp=b[lson(p)].lmxp;
    else b[p].lmxp=b[rson(p)].lmxp;

    b[p].lmn=min(b[lson(p)].lmn,b[lson(p)].sum+b[rson(p)].lmn);
    if (b[p].lmn==b[lson(p)].lmn) b[p].lmnp=b[lson(p)].lmnp;
    else b[p].lmnp=b[rson(p)].lmnp;

    b[p].rmx=max(b[rson(p)].rmx,b[rson(p)].sum+b[lson(p)].rmx);
    if (b[p].rmx==b[rson(p)].rmx) b[p].rmxp=b[rson(p)].rmxp;
    else b[p].rmxp=b[lson(p)].rmxp;

    b[p].rmn=min(b[rson(p)].rmn,b[rson(p)].sum+b[lson(p)].rmn);
    if (b[p].rmn==b[rson(p)].rmn) b[p].rmnp=b[rson(p)].rmnp;
    else b[p].rmnp=b[lson(p)].rmnp;

    b[p].mx=-INF;
    if (b[lson(p)].mx>b[p].mx) {
        b[p].mx=b[lson(p)].mx;
        b[p].mxl=b[lson(p)].mxl;
        b[p].mxr=b[lson(p)].mxr;
    }
    if (b[rson(p)].mx>b[p].mx) {
        b[p].mx=b[rson(p)].mx;
        b[p].mxl=b[rson(p)].mxl;
        b[p].mxr=b[rson(p)].mxr;
    }
    if (b[lson(p)].rmx+b[rson(p)].lmx>b[p].mx) {
        b[p].mx=b[lson(p)].rmx+b[rson(p)].lmx;
        b[p].mxl=b[lson(p)].rmxp;
        b[p].mxr=b[rson(p)].lmxp;
    }

    b[p].mn=INF;
    if (b[lson(p)].mn<b[p].mn) {
        b[p].mn=b[lson(p)].mn;
        b[p].mnl=b[lson(p)].mnl;
        b[p].mnr=b[lson(p)].mnr;
    }
    if (b[rson(p)].mn<b[p].mn) {
        b[p].mn=b[rson(p)].mn;
        b[p].mnl=b[rson(p)].mnl;
        b[p].mnr=b[rson(p)].mnr;
    }
    if (b[lson(p)].rmn+b[rson(p)].lmn<b[p].mn) {
        b[p].mn=b[lson(p)].rmn+b[rson(p)].lmn;
        b[p].mnl=b[lson(p)].rmnp;
        b[p].mnr=b[rson(p)].lmnp;
    }

    b[p].sum=b[lson(p)].sum+b[rson(p)].sum;
}
void build(int p,int l,int r)
{
    b[p].lazy=0;
    if (l==r) {
        b[p].sum=a[l];
        b[p].lmn=b[p].lmx=a[l];
        b[p].rmn=b[p].rmx=a[l];
        b[p].mx=b[p].mn=a[l];
        b[p].mxl=b[p].mxr=b[p].mnl=b[p].mnr=l;
        b[p].lmxp=b[p].lmnp=b[p].rmxp=b[p].rmnp=l;
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
        b[lson(p)].update();
        b[rson(p)].update();
        b[p].lazy=false;
    }
}
void modify(int p,int l,int r,int pos,int val)
{
    if (l==r) {
        b[p].sum=val;
        b[p].lmx=b[p].lmn=b[p].rmx=b[p].rmn=val;
        b[p].mx=b[p].mn=val;
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(p);
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
node getMaxSeg(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        return b[p];
    }
    int mid=(l+r)>>1;
    pushdown(p);
    if (R<=mid) return getMaxSeg(lson(p),l,mid,L,R);
    else if (L>mid) return getMaxSeg(rson(p),mid+1,r,L,R);
    else {
        node e1=getMaxSeg(lson(p),l,mid,L,R);
        node e2=getMaxSeg(rson(p),mid+1,r,L,R);
        node e;
        e.lmx=max(e1.lmx,e1.sum+e2.lmx);
        if (e.lmx==e1.lmx) e.lmxp=e1.lmxp;
        else e.lmxp=e2.lmxp;

        e.lmn=min(e1.lmn,e1.sum+e2.lmn);
        if (e.lmn==e1.lmn) e.lmnp=e1.lmnp;
        else e.lmnp=e2.lmnp;

        e.rmx=max(e2.rmx,e2.sum+e1.rmx);
        if (e.rmx==e2.rmx) e.rmxp=e2.rmxp;
        else e.rmxp=e1.rmxp;

        e.rmn=min(e2.rmn,e2.sum+e1.rmn);
        if (e.rmn==e2.rmn) e.rmnp=e2.rmnp;
        else e.rmnp=e1.rmnp;

        e.mx=-INF;
        if (e1.mx>e.mx) {
            e.mx=e1.mx;
            e.mxl=e1.mxl;
            e.mxr=e1.mxr;
        }
        if (e2.mx>e.mx) {
            e.mx=e2.mx;
            e.mxl=e2.mxl;
            e.mxr=e2.mxr;
        }
        if (e1.rmx+e2.lmx>e.mx) {
            e.mx=e1.rmx+e2.lmx;
            e.mxl=e1.rmxp;
            e.mxr=e2.lmxp;
        }

        e.mn=INF;
        if (e1.mn<e.mn) {
            e.mn=e1.mn;
            e.mnl=e1.mnl;
            e.mnr=e1.mnr;
        }
        if (e2.mn<e.mn) {
            e.mn=e2.mn;
            e.mnl=e2.mnl;
            e.mnr=e2.mnr;
        }
        if (e1.rmn+e2.lmn<e.mn) {
            e.mn=e1.rmn+e2.lmn;
            e.mnl=e1.rmnp;
            e.mnr=e2.lmnp;
        }

        e.sum=e1.sum+e2.sum;
        return e;
    }
}
vector<PII> v;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    while (m--) {
        scanf("%d",&op);
        if (op==0) {
            scanf("%d%d",&x,&val);
            modify(1,1,n,x,val);
        }
        else {
            scanf("%d%d%d",&l,&r,&k);
            v.clear();
            int ans=0;
            while (k--) {
                node e=getMaxSeg(1,1,n,l,r);
                if (e.mx<=0) break;
                ans+=e.mx;
                coverSeg(1,1,n,e.mxl,e.mxr);
                v.push_back(make_pair(e.mxl,e.mxr));
            }
            for (auto e:v) {
                coverSeg(1,1,n,e.first,e.second);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

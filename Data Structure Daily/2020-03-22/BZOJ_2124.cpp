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
const int mod=1e9+7;
const int maxn=1e4+10;
int pw[maxn];
int a[maxn];
int T,n;
db getCurrentTime()
{
    return (db)(clock()-startTime)/CLOCKS_PER_SEC;
}
struct node
{
    int Lhash,Rhash;
    int len;
    int v;
}b[maxn<<2];
void pushup(int p)
{
    b[p].Lhash=(1LL*b[lson(p)].Lhash*pw[b[rson(p)].len]%mod+b[rson(p)].Lhash)%mod;
    b[p].Rhash=(1LL*b[rson(p)].Rhash*pw[b[lson(p)].len]%mod+b[lson(p)].Rhash)%mod;
    b[p].len=b[lson(p)].len+b[rson(p)].len;
}
void build(int p,int l,int r)
{
    if (l==r) {
        b[p].len=1;
        b[p].Lhash=b[p].Rhash=0;
        b[p].v=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    pushup(p);
}
void modify(int p,int l,int r,int pos)
{
    if (l==r) {
        b[p].v=1;
        b[p].Lhash=b[p].Rhash=1;
        return ;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) modify(lson(p),l,mid,pos);
    else modify(rson(p),mid+1,r,pos);
    pushup(p);
}
node getHash(int p,int l,int r,int L,int R)
{
    if (L>R) {
        node e;
        e.Lhash=e.Rhash=0;
        return e;
    }
    if (L<=l&&r<=R) return b[p];
    int mid=(l+r)>>1;
    if (R<=mid) return getHash(lson(p),l,mid,L,R);
    else if (L>mid) return getHash(rson(p),mid+1,r,L,R);
    else {
        node e1=getHash(lson(p),l,mid,L,R);
        node e2=getHash(rson(p),mid+1,r,L,R);
        node e;
        e.Lhash=(1LL*e1.Lhash*pw[e2.len]%mod+e2.Lhash)%mod;
        e.Rhash=(1LL*e2.Rhash*pw[e1.len]%mod+e1.Rhash)%mod;
        e.len=e1.len+e2.len;
        return e;
    }
}
int main()
{
    pw[0]=1;
    for (int i=1;i<maxn;i++) pw[i]=1LL*pw[i-1]*233%mod;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        bool bo=false;
        for (int i=1;i<=n;i++) {
            int x=min(a[i]-1,n-a[i]);
            node l=getHash(1,1,n,a[i]-x,a[i]-1);
            node r=getHash(1,1,n,a[i]+1,a[i]+x);
            if (l.Rhash!=r.Lhash) {
                bo=true; break;
            }
            modify(1,1,n,a[i]);
        }
        if (bo) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
/*
1 5 3 2 7 6 4
*/

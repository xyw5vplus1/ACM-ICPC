#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
const int maxn=2e5;
int a[maxn+5],p[maxn+5],pos[maxn+5];
ll c[maxn+5];
int n;
struct SegmentTree
{
    ll mn,lazy;
}b[4*maxn+5];
void pushup(int p)
{
    b[p].mn=min(b[lson(p)].mn,b[rson(p)].mn);
}
void build(int p,int l,int r)
{
    b[p].lazy=0;
    if (l==r) {
        b[p].mn=c[l];
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
        b[lson(p)].mn+=b[p].lazy; b[lson(p)].lazy+=b[p].lazy;
        b[rson(p)].mn+=b[p].lazy; b[rson(p)].lazy+=b[p].lazy;
        b[p].lazy=0;
    }
}
void modify(int p,int l,int r,int L,int R,int val)
{
    if (L<=l&&r<=R) {
        b[p].mn+=val; b[p].lazy+=val;
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(p);
    if (L<=mid) modify(lson(p),l,mid,L,R,val);
    if (R>mid) modify(rson(p),mid+1,r,L,R,val);
    pushup(p);
}
ll getMn(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) return b[p].mn;
    int mid=(l+r)>>1;
    pushdown(p);
    if (R<=mid) return getMn(lson(p),l,mid,L,R);
    else if (L>mid) return getMn(rson(p),mid+1,r,L,R);
    else return min(getMn(lson(p),l,mid,L,R),getMn(rson(p),mid+1,r,L,R));
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll sum=0;
    bool bo=false;
    for (int i=1;i<=n;i++) {
        if (p[i]!=1) sum+=a[i];
        else bo=true;
        if (!bo) c[i]=sum+a[pos[1]];
        else c[i]=sum;
    }
    build(1,1,n);
    ll ans=a[1];
    ans=min(ans,1LL*a[n]);
    ans=min(ans,getMn(1,1,n,1,n-1));
    for (int i=2;i<=n;i++) {
        int p=pos[i];
        if (p>1) modify(1,1,n,1,p-1,a[p]);
        modify(1,1,n,p,n,-a[p]);
        ans=min(ans,getMn(1,1,n,1,n-1));
    }
    printf("%I64d\n",ans);
    return 0;
}

/*
简要题意：
n个数，m种操作。
操作一：查询区间和
操作二：区间[l,r]对x取模
操作三：单点赋值
思路：
吕凯风出的div1的题。
这种题的关键在于分析复杂度，本来如果没有第三个操作，会非常放心大胆地写。
因为取模只会让值越变越小，跟区间开根基本上一个道理，该暴力的时候暴力，但是要控制暴力的次数。
单点赋值的存在动摇了我采用这种做法的决心。
然而在题解中，vfleaking分析了一波复杂度，其实这样做还是OK的。
取模的性质保证了，如果一旦被取模的数大于等于模数，在取模后会严格小于原先的一半，也就是说一个数X只会发生[logX]次实际有意义的取模。
为了保证有意义的取模，我们需要维护区间最大值，这个非常好写。
vfleaking把每个数能发生实际取模的次数称为这个数的energy，那么初始状态下的总energy是O(Nlog(ai))的。
维护区间最大值保证了每次实际暴力取模时，会使整个的energy之和至少减少1.
而单点赋值，最大能让整个区间的energy之和增加O(log(ai)).
因此整体的最大energy是O((N+M)log(ai))的。每次减小1的复杂度是均摊O(logN)（线段树深度）的。
因此整体的复杂度是O((N+M)log(ai)logN)的。
两个log在这道题依然是OK的能过的。
*/

#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m,l,r,x,op;
int a[maxn];
struct node
{
    int mx;
    ll sum;
}b[4*maxn];
void pushup(int p)
{
    b[p].mx=max(b[lson(p)].mx,b[rson(p)].mx);
    b[p].sum=b[lson(p)].sum+b[rson(p)].sum;
}
void build(int p,int l,int r)
{
    if (l==r) {
        b[p].mx=b[p].sum=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    pushup(p);
}
void modify(int p,int l,int r,int L,int R,int v)
{
    if (L<=l&&r<=R) {
        if (b[p].mx<v) return ;
        if (l==r) {
            b[p].mx%=v; b[p].sum%=v;
            return ;
        }
        int mid=(l+r)>>1;
        modify(lson(p),l,mid,L,R,v);
        modify(rson(p),mid+1,r,L,R,v);
        pushup(p);
        return ;
    }
    int mid=(l+r)>>1;
    if (L<=mid) modify(lson(p),l,mid,L,R,v);
    if (R>mid) modify(rson(p),mid+1,r,L,R,v);
    pushup(p);
}
void setVal(int p,int l,int r,int pos,int v)
{
    if (l==r) {
        b[p].sum=b[p].mx=v;
        return ;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) setVal(lson(p),l,mid,pos,v);
    else setVal(rson(p),mid+1,r,pos,v);
    pushup(p);
}
ll getSum(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) return b[p].sum;
    int mid=(l+r)>>1;
    ll ans=0;
    if (L<=mid) ans+=getSum(lson(p),l,mid,L,R);
    if (R>mid) ans+=getSum(rson(p),mid+1,r,L,R);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    while (m--) {
        scanf("%d",&op);
        if (op==1) {
            scanf("%d%d",&l,&r);
            printf("%lld\n",getSum(1,1,n,l,r));
        }
        else if (op==2) {
            scanf("%d%d%d",&l,&r,&x);
            modify(1,1,n,l,r,x);
        }
        else {
            scanf("%d%d",&l,&x);
            setVal(1,1,n,l,x);
        }
    }
    return 0;
}

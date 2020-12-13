#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=3e5+10;
int a[maxn];
int n,m;
int op,x,y;
struct node
{
    int val;
}b[maxn<<2];
void pushup(int p)
{
    b[p].val=(b[lson(p)].val^b[rson(p)].val);
}
void build(int p,int l,int r)
{
    if (l==r) {
        b[p].val=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    pushup(p);
}
void modify(int p,int l,int r,int pos,int val)
{
    if (l==r) {
        b[p].val^=val; return ;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) modify(lson(p),l,mid,pos,val);
    else modify(rson(p),mid+1,r,pos,val);
    pushup(p);
}
int getAns(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        return b[p].val;
    }
    int ans=0;
    int mid=(l+r)>>1;
    if (L<=mid) ans^=getAns(lson(p),l,mid,L,R);
    if (R>mid) ans^=getAns(rson(p),mid+1,r,L,R);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    while (m--) {
        scanf("%d%d%d",&op,&x,&y);
        if (op==1) modify(1,1,n,x,y);
        else printf("%d\n",getAns(1,1,n,x,y));
    }
    return 0;
}


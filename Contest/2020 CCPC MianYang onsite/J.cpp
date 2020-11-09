#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
const int maxn=2e5+10;
int T,n,m,t,x;
int mx[maxn];
struct node
{
    int mx;
    int lazy;
}b[maxn<<2];
void pushup(int p)
{
    b[p].mx=max(b[lson(p)].mx,b[rson(p)].mx);
}
void build(int p,int l,int r)
{
    b[p].lazy=0;
    if (l==r) {
        b[p].mx=0;
        return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    pushup(p);
}
void update(int p,int val)
{
    b[p].mx=max(b[p].mx,val);
    b[p].lazy=max(b[p].lazy,val);
}
void pushdown(int p)
{
    if (b[p].lazy) {
        update(lson(p),b[p].lazy);
        update(rson(p),b[p].lazy);
        b[p].lazy=0;
    }
}
void update(int p,int l,int r,int L,int R,int val)
{
    if (L<=l&&r<=R) {
        update(p,val);
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(p);
    if (L<=mid) update(lson(p),l,mid,L,R,val);
    if (R>mid) update(rson(p),mid+1,r,L,R,val);
    pushup(p);
}
int getAns(int p,int l,int r,int pos)
{
    if (l==r) return b[p].mx;
    pushdown(p);
    int mid=(l+r)>>1;
    if (pos<=mid) return getAns(lson(p),l,mid,pos);
    else return getAns(rson(p),mid+1,r,pos);
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=100000;i++) mx[i]=0;
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&t,&x);
            mx[t]=max(mx[t],x);
        }
        build(1,1,100000);
        for (int i=1;i<=100000;i++)
            for (int j=1;j<=m;j+=2*i) update(1,1,100000,j,min(j+i-1,m),mx[i]);
        printf("Case #%d:",kase);
        for (int i=1;i<=m;i++) printf(" %d",getAns(1,1,100000,i));
        printf("\n");
    }
    return 0;
}

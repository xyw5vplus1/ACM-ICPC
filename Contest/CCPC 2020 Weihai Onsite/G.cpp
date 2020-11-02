#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
const int maxn=5e5+10;
const int mod1=1e9+7;
const int mod2=1e9+9;
const int pr=233;
struct node
{
    int val;
    int _hash1;
    int _hash2;
    int mx;
    int lazy;
}b[maxn<<2];
int a[maxn];
int pw1[maxn],pw2[maxn];
int sump1[maxn],sump2[maxn];
void pushup(int p)
{
    b[p]._hash1=(b[lson(p)]._hash1+b[rson(p)]._hash1)%mod1;
    b[p]._hash2=(b[lson(p)]._hash2+b[rson(p)]._hash2)%mod2;
    b[p].mx=max(b[lson(p)].mx,b[rson(p)].mx);
}
void build(int p,int l,int r)
{
    b[p].lazy=0;
    if (l==r) {
        b[p].val=a[l];
        b[p]._hash1=1LL*pw1[l]*b[p].val%mod1;
        b[p]._hash2=1LL*pw2[l]*b[p].val%mod2;
        b[p].mx=b[p].val;
        return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    pushup(p);
}
void update(int p,int l,int r,int v)
{
    b[p].val+=v; b[p].mx+=v;
    b[p]._hash1=(b[p]._hash1+1LL*(sump1[r]-sump1[l-1]+mod1)*v)%mod1;
    b[p]._hash2=(b[p]._hash2+1LL*(sump2[r]-sump2[l-1]+mod2)*v)%mod2;
    b[p].lazy+=v;
}
void pushdown(int p,int l,int r)
{
    if (b[p].lazy) {
        int mid=(l+r)>>1;
        update(lson(p),l,mid,b[p].lazy);
        update(rson(p),mid+1,r,b[p].lazy);
        b[p].lazy=0;
    }
}
void modifySeg(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        update(p,l,r,1);
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(p,l,r);
    if (L<=mid) modifySeg(lson(p),l,mid,L,R);
    if (R>mid) modifySeg(rson(p),mid+1,r,L,R);
    pushup(p);
}
void cutSeg(int p,int l,int r)
{
    if (b[p].mx<65536) return ;
    if (l==r) {
        b[p].val-=65536;
        b[p].mx=b[p].val;
        b[p]._hash1=1LL*b[p].val*pw1[l]%mod1;
        b[p]._hash2=1LL*b[p].val*pw2[l]%mod2;
        return ;
    }
    pushdown(p,l,r);
    int mid=(l+r)>>1;
    cutSeg(lson(p),l,mid);
    cutSeg(rson(p),mid+1,r);
    pushup(p);
}
int queryHash1(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) return b[p]._hash1;
    int ans=0;
    pushdown(p,l,r);
    int mid=(l+r)>>1;
    if (L<=mid) ans=(ans+queryHash1(lson(p),l,mid,L,R))%mod1;
    if (R>mid) ans=(ans+queryHash1(rson(p),mid+1,r,L,R))%mod1;
    return ans;
}
int queryHash2(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) return b[p]._hash2;
    int ans=0;
    pushdown(p,l,r);
    int mid=(l+r)>>1;
    if (L<=mid) ans=(ans+queryHash2(lson(p),l,mid,L,R))%mod2;
    if (R>mid) ans=(ans+queryHash2(rson(p),mid+1,r,L,R))%mod2;
    return ans;
}
int n,q;
int op,l,r,x,y,L;
int main()
{
    scanf("%d%d",&n,&q);
    pw1[0]=1; pw2[0]=1;
    for (int i=1;i<=n;i++) pw1[i]=1LL*pw1[i-1]*pr%mod1;
    for (int i=1;i<=n;i++) pw2[i]=1LL*pw2[i-1]*pr%mod2;
    sump1[0]=0; sump2[0]=0;
    for (int i=1;i<=n;i++) sump1[i]=(sump1[i-1]+pw1[i])%mod1;
    for (int i=1;i<=n;i++) sump2[i]=(sump2[i-1]+pw2[i])%mod2;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    while (q--) {
        scanf("%d",&op);
        if (op==1) {
            scanf("%d%d",&l,&r);
            modifySeg(1,1,n,l,r);
            cutSeg(1,1,n);
        }
        else {
            scanf("%d%d%d",&x,&y,&L);
            if (x>y) swap(x,y);
            int left=queryHash1(1,1,n,x,x+L-1),right=queryHash1(1,1,n,y,y+L-1);
            bool bo=true;
            //printf("debug %d %d\n",1LL*left*pw[y-x]%mod,right);
            if (1LL*left*pw1[y-x]%mod1!=right) bo=false;
            left=queryHash2(1,1,n,x,x+L-1),right=queryHash2(1,1,n,y,y+L-1);
            if (1LL*left*pw2[y-x]%mod2!=right) bo=false;
            if (bo) printf("yes\n");
            else printf("no\n");
        }
    }
    return 0;
}

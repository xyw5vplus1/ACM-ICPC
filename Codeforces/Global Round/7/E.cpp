#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
const int maxn=3e5;
int p[maxn+5],pos[maxn+5],q[maxn+5];
int n;
int ans[maxn+5];
struct node
{
    int mx;
    int lazy;
}b[4*maxn+5];
void pushup(int p)
{
    b[p].mx=max(b[lson(p)].mx,b[rson(p)].mx);
}
void build(int p,int l,int r)
{
    if (l==r) {
        b[p].lazy=b[p].mx=0;
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
        b[lson(p)].lazy+=b[p].lazy; b[lson(p)].mx+=b[p].lazy;
        b[rson(p)].lazy+=b[p].lazy; b[rson(p)].mx+=b[p].lazy;
        b[p].lazy=0;
    }
}
void modify(int p,int l,int r,int L,int R,int d)
{
    if (L<=l&&r<=R) {
        b[p].mx+=d; b[p].lazy+=d;
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(p);
    if (L<=mid) modify(lson(p),l,mid,L,R,d);
    if (R>mid) modify(rson(p),mid+1,r,L,R,d);
    pushup(p);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    for (int i=1;i<=n;i++) scanf("%d",&q[i]);
    build(1,1,n);
    ans[0]=n;
    modify(1,1,n,1,pos[n],1);
    for (int i=1;i<=n-1;i++) {
        modify(1,1,n,1,q[i],-1);
        ans[i]=ans[i-1];
        while (b[1].mx<=0) {
            ans[i]--;
            modify(1,1,n,1,pos[ans[i]],1);
        }
    }
    for (int i=0;i<=n-1;i++) printf("%d ",ans[i]);
    return 0;
}

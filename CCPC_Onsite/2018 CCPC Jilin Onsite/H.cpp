#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
const int mod=1e9+7;
const int maxn=2e5+10;
int T,n,m,l,r,v;
char s[maxn];
int pw[maxn];
struct node
{
    int sum;
    int sump;
    int lazylen;
    int lazysum1;
    int lazysum2;
}b[4*maxn];
void pushup(int p)
{
    b[p].sum=(b[lson(p)].sum+b[rson(p)].sum)%mod;
    b[p].sump=(b[lson(p)].sump+b[rson(p)].sump)%mod;
}
void build(int p,int l,int r)
{
    b[p].lazylen=b[p].lazysum1=b[p].lazysum2=0;
    if (l==r) {
        b[p].sum=0;
        b[p].sump=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    pushup(p);
}
void pushdown(int p,int l,int r)
{
    if (b[p].lazylen!=0) {
        int mid=(l+r)>>1;
        b[lson(p)].sum=(1LL*b[lson(p)].sum*pw[b[p].lazylen]%mod)%mod;
        b[lson(p)].sum=(b[lson(p)].sum+1LL*b[p].lazysum2*(mid-l+1)%mod)%mod;
        b[lson(p)].sum=(b[lson(p)].sum+1LL*b[p].lazysum1*b[lson(p)].sump%mod*pw[b[p].lazylen]%mod)%mod;
        b[lson(p)].sump=1LL*b[lson(p)].sump*pw[2*b[p].lazylen]%mod;

        b[lson(p)].lazylen+=b[p].lazylen;
        b[lson(p)].lazysum2=(1LL*b[lson(p)].lazysum2*pw[b[p].lazylen]%mod+b[p].lazysum2)%mod;
        b[lson(p)].lazysum1=(b[lson(p)].lazysum1+1LL*b[p].lazysum1*pw[(b[lson(p)].lazylen-b[p].lazylen)]%mod)%mod;

        b[rson(p)].sum=(1LL*b[rson(p)].sum*pw[b[p].lazylen]%mod)%mod;
        b[rson(p)].sum=(b[rson(p)].sum+1LL*b[p].lazysum2*(r-mid)%mod)%mod;
        b[rson(p)].sum=(b[rson(p)].sum+1LL*b[p].lazysum1*b[rson(p)].sump%mod*pw[b[p].lazylen]%mod)%mod;
        b[rson(p)].sump=1LL*b[rson(p)].sump*pw[2*b[p].lazylen]%mod;

        b[rson(p)].lazylen+=b[p].lazylen;
        b[rson(p)].lazysum2=(1LL*b[rson(p)].lazysum2*pw[b[p].lazylen]%mod+b[p].lazysum2)%mod;
        b[rson(p)].lazysum1=(b[rson(p)].lazysum1+1LL*b[p].lazysum1*pw[(b[rson(p)].lazylen-b[p].lazylen)]%mod)%mod;

        b[p].lazylen=0;
        b[p].lazysum1=b[p].lazysum2=0;
    }
}
void modify(int p,int l,int r,int L,int R,int v)
{
    if (L<=l&&r<=R) {
        b[p].sum=1LL*b[p].sum*10%mod;
        b[p].sum=(b[p].sum+v*(r-l+1))%mod;
        b[p].sum=(b[p].sum+1LL*v*10*b[p].sump%mod)%mod;
        b[p].sump=1LL*b[p].sump*100%mod;

        b[p].lazylen+=1;
        b[p].lazysum2=(1LL*b[p].lazysum2*10+v)%mod;
        b[p].lazysum1=(b[p].lazysum1+1LL*pw[b[p].lazylen-1]*v%mod)%mod;

        return ;
    }
    int mid=(l+r)>>1;
    pushdown(p,l,r);
    if (L<=mid) modify(lson(p),l,mid,L,R,v);
    if (R>mid) modify(rson(p),mid+1,r,L,R,v);
    pushup(p);
}
int getSum(int p,int l,int r,int L,int R)
{
    if (L>R) return 0;
    if (L<=l&&r<=R) return b[p].sum;
    int mid=(l+r)>>1;
    pushdown(p,l,r);
    int ans=0;
    if (L<=mid) ans=(ans+getSum(lson(p),l,mid,L,R))%mod;
    if (R>mid) ans=(ans+getSum(rson(p),mid+1,r,L,R))%mod;
    return ans;
}
void dfs(int p,int l,int r)
{
    printf("dfs %d %d %d\n",p,l,r);
    printf("sum=%d sump=%d lazylen=%d lazysum1=%d lazysum2=%d\n",b[p].sum,b[p].sump,b[p].lazylen,b[p].lazysum1,b[p].lazysum2);
    if (l==r) return ;
    int mid=(l+r)>>1;
    dfs(lson(p),l,mid);
    dfs(rson(p),mid+1,r);
}
int main()
{
    pw[0]=1;
    for (int i=1;i<maxn;i++)
        pw[i]=1LL*pw[i-1]*10%mod;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        printf("Case %d:\n",kase);
        scanf("%d%d",&n,&m);
        build(1,1,n);
        while (m--) {
            scanf("%s",s);
            if (s[0]=='w') {
                scanf("%d%d%d",&l,&r,&v);
                modify(1,1,n,l,r,v);
                //dfs(1,1,n);
            }
            else {
                scanf("%d%d",&l,&r);
                printf("%d\n",getSum(1,1,n,l,r));
                //dfs(1,1,n);
            }
        }
    }
    return 0;
}

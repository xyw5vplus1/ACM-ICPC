/*
简单题意:
[1..n]每个位置一个空字符串。
两种操作，一种把区间内的每个字符串头尾都加上数字x，例如，'987789'加上'3'变成'39877893'。
第二种查询区间内的数字和（把字符串看成对应的数字串）模1e9+7的余数。
难度：
2018 CCPC 吉林站 金牌题
主要思路：
线段树
需要维护的信息有，区间和，以及区间内的长度幂次和（例如，区间内有两个数，长度分别为4和6，则该项结果为10^4+10^6）
lazy标记项分别有，区间经历第一种操作的次数，区间经过第一种操作带来的头部贡献和尾部贡献（不考虑位置的影响，即只考虑头部尾部单独的大小，不考虑与后面拼接之后的大小）。
转移需要想清楚就可以了，每一项都需要维护得特别清楚。重点是对整段修改，以及pushdown的地方，考虑lazy标记之间叠加的时候。
取模的地方写残了WA了两发。
*/
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

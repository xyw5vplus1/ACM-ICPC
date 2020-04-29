#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
const ll INF=1e12;
const int maxn=5e6;
ll a[maxn+5];
int n,q,l,r,op;
struct Splay
{
    int ch[2];
    int fa;
    int cnt,sz;
    ll val,sum;
}b[maxn+5];
int tot=0,root[maxn+5];
inline int newNode(int fa,ll val)
{
    int p=++tot;
    b[p].fa=fa;
    b[p].val=b[p].sum=val;
    b[p].cnt=b[p].sz=1;
    if (fa) b[fa].ch[b[fa].val<val]=p;
    b[p].ch[0]=b[p].ch[1]=0;
    return p;
}
inline int checkR(int p)
{
    return b[b[p].fa].ch[1]==p;
}
inline void pushup(int p)
{
    b[p].sz=b[p].cnt;
    if (b[p].ch[0]) b[p].sz+=b[b[p].ch[0]].sz;
    if (b[p].ch[1]) b[p].sz+=b[b[p].ch[1]].sz;
    b[p].sum=b[p].val*b[p].cnt;
    if (b[p].ch[0]) b[p].sum+=b[b[p].ch[0]].sum;
    if (b[p].ch[1]) b[p].sum+=b[b[p].ch[1]].sum;
}
inline void RotateNode(int p)
{
    int f=b[p].fa,ff=b[f].fa,w=checkR(p);
    b[f].ch[w]=b[p].ch[w^1]; b[b[f].ch[w]].fa=f;
    b[f].fa=p; b[p].ch[w^1]=f;
    b[p].fa=ff;
    if (ff) b[ff].ch[b[ff].ch[1]==f]=p;
    pushup(f); pushup(p);
}
inline void SplayNode(int p,int goal,int q) //把p旋转为goal的儿子
{
    while (b[p].fa!=goal) {
        int f=b[p].fa;
        int ff=b[f].fa;
        if (ff!=goal) {
            if (checkR(p)==checkR(f)) RotateNode(f);
            else RotateNode(p);
        }
        RotateNode(p);
    }
    if (goal==0) root[q]=p;
}
inline void InsertNode(ll val,int q)
{
    int u=root[q],fa=0;
    while (u) {
        if (b[u].val==val) {
            b[u].cnt++; pushup(u); SplayNode(u,0,q); return ;
        }
        fa=u;
        u=b[u].ch[b[u].val<val];
    }
    u=newNode(fa,val); SplayNode(u,0,q);
}
inline int FindNode(ll val,int q)
{
    int u=root[q];
    while (u) {
        if (b[u].val==val) {
            SplayNode(u,0,q);
            return u;
        }
        u=b[u].ch[b[u].val<val];
    }
    return 0;
}
inline void DeleteNode(ll val,int q) // 元素不存在直接返回
{
    if (!FindNode(val,q)) return ;
    if (b[root[q]].cnt>1) {
        b[root[q]].cnt--; pushup(root[q]); return ;
    }
    if (!b[root[q]].ch[1]) {
        root[q]=b[root[q]].ch[0];
        b[root[q]].fa=0;
    }
    else {
        int u=b[root[q]].ch[1];
        while (b[u].ch[0]) u=b[u].ch[0];
        SplayNode(u,root[q],q);
        b[u].ch[0]=b[root[q]].ch[0];
        b[b[u].ch[0]].fa=u;
        root[q]=u; b[root[q]].fa=0;
        pushup(root[q]);
    }
}
inline int getRank(ll val,int q) // 严格小于的个数+1
{
    int u=root[q],rk=0;
    while (u) {
        if (b[u].val>val) u=b[u].ch[0];
        else if (b[u].val==val) {
            rk+=b[b[u].ch[0]].sz;
            SplayNode(u,0,q);
            break;
        }
        else {
            rk+=b[b[u].ch[0]].sz+b[u].cnt;
            u=b[u].ch[1];
        }
    }
    return rk+1;
}
inline ll getVal(int rk,int q)
{
    int u=root[q];
    while (u) {
        if (rk<=b[b[u].ch[0]].sz) u=b[u].ch[0];
        else if (rk<=b[b[u].ch[0]].sz+b[u].cnt) {
            SplayNode(u,0,q);
            break;
        }
        else {
            rk-=(b[b[u].ch[0]].sz+b[u].cnt);
            u=b[u].ch[1];
        }
    }
    return b[u].val;
}
inline ll pre(ll val,int q) //严格小于
{
    return getVal(getRank(val,q)-1,q);
}
inline ll nxt(ll val,int q) //严格大于
{
    return getVal(getRank(val+1,q),q);
}
void showSplay(int u)
{
    if (b[u].ch[0]) showSplay(b[u].ch[0]);
    printf("%lld ",b[u].val);
    if (b[u].ch[1]) showSplay(b[u].ch[1]);
}
inline ll getSum_NotMoreThan(ll val,int q)
{
    if (!FindNode(val,q)) {
        ll p1=pre(val,q);
        FindNode(p1,q);
        return b[b[root[q]].ch[0]].sum+b[root[q]].cnt*b[root[q]].val;
    }
    else {
        return b[b[root[q]].ch[0]].sum+b[root[q]].cnt*b[root[q]].val;
    }
}
void build(int p,int l,int r)
{
    for (int i=l;i<=r;i++) InsertNode(a[i],p);
    InsertNode(-INF,p); InsertNode(INF,p);
    if (l==r) return ;
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
}
void SegmentTree_Modify(int p,int l,int r,int pos,ll val)
{
    DeleteNode(a[pos],p);
    InsertNode(val,p);
    if (l==r) {
        a[pos]=val;
        /*printf("dfs: ");
        showSplay(root[p]);
        printf("\n");*/
        return ;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) SegmentTree_Modify(lson(p),l,mid,pos,val);
    else SegmentTree_Modify(rson(p),mid+1,r,pos,val);
}
ll SegmentTree_GetSum(int p,int l,int r,int L,int R,ll val)
{
    if (L<=l&&r<=R) return getSum_NotMoreThan(val,p)+INF;
    int mid=(l+r)>>1;
    ll sum=0;
    if (L<=mid) sum+=SegmentTree_GetSum(lson(p),l,mid,L,R,val);
    if (R>mid) sum+=SegmentTree_GetSum(rson(p),mid+1,r,L,R,val);
    return sum;
}
ll solve(int l,int r)
{
    ll v=SegmentTree_GetSum(1,1,n,l,r,1);
    if (v==0) return 1;
    ll last=v,now;
    while (true) {
        now=SegmentTree_GetSum(1,1,n,l,r,last+1);
        if (now==last) return now+1;
        last=now;
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    while (q--) {
        scanf("%d",&op);
        if (op==2) {
            scanf("%d%d",&l,&r);
            printf("%lld\n",solve(l,r));
        }
        else {
            scanf("%d%d",&l,&r);
            SegmentTree_Modify(1,1,n,l,r);
        }
    }
    return 0;
}

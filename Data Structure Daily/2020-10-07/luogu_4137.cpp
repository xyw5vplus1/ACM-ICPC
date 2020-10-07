/*
题意：
n个数，m次询问，每次询问一个区间的mex（不在区间内的最小自然数）。
思路：
离线+线段树
经典离线数据结构思维题
对询问离线处理，按左端点分类。
从左到右枚举左端点，需要维护出以当前枚举下标i为左端点的时候，每个点[i..n]作为右端点的答案，这样查询的时候，只需要查询对应右端点位置的值即可。
关键在于左端点移动时对答案带来的改变。
当左端点向右移动一个单位时，考虑对哪些区间的答案产生影响。
注意到如果当前值为a[i],a[i]下一次出现的位置为nxt[i]，那么对[nxt[i]..n]范围内的点，答案不会产生变化，因为实际区间内出现的元素没有发生改变。
因此实际发生改变的区间为[i..nxt[i]-1]。
那么接下来分析对这些区间带来什么样的变化。
变化在于，没有了a[i]这个元素，那么如果原先的值小于等于a[i]，由mex的定义，答案不发生改变；如果原先的答案大于a[i]，那么此时a[i]成为了最新的没在区间内出现的最小的数了。
因此这些位置的答案都需要变成a[i]。
也就是说，我们需要做的事情其实是，维护一个数组，然后对某个区间取min，然后查询单点的值。
那么用线段树来做这件事再合适不过。
一开始脑残傻逼了以为是吉司机线段树，后来意识到了因为没有求区间和，所以不需要用吉司机那一套。
直接对每个区间打个lazy标记即可。
维护区间min的地方写残了WA了两发。

这套做法能够起作用的关键在于，随着左端点的单位移动，数组维护的答案变化是可以用数据结构很好地维护出来的。
是一个非常重要的思路。
枚举左端点，维护一个数组，记录从当前左端点到每个右端点的答案，再考虑左端点移动对答案带来的影响。
*/
#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
const int maxn=2e5+10;
const int INF=0x3f3f3f3f;
int a[maxn],c[maxn],nxt[maxn];
int n,m,l,r;
int ans[maxn];
vector<pair<int,int> > q[maxn];
map<int,bool> mp;
map<int,int> last;
struct node
{
    int mn;
    int lazy;
    void update(int v)
    {
        mn=min(v,mn);
        lazy=min(lazy,v);
    }
}b[4*maxn];
void pushup(int p)
{
    b[p].mn=min(b[lson(p)].mn,b[rson(p)].mn);
}
void build(int p,int l,int r)
{
    b[p].lazy=INF;
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
    if (b[p].lazy!=INF) {
        b[lson(p)].update(b[p].lazy);
        b[rson(p)].update(b[p].lazy);
        b[p].lazy=INF;
    }
}
void update(int p,int l,int r,int L,int R,int val)
{
    if (L<=l&&r<=R) {
        b[p].mn=min(b[p].mn,val);
        b[p].lazy=min(b[p].lazy,val);
        return ;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if (L<=mid) update(lson(p),l,mid,L,R,val);
    if (R>mid) update(rson(p),mid+1,r,L,R,val);
    pushup(p);
}
int query(int p,int l,int r,int pos)
{
    if (l==r) return b[p].mn;
    int mid=(l+r)>>1;
    pushdown(p);
    if (pos<=mid) return query(lson(p),l,mid,pos);
    else return query(rson(p),mid+1,r,pos);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) nxt[i]=-1;
    for (int i=1;i<=n;i++) {
        if (last.count(a[i])) {
            nxt[last[a[i]]]=i;
        }
        last[a[i]]=i;
    }
    for (int i=1;i<=m;i++) {
        scanf("%d%d",&l,&r);
        q[l].push_back(make_pair(r,i));
    }
    for (int i=1;i<=n;i++) {
        mp[a[i]]=true;
        int tem=c[i-1];
        while (mp[tem]) tem++;
        c[i]=tem;
    }
    build(1,1,n);
    for (int i=1;i<=n;i++) {
        for (int j=0;j<(int)q[i].size();j++) {
            int x=q[i][j].first,y=q[i][j].second;
            ans[y]=query(1,1,n,x);
        }
        if (nxt[i]!=-1) update(1,1,n,i,nxt[i]-1,a[i]);
        else update(1,1,n,i,n,a[i]);
    }
    for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}

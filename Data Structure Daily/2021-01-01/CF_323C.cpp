#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int maxtot=3e7+10;
int n,q;
int p1[maxn],p2[maxn],pos[maxn],a[maxn];
int root[maxn];
int l1,r1,l2,r2;
int tot=0;
struct node
{
    int lc,rc,cnt;
}b[maxtot];
void pushup(int p)
{
    b[p].cnt=b[b[p].lc].cnt+b[b[p].rc].cnt;
}
int update(int pre,int l,int r,int pos,int val)
{
    int cur=++tot;
    b[cur]=b[pre];
    if (l==r) {
        b[cur].cnt+=val;
        return cur;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) b[cur].lc=update(b[pre].lc,l,mid,pos,val);
    else b[cur].rc=update(b[cur].rc,mid+1,r,pos,val);
    pushup(cur);
    return cur;
}
int querySum(int p,int l,int r,int L,int R)
{
    if (L>R) return 0;
    if (L<=l&&r<=R) return b[p].cnt;
    int mid=(l+r)>>1;
    int ans=0;
    if (L<=mid) ans+=querySum(b[p].lc,l,mid,L,R);
    if (R>mid) ans+=querySum(b[p].rc,mid+1,r,L,R);
    return ans;
}
int f(int z,int x)
{
    return (z-1+x)%n+1;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&p1[i]);
    for (int i=1;i<=n;i++) scanf("%d",&p2[i]);
    for (int i=1;i<=n;i++) pos[p2[i]]=i;
    for (int i=1;i<=n;i++) a[i]=pos[p1[i]];
    root[0]=0;
    for (int i=1;i<=n;i++) root[i]=update(root[i-1],1,n,a[i],1);
    scanf("%d",&q);
    int lastans=0;
    int l_1,r_1,l_2,r_2;
    while (q--) {
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        l_1=f(l1,lastans),r_1=f(r1,lastans);
        l_2=f(l2,lastans),r_2=f(r2,lastans);
        l1=min(l_1,r_1); r1=max(l_1,r_1);
        l2=min(l_2,r_2); r2=max(l_2,r_2);
        //printf("debug %d %d %d %d\n",l1,r1,l2,r2);
        lastans=querySum(root[r1],1,n,l2,r2)-querySum(root[l1-1],1,n,l2,r2);
        printf("%d\n",lastans); lastans++;
    }
    return 0;
}

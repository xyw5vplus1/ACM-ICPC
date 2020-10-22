#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int maxtot=8e6;
struct node
{
    int lc,rc;
    int cnt;
}b[maxtot];
int tot=0;
int n,q;
int a[maxn],root[maxn],ans[maxn];
int last[maxn];
int l,r;
int build()
{
    int p=++tot;
    b[p].lc=b[p].rc=b[p].cnt=0;
    return p;
}
void pushup(int p)
{
    b[p].cnt=b[b[p].lc].cnt+b[b[p].rc].cnt;
}
int modify(int pre,int l,int r,int pos,int val)
{
    int cur=++tot;
    b[cur]=b[pre];
    if (l==r) {
        b[cur].cnt+=val;
        return cur;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) {
        if (!b[pre].lc) b[pre].lc=build();
        b[cur].lc=modify(b[pre].lc,l,mid,pos,val);
    }
    else {
        if (!b[pre].rc) b[pre].rc=build();
        b[cur].rc=modify(b[pre].rc,mid+1,r,pos,val);
    }
    pushup(cur);
    return cur;
}
int getCnt(int p,int l,int r,int L,int R)
{
    if (L>R) return 0;
    if (!p) return 0;
    if (L<=l&&r<=R) return b[p].cnt;
    int mid=(l+r)>>1;
    int ans=0;
    if (L<=mid) ans+=getCnt(b[p].lc,l,mid,L,R);
    if (R>mid) ans+=getCnt(b[p].rc,mid+1,r,L,R);
    return ans;
}
int findpos(int p,int l,int r,int sum,int up)
{
    if (l==r) return l;
    int mid=(l+r)>>1;
    if (sum+b[b[p].lc].cnt<up) return findpos(b[p].rc,mid+1,r,sum+b[b[p].lc].cnt,up);
    else return findpos(b[p].lc,l,mid,sum,up);
}
int getAns(int L,int R)
{
    int k=getCnt(root[L],1,n,L,R);
    //printf("cnt tot=%d\n",k);
    int need;
    if (k&1) need=k/2+1;
    else need=k/2;
    int pre=0;
    if (L>1) pre=getCnt(root[L],1,n,1,L-1);
    need+=pre;
    return findpos(root[L],1,n,0,need);
}
int T;
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&q);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        tot=0;
        root[n+1]=++tot;
        for (int i=0;i<maxn;i++) last[a[i]]=-1;
        for (int i=n;i>=1;i--) {
            root[i]=modify(root[i+1],1,n,i,1);
            if (last[a[i]]!=-1) {
                root[i]=modify(root[i],1,n,last[a[i]],-1);
            }
            last[a[i]]=i;
        }
        printf("Case #%d:",kase);
        int lastans=0;
        for (int q0=1;q0<=q;q0++){
            scanf("%d%d",&l,&r);
            int l0=min((lastans+l)%n+1,(lastans+r)%n+1);
            int r0=max((lastans+l)%n+1,(lastans+r)%n+1);
            //printf("debug %d %d\n",l0,r0);
            lastans=getAns(l0,r0);
            ans[q0]=lastans;
            //printf(" %d",lastans);
        }
        for (int i=1;i<=q;i++) printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}

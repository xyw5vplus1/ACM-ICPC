#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5;
struct SegmentTree
{
    int lc,rc;
    int cnt;
}b[maxn*40+5];
int exist[maxn+5],root[maxn+5],a[maxn+5],ans[maxn+5];
int tot=0;
int n,m,T;
int l0,r0,l1,r1;
int build(int l,int r)
{
    int p=++tot;
    if (l==r) {
        b[p].cnt=0; b[p].lc=b[p].rc=0; return p;
    }
    int mid=(l+r)>>1;
    b[p].lc=build(l,mid);
    b[p].rc=build(mid+1,r);
    b[p].cnt=b[b[p].lc].cnt+b[b[p].rc].cnt;
    return p;
}
int update(int pre,int l,int r,int pos,int val)
{
    int cur=++tot;
    b[cur]=b[pre];
    if (l==r) {
        b[cur].cnt+=val; return cur;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) b[cur].lc=update(b[pre].lc,l,mid,pos,val);
    else b[cur].rc=update(b[pre].rc,mid+1,r,pos,val);
    b[cur].cnt=b[b[cur].lc].cnt+b[b[cur].rc].cnt;
    return cur;
}
int query(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) return b[p].cnt;
    int mid=(l+r)>>1;
    int ans=0;
    if (L<=mid) ans+=query(b[p].lc,l,mid,L,R);
    if (R>mid) ans+=query(b[p].rc,mid+1,r,L,R);
    return ans;
}
int kth(int p,int l,int r,int k)
{
    if (l==r) {
        return l;
    }
    int mid=(l+r)>>1;
    if (b[b[p].lc].cnt>=k) return kth(b[p].lc,l,mid,k);
    else {
        k-=b[b[p].lc].cnt;
        return kth(b[p].rc,mid+1,r,k);
    }
}
bool check(int L,int cur,int need)
{
    if (query(root[L],1,n,L,cur)>=need) return true;
    return false;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int lastans=0;
        tot=0;
        root[n+1]=build(1,n);
        memset(exist,-1,sizeof(exist));
        for (int i=n;i>=1;i--) {
            if (exist[a[i]]!=-1) {
                root[i]=update(root[i+1],1,n,exist[a[i]],-1);
                root[i]=update(root[i],1,n,i,1);
            }
            else root[i]=update(root[i+1],1,n,i,1);
            exist[a[i]]=i;
        }
        for (int i=1;i<=m;i++) {
            scanf("%d%d",&l0,&r0);
            l1=min((l0+lastans)%n+1,(r0+lastans)%n+1);
            r1=max((l0+lastans)%n+1,(r0+lastans)%n+1);
            //printf("debug %d %d\n",l1,r1);
            int k=query(root[l1],1,n,l1,r1);
            ans[i]=kth(root[l1],1,n,(k+1)>>1);
            lastans=ans[i];
        }
        printf("Case #%d:",kase);
        for (int i=1;i<=m;i++) printf(" %d",ans[i]);
        printf("\n");
        //printf("lalala\n");
    }
    return 0;
}

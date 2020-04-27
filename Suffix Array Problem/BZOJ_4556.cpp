#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int INF=1e9;
const int maxtot=3e6+10;
int oldrk[maxn],id[maxn],px[maxn],cnt[maxn];
int sa[maxn],rk[maxn],ht[maxn];
int root[maxn];
int n,m;
int a0,b0,c0,d0;
char s[maxn];
int lg[maxn];
int dp[maxn][20];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
bool cmp(int x,int y,int w)
{
    return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];
}
void SA(char s[],int n)
{
    int m=300,p;
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) ++cnt[rk[i]=s[i]];
    for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
    for (int w=1;w<n;w<<=1,m=p) {  // m=p 就是优化计数排序值域
        p=0;
        for (int i=n;i>n-w;i--) id[++p]=i;
        for (int i=1;i<=n;i++)
            if (sa[i]>w) id[++p]=sa[i]-w;
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=n;i++) ++cnt[px[i]=rk[id[i]]];
        for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for (int i=n;i>=1;i--) sa[cnt[px[i]]--]=id[i];
        memcpy(oldrk,rk,sizeof(rk));
        for (int p=0,i=1;i<=n;i++)
            rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
    }
}
void calcH(char a[],int n)
{
    for (int i=1,j=0;i<=n;i++) {
        if (j) --j;
        while (a[i+j]==a[sa[rk[i]-1]+j]) ++j;
        ht[rk[i]]=j;
    }
}
void InitST(int a[],int n)
{
    for (int i=1;i<=n;i++) dp[i][0]=a[i];
    for (int j=1;j<=lg[n];j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
        dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmqMin(int l,int r)
{
    if (l>r) return INF;
    int k=lg[r-l+1];
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
struct segmentTree
{
    int lc,rc;
    int cnt;
}b[maxtot];
int tot=0;
void pushup(int cur)
{
    b[cur].cnt=b[b[cur].lc].cnt+b[b[cur].rc].cnt;
}
int InsertNode(int pre,int l,int r,int pos,int val)
{
    int cur=++tot;
    b[cur]=b[pre];
    if (l==r) {
        b[cur].cnt+=val;
        return cur;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) b[cur].lc=InsertNode(b[pre].lc,l,mid,pos,val);
    else b[cur].rc=InsertNode(b[pre].rc,mid+1,r,pos,val);
    pushup(cur);
    return cur;
}
int calc(int cur,int pre,int l,int r,int L,int R)
{
    if (L>R||b[cur].cnt-b[pre].cnt==0) return 0;
    if (L<=l&&r<=R) return b[cur].cnt-b[pre].cnt;
    int mid=(l+r)>>1;
    int ans=0;
    if (L<=mid) ans+=calc(b[cur].lc,b[pre].lc,l,mid,L,R);
    if (R>mid) ans+=calc(b[cur].rc,b[pre].rc,mid+1,r,L,R);
    return ans;
}
int getLessThan(int cur,int pre,int l,int r,int val)
{
    if (l==r) {
        return 0;
    }
    int mid=(l+r)>>1;
    if (val<=mid) return getLessThan(b[cur].lc,b[pre].lc,l,mid,val);
    else {
        return b[b[cur].lc].cnt-b[b[pre].lc].cnt+getLessThan(b[cur].rc,b[pre].rc,mid+1,r,val);
    }
}
int getKth(int cur,int pre,int l,int r,int k)
{
    if (l==r) return l;
    int mid=(l+r)>>1;
    if (b[b[cur].lc].cnt-b[b[pre].lc].cnt>=k) return getKth(b[cur].lc,b[pre].lc,l,mid,k);
    else {
        k-=b[b[cur].lc].cnt-b[b[pre].lc].cnt;
        return getKth(b[cur].rc,b[pre].rc,mid+1,r,k);
    }
}
int getL(int pos,int d)
{
    int l=1,r=pos;
    while (l<r) {
        int mid=((l+r)>>1);
        if (rmqMin(mid+1,pos)>=d) r=mid;
        else l=mid+1;
    }
    return l;
}
int getR(int pos,int d)
{
    int l=pos,r=n;
    while (l<r) {
        int mid=((l+r+1)>>1);
        if (rmqMin(pos+1,mid)>=d) l=mid;
        else r=mid-1;
    }
    return l;
}
bool check(int d)
{
    int l0=getL(rk[c0],d),r0=getR(rk[c0],d);
    //printf("debug %d L=%d R=%d\n",d,l0,r0);
    /*int cnt=getLessThan(root[r0],root[l0-1],1,n,a0);
    if (cnt==r0-l0+1) return false;
    int tem=getKth(root[r0],root[l0-1],1,n,cnt+1);
    //printf("min_a0=%d\n",tem);
    if (b0-tem+1>=d) return true;
    else return false;*/
    if (calc(root[r0],root[l0-1],1,n,a0,b0-d+1)>0) return true;
    return false;
}
int main()
{
    lg[0]=-1;
    for (int i=1;i<maxn;i++)
        if (i&(i-1)) lg[i]=lg[i-1];
        else lg[i]=lg[i-1]+1;
    //scanf("%d%d",&n,&m);
    n=read(); m=read();
    scanf("%s",s+1);
    SA(s,n);
    calcH(s,n);
    InitST(ht,n);
    //for (int i=1;i<=n;i++) printf("%d ",ht[i]); printf("\n");
    root[0]=0;
    for (int i=1;i<=n;i++) root[i]=InsertNode(root[i-1],1,n,sa[i],1);
    int l,r,mid;
    while (m--) {
        //scanf("%d%d%d%d",&a0,&b0,&c0,&d0);
        a0=read(); b0=read(); c0=read(); d0=read();
        l=0,r=min(d0-c0+1,b0-a0+1);
        while (l<r) {
            mid=((l+r+1)>>1);
            if (check(mid)) l=mid;
            else r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int INF=1e9;
const int maxtot=2e6;
int oldrk[maxn],px[maxn],id[maxn],cnt[maxn];
int rk[maxn],ht[maxn],sa[maxn];
int dp[maxn][20];
int lg[maxn];
int root[maxn];
int T,n,q,l,r,k;
char s[maxn];
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
int rmqMn(int l,int r)
{
    if (r<l) return INF;
    int k=lg[r-l+1];
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
struct node
{
    int lc,rc;
    int cnt;
}b[maxtot];
int tot=0;
void pushup(int p)
{
    b[p].cnt=b[b[p].lc].cnt+b[b[p].rc].cnt;
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
int Kth(int cur,int pre,int l,int r,int k)
{
    if (l==r) {
        return l;
    }
    int mid=(l+r)>>1;
    if (b[b[cur].lc].cnt-b[b[pre].lc].cnt>=k)
        return Kth(b[cur].lc,b[pre].lc,l,mid,k);
    else {
        k-=(b[b[cur].lc].cnt-b[b[pre].lc].cnt);
        return Kth(b[cur].rc,b[pre].rc,mid+1,r,k);
    }
}
int getLpos(int pos,int len)
{
    //printf("debug getL %d %d\n",pos,len);
    int l=1,r=pos;
    while (l<r) {
        int mid=(l+r)>>1;
        if (rmqMn(mid+1,pos)>=len) r=mid;
        else l=mid+1;
    }
    return l;
}
int getRpos(int pos,int len)
{
    //printf("debug getR %d %d\n",pos,len);
    int l=pos,r=n;
    while (l<r) {
        int mid=(l+r+1)>>1;
        if (rmqMn(pos+1,mid)>=len) l=mid;
        else r=mid-1;
    }
    return l;
}
int main()
{
    lg[0]=-1;
    for (int i=1;i<maxn;i++)
        if (i&(i-1)) lg[i]=lg[i-1];
        else lg[i]=lg[i-1]+1;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);
        SA(s,n);
        calcH(s,n);
        InitST(ht,n);
        for (int i=1;i<=n;i++) rk[sa[i]]=i;
        //for (int i=1;i<=n;i++) printf("%d ",sa[i]); printf("\n");
        tot=0;
        root[0]=0;
        for (int i=1;i<=n;i++) root[i]=InsertNode(root[i-1],1,n,sa[i],1);
        int l0,r0;
        while (q--) {
            scanf("%d%d%d",&l,&r,&k);
            l0=getLpos(rk[l],r-l+1);
            r0=getRpos(rk[l],r-l+1);
            //printf("debug %d %d\n",l0,r0);
            if (r0-l0+1<k) printf("-1\n");
            else printf("%d\n",Kth(root[r0],root[l0-1],1,n,k));
        }
    }
    return 0;
}

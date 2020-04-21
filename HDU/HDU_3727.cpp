#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=1e5;
const int maxm=205000;
vector<int> v[maxm+5];
int e[maxn+5],root[maxn+5],type[maxm+5];
int n,m,sz,n0,tot,x;
ll ans1,ans2,ans3;
char s[100];
void Init()
{
    tot=0; n0=0; ans1=0; ans2=0; ans3=0;
    for (int i=1;i<=n;i++) v[i].clear();
}
struct SegmentTree
{
    int lc,rc;
    int cnt;
}b[maxn*20];
int build(int l,int r)
{
    int p=++tot;
    if (l==r) {
        b[p].cnt=0; return p;
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
int kth(int cur,int pre,int l,int r,int k)
{
    if (l==r) return e[l];
    int mid=(l+r)>>1;
    if (b[b[cur].lc].cnt-b[b[pre].lc].cnt>=k) return kth(b[cur].lc,b[pre].lc,l,mid,k);
    else {
        k-=b[b[cur].lc].cnt-b[b[pre].lc].cnt;
        return kth(b[cur].rc,b[pre].rc,mid+1,r,k);
    }
}
int queryK(int cur,int pre,int l,int r,int val)
{
    if (l==r) return 0;
    int mid=(l+r)>>1;
    if (e[mid]>=val) return queryK(b[cur].lc,b[pre].lc,l,mid,val);
    else return queryK(b[cur].rc,b[pre].rc,mid+1,r,val)+b[b[cur].lc].cnt-b[b[pre].lc].cnt;
}
int getPos(int val)
{
    return lower_bound(e+1,e+sz+1,val)-e;
}
int main()
{
    int kase=0;
    while (scanf("%d",&n)!=EOF) {
        kase++;
        Init();
        for (int i=1;i<=n;i++) {
            scanf("%s",s);
            if (s[0]=='I') {
                type[i]=0;
                scanf("%d",&x);
                v[i].push_back(x);
                e[++n0]=x;
            }
            else if (s[6]=='1') {
                type[i]=1;
                scanf("%d",&x);
                v[i].push_back(x);
                scanf("%d",&x);
                v[i].push_back(x);
                scanf("%d",&x);
                v[i].push_back(x);
            }
            else if (s[6]=='2') {
                type[i]=2;
                scanf("%d",&x);
                v[i].push_back(x);
            }
            else if (s[6]=='3') {
                type[i]=3;
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        sort(e+1,e+n0+1);
        sz=unique(e+1,e+n0+1)-(e+1);
        root[0]=build(1,sz);
        printf("Case %d:\n",kase);
        int cur=0;
        for (int i=1;i<=n;i++) {
            if (type[i]==0) {
                ++cur;
                root[cur]=update(root[cur-1],1,sz,getPos(v[i][0]),1);
            }
            else if (type[i]==1) {
                int l=v[i][0],r=v[i][1],k=v[i][2];
                ans1+=kth(root[r],root[l-1],1,sz,k);
            }
            else if (type[i]==2) {
                int x=v[i][0];
                ans2+=queryK(root[cur],root[0],1,sz,x)+1;
            }
            else if (type[i]==3) {
                int k=v[i][0];
                ans3+=kth(root[cur],root[0],1,sz,k);
            }
        }
        printf("%lld\n%lld\n%lld\n",ans1,ans2,ans3);
    }
    return 0;
}

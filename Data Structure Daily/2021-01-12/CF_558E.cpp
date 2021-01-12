#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a-1;i>=b;i--)
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int maxn=1e5+10;
int n,m,l,r,op;
char s[maxn];
struct node
{
    int cnt[26];
    int lazy;
    void update(int l,int r,int ch)
    {
        rep(i,0,26) cnt[i]=0;
        cnt[ch]=r-l+1;
        lazy=ch;
    }
}b[maxn<<2];
void pushup(int p)
{
    rep(i,0,26) b[p].cnt[i]=b[lson(p)].cnt[i]+b[rson(p)].cnt[i];
}
void build(int p,int l,int r)
{
    b[p].lazy=-1;
    if (l==r) {
        rep(i,0,26) b[p].cnt[i]=0;
        b[p].cnt[s[l]-'a']++;
        return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    pushup(p);
}
void pushdown(int p,int l,int r)
{
    if (b[p].lazy!=-1) {
        int mid=(l+r)>>1;
        b[lson(p)].update(l,mid,b[p].lazy);
        b[rson(p)].update(mid+1,r,b[p].lazy);
        b[p].lazy=-1;
    }
}
void segmentCover(int p,int l,int r,int L,int R,int ch)
{
    if (L>R) return ;
    if (L<=l&&r<=R) {
        b[p].update(l,r,ch);
        return ;
    }
    int mid=(l+r)>>1;
    pushdown(p,l,r);
    if (L<=mid) segmentCover(lson(p),l,mid,L,R,ch);
    if (R>mid) segmentCover(rson(p),mid+1,r,L,R,ch);
    pushup(p);
}
node getNode(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) return b[p];
    int mid=(l+r)>>1;
    pushdown(p,l,r);
    if (R<=mid) return getNode(lson(p),l,mid,L,R);
    else if (L>mid) return getNode(rson(p),mid+1,r,L,R);
    else {
        node e;
        node e1=getNode(lson(p),l,mid,L,R);
        node e2=getNode(rson(p),mid+1,r,L,R);
        rep(i,0,26) e.cnt[i]=e1.cnt[i]+e2.cnt[i];
        return e;
    }
}
void dfs(int p,int l,int r)
{
    if (l==r) {
        rep(i,0,26)
        if (b[p].cnt[i]) {
            printf("%c",'a'+i);
            break;
        }
        return ;
    }
    pushdown(p,l,r);
    int mid=(l+r)>>1;
    dfs(lson(p),l,mid);
    dfs(rson(p),mid+1,r);
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    build(1,1,n);
    rep(_,0,m) {
        scanf("%d%d%d",&l,&r,&op);
        if (op==1) {
            node e=getNode(1,1,n,l,r);
            int cur=l;
            rep(i,0,26) {
                segmentCover(1,1,n,cur,cur+e.cnt[i]-1,i);
                cur+=e.cnt[i];
            }
        }
        else {
            node e=getNode(1,1,n,l,r);
            int cur=r;
            rep(i,0,26) {
                segmentCover(1,1,n,cur-e.cnt[i]+1,cur,i);
                cur-=e.cnt[i];
            }
        }
    }
    dfs(1,1,n);
    return 0;
}

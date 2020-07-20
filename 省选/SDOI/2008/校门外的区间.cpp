#include<cstdio>
#include<algorithm>
#include<vector>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
const int maxn=65536*2;
vector<int> ans;
char op[10],s[10];
struct node
{
    int val;
    int cover,trans;
}b[4*maxn+5];
void build(int p,int l,int r)
{
    b[p].cover=-1; b[p].trans=0;
    if (l==r) {
        b[p].val=0; return ;
    }
    int mid=(l+r)>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
}
void pushdown(int p)
{
    if (b[p].cover!=-1) {
        b[lson(p)].val=b[p].cover;
        b[rson(p)].val=b[p].cover;
            b[lson(p)].cover=b[p].cover;
            b[rson(p)].cover=b[p].cover;
        b[lson(p)].trans=0;
        b[rson(p)].trans=0;
    }
    else if (b[p].trans){
        b[lson(p)].val=1-b[lson(p)].val; b[rson(p)].val=1-b[rson(p)].val;
        if (b[lson(p)].cover!=-1) b[lson(p)].cover=1-b[lson(p)].cover;
        else b[lson(p)].trans^=1;
        if (b[rson(p)].cover!=-1) b[rson(p)].cover=1-b[rson(p)].cover;
        else b[rson(p)].trans^=1;
    }
    b[p].cover=-1; b[p].trans=0;
}
void cover(int p,int l,int r,int L,int R,int val)
{
    if (L<=l&&r<=R) {
        b[p].val=val; b[p].cover=val; b[p].trans=0;
        return ;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if (L<=mid) cover(lson(p),l,mid,L,R,val);
    if (R>mid) cover(rson(p),mid+1,r,L,R,val);
}
void trans(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) {
        b[p].val=1-b[p].val;
        if (b[p].cover!=-1) b[p].cover=1-b[p].cover;
        else b[p].trans^=1;
        return ;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if (L<=mid) trans(lson(p),l,mid,L,R);
    if (R>mid) trans(rson(p),mid+1,r,L,R);
}
int query(int p,int l,int r,int pos)
{
   if (l==r) return b[p].val;
   pushdown(p);
   int mid=(l+r)>>1;
   if (pos<=mid) return query(lson(p),l,mid,pos);
   else return query(rson(p),mid+1,r,pos);
}
int main()
{
    build(1,0,maxn);
    while (scanf("%s",op)!=EOF){
        int l,r;
        getchar(); char ch1=getchar(); scanf("%d",&l); getchar(); scanf("%d",&r); char ch2=getchar();
        if (ch1=='[') l*=2;
        else l=l*2+1;
        if (ch2==']') r*=2;
        else r=r*2-1;
        //printf("%d %d\n",l,r);
        if (op[0]=='U') cover(1,0,maxn,l,r,1);
        else if (op[0]=='I') {
            if (l>=1) cover(1,0,maxn,0,l-1,0);
            if (r<maxn) cover(1,0,maxn,r+1,maxn,0);
        }
        else if (op[0]=='D') cover(1,0,maxn,l,r,0);
        else if (op[0]=='C') {
            trans(1,0,maxn,0,maxn);
            if (l>=1) cover(1,0,maxn,0,l-1,0);
            if (r<maxn) cover(1,0,maxn,r+1,maxn,0);
        }
        else if (op[0]=='S') trans(1,0,maxn,l,r);
    }
    for (int i=0;i<maxn;i++)
        if (query(1,0,maxn,i)) ans.push_back(i);
    if (!ans.size()) {
        printf("empty set\n");
        return 0;
    }
    int last=-1;
    for (int i=0;i<ans.size();i++) {
        if (i==0) continue;
        if (ans[i]-ans[i-1]>1) {
            int l=ans[last+1],r=ans[i-1];
            if (l&1) printf("(%d",(l-1)/2);
            else printf("[%d",l/2);
            printf(",");
            if (r&1) printf("%d) ",(r+1)/2);
            else printf("%d] ",r/2);
            last=i-1;
        }
    }
    int l=ans[last+1],r=ans[ans.size()-1];
    if (l&1) printf("(%d",(l-1)/2);
    else printf("[%d",l/2);
    printf(",");
    if (r&1) printf("%d) ",(r+1)/2);
    else printf("%d] ",r/2);
    return 0;
}

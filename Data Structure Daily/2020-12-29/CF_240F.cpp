#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
const int maxn=1e5+10;
char s[maxn];
int n,m,l,r;
struct node
{
    char ch,lazy;
    int cnt[26];
}b[maxn<<2];
void updatePoint(int p,int l,int r,char ch0)
{
    for (int i=0;i<26;i++) b[p].cnt[i]=0;
    b[p].cnt[ch0-'a']=r-l+1;
    b[p].ch=ch0;
    b[p].lazy=ch0;
}
void pushup(int p)
{
    for (int i=0;i<26;i++)
        b[p].cnt[i]=b[lson(p)].cnt[i]+b[rson(p)].cnt[i];
}
void build(int p,int l,int r)
{
    //printf("debug %d %d %d\n",p,l,r);
    b[p].lazy='0';
    if (l==r) {
        for (int i=0;i<26;i++) b[p].cnt[i]=0;
        b[p].ch=s[l];
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
    if (b[p].lazy!='0') {
        char ch0=b[p].lazy;
        int mid=(l+r)>>1;
        updatePoint(lson(p),l,mid,ch0);
        updatePoint(rson(p),mid+1,r,ch0);
        b[p].lazy='0';
    }
}
void coverSeg(int p,int l,int r,int L,int R,char ch0)
{
    if (L>R) return ;
    if (L<=l&&r<=R) {
        updatePoint(p,l,r,ch0);
        return ;
    }
    pushdown(p,l,r);
    int mid=(l+r)>>1;
    if (L<=mid) coverSeg(lson(p),l,mid,L,R,ch0);
    if (R>mid) coverSeg(rson(p),mid+1,r,L,R,ch0);
    pushup(p);
}
node getPoint(int p,int l,int r,int L,int R)
{
    if (L<=l&&r<=R) return b[p];
    pushdown(p,l,r);
    int mid=(l+r)>>1;
    if (R<=mid) return getPoint(lson(p),l,mid,L,R);
    else if (L>mid) return getPoint(rson(p),mid+1,r,L,R);
    else {
        node e1=getPoint(lson(p),l,mid,L,R);
        node e2=getPoint(rson(p),mid+1,r,L,R);
        node e;
        for (int i=0;i<26;i++) e.cnt[i]=e1.cnt[i]+e2.cnt[i];
        return e;
    }
}
void change(int l,int r)
{
    node e=getPoint(1,1,n,l,r);
    //for (int i=0;i<26;i++) printf("%d ",e.cnt[i]); printf("\n");
    int cnt=0;
    int val=-1;
    for (int i=0;i<26;i++)
        if (e.cnt[i]&1) {
            cnt++; val=i;
        }
    if (cnt>1) return ;
    int cur=l;
    for (int i=0;i<26;i++) {
        //printf("debug %d %d\n",cur,cur+e.cnt[i]/2-1);
        coverSeg(1,1,n,cur,cur+e.cnt[i]/2-1,'a'+i);
        cur+=e.cnt[i]/2;
    }
    if (val!=-1) {
        //printf("debug %d %d\n",cur,cur);
        coverSeg(1,1,n,cur,cur,'a'+val);
        cur++;
    }
    for (int i=25;i>=0;i--) {
        //printf("debug %d %d\n",cur,cur+e.cnt[i]/2-1);
        coverSeg(1,1,n,cur,cur+e.cnt[i]/2-1,'a'+i);
        cur+=e.cnt[i]/2;
    }
    return ;
}
void dfs(int p,int l,int r)
{
    if (l==r) {
        printf("%c",b[p].ch);
        return ;
    }
    pushdown(p,l,r);
    int mid=(l+r)>>1;
    dfs(lson(p),l,mid);
    dfs(rson(p),mid+1,r);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    build(1,1,n);
    while (m--) {
        scanf("%d%d",&l,&r);
        change(l,r);
        //dfs(1,1,n); //printf("\n");
    }
    dfs(1,1,n);
    return 0;
}

#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#pragma GCC optimize ("O2")
#pragma comment(linker,"/STACK:1024000000,1024000000")
using namespace std;
const int maxn=2e5+10;
const int maxtot=maxn*200;
vector<int> v[maxn];
char s[maxn];
int trie[maxn][26];
int tot=0,tim=0;
int n,q,op,k,l,r,x,y;
int st[maxn],ed[maxn];
int a[maxn],treep[maxn];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
void InsertTrie(int k)
{
    int len=strlen(s);
    int u=1,x;
    for (int i=0;i<len;i++) {
        x=s[i]-'a';
        if (!trie[u][x]) trie[u][x]=++tot;
        u=trie[u][x];
    }
    v[u].push_back(k);
}
void dfs(int u)
{
    if (v[u].size()) {
        st[u]=tim+1;
        for (auto e:v[u]) {
            a[++tim]=e; treep[e]=tim;
        }
    }
    for (int i=0;i<26;i++) {
        if (trie[u][i]) {
            dfs(trie[u][i]);
            if (!st[u]) st[u]=st[trie[u][i]];
        }
    }
    ed[u]=tim;
}
struct SegmentTree
{
    int lc,rc;
    int cnt;
}b[maxtot];
void pushup(int p)
{
    b[p].cnt=b[b[p].lc].cnt+b[b[p].rc].cnt;
}
void ModifyNode(int p,int l,int r,int pos,int val)
{
    if (l==r) {
        b[p].cnt+=val;
        return ;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) {
        if (!b[p].lc) b[p].lc=++tot;
        ModifyNode(b[p].lc,l,mid,pos,val);
    }
    else {
        if (!b[p].rc) b[p].rc=++tot;
        ModifyNode(b[p].rc,mid+1,r,pos,val);
    }
    pushup(p);
}
int calc(int p,int l,int r,int L,int R)
{
    if (L>R||!b[p].cnt) return 0;
    if (L<=l&&r<=R) return b[p].cnt;
    int mid=(l+r)>>1;
    int ans=0;
    if (L<=mid) {
        if (b[p].lc) ans+=calc(b[p].lc,l,mid,L,R);
    }
    if (R>mid){
        if (b[p].rc) ans+=calc(b[p].rc,mid+1,r,L,R);
    }
    return ans;
}
int rt[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int num,int v)
{
    while (x<=n) {
        ModifyNode(rt[x],1,n,num,v);
        x+=lowbit(x);
    }
}
int getCnt(int L,int R,int l0,int r0)
{
    int ans=0;
    for (int i=R;i;i-=lowbit(i)) ans+=calc(rt[i],1,n,l0,r0);
    for (int i=L-1;i;i-=lowbit(i)) ans-=calc(rt[i],1,n,l0,r0);
    return ans;
}
int findK(int k)
{
    int len=strlen(s);
    int u=1,x;
    for (int i=0;i<k;i++) {
        x=s[i]-'a';
        u=trie[u][x];
    }
    return u;
}
int main()
{
    n=read(); q=read();
    tot=1;
    for (int i=1;i<=n;i++) {
        scanf("%s",s);
        InsertTrie(i);
    }
    dfs(1);
    for (int i=1;i<=n;i++) rt[i]=++tot;
    for (int i=1;i<=n;i++) update(i,a[i],1);
    int p,tx,ty;
    while (q--) {
        op=read();
        if (op==2) {
            scanf("%s",s);
            k=read(); l=read(); r=read();
            p=findK(k);
            //printf("debug %d\n",p);
            if (!p) printf("0\n");
            else {
                printf("%d\n",getCnt(st[p],ed[p],l,r));
            }
        }
        else {
            x=read(); y=read();
            if (x==y) continue;
            tx=treep[x],ty=treep[y];
            update(tx,x,-1); update(tx,y,1);
            update(ty,y,-1); update(ty,x,1);
            a[tx]=y; a[ty]=x;
            treep[x]=ty; treep[y]=tx;
        }
    }
    return 0;
}
/*
7 100
aa
a
abac
aabc
bca
aba
aaaa
2 a 1 1 3
*/


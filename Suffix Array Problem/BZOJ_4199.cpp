#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
typedef long long ll;
const ll INF=2e18;
vector<int> v[maxn];
int oldrk[maxn],px[maxn],id[maxn],cnt[maxn];
int sa[maxn],rk[maxn],ht[maxn];
ll ans1[maxn],ans2[maxn];
int father[maxn],sz[maxn],mx[maxn],mn[maxn];
int n;
char s[maxn];
int a[maxn];
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
int _find(int x)
{
    if (x==father[x]) return x;
    father[x]=_find(father[x]);
    return father[x];
}
void _merge(int u,int v) // 令u严格小于v
{
    u=_find(u); v=_find(v);
    father[v]=u;
    sz[u]+=sz[v];
    mx[u]=max(mx[u],mx[v]);
    mn[u]=min(mn[u],mn[v]);
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    SA(s,n);
    calcH(s,n);
    for (int i=1;i<=n;i++) {
        father[i]=i; mx[i]=a[sa[i]]; mn[i]=a[sa[i]]; sz[i]=1;
    }
    for (int i=1;i<=n;i++)
        v[ht[i]].push_back(i);
    int u0,v0;
    memset(ans1,0,sizeof(ans1));
    for (int i=0;i<=n;i++) ans2[i]=-INF;
    for (int r=n-1;r>=0;r--) {
        for (int j=0;j<v[r].size();j++) {
            if (_find(v[r][j])!=1) {
                u0=_find(v[r][j])-1; v0=v[r][j];
                //printf("debug %d %d\n",_find(u0),_find(v0));
                ans1[r]+=1LL*sz[_find(u0)]*sz[_find(v0)];
                ans2[r]=max(ans2[r],1LL*mx[_find(u0)]*mx[_find(v0)]);
                ans2[r]=max(ans2[r],1LL*mn[_find(u0)]*mn[_find(v0)]);
                _merge(u0,v0);
            }
        }
    }
    for (int i=n-1;i>=0;i--) {
        ans1[i]=ans1[i]+ans1[i+1];
        ans2[i]=max(ans2[i],ans2[i+1]);
    }
    for (int i=0;i<n;i++)
        if (ans1[i]!=0) printf("%lld %lld\n",ans1[i],ans2[i]);
        else printf("0 0\n");
    return 0;
}

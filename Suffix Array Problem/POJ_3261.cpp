#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5;
int cnt[maxn+5];
int rk[maxn+5],id[maxn+5],oldrk[maxn+5],sa[maxn+5],px[maxn+5];
int a[maxn+5],ht[maxn+5];
int n,k;
bool cmp(int x, int y, int w)
{
    return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];
}
void SA(int s[],int n)
{
    int m=300,p;
    memset(cnt,0,sizeof(cnt));
    //printf("start SA:\n");
    for (int i=1;i<=n;i++) ++cnt[rk[i]=s[i]];
    //printf("debug SA:\n");
    for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
    //printf("debug SA:\n");
    for (int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
    //printf("Sa:\n");
    for (int w=1;w<n;w<<=1,m=p) {  // m=p 就是优化计数排序值域
        //printf("debug %d\n",w);
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
void calcH(int a[],int n)
{
    for (int i=1,j=0;i<=n;i++) {
        if (j) --j;
        while (a[i+j]==a[sa[rk[i]-1]+j]) ++j;
        ht[rk[i]]=j;
    }
}
bool check(int d)
{
    int cnt=1;
    for (int i=1;i<=n;i++)
    if (ht[i]>=d) {
        cnt++;
        if (cnt>=k) return true;
    }
    else cnt=1;
    return false;
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    SA(a,n);
    calcH(a,n);
    int l=1,r=n;
    while (l<r) {
        int mid=(l+r+1)>>1;
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}

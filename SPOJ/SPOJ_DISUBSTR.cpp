#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int oldrk[maxn+5],rk[maxn+5],ht[maxn+5],sa[maxn+5],id[maxn+5],px[maxn+5];
int cnt[maxn+5];
char s[maxn+5];
int n;
bool cmp(int x, int y, int w)
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
int T;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%s",s+1);
        n=strlen(s+1);
        SA(s,n);
        calcH(s,n);
        long long ans=0;
        for (int i=1;i<=n;i++) ans=(ans+n-sa[i]+1-ht[i]);
        printf("%lld\n",ans);
    }
    return 0;
}

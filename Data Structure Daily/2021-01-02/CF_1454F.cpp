#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],e[maxn];
vector<int> v1[maxn],v2[maxn];
int l[maxn],r[maxn];
int s[maxn];
int T,n;
int pre[maxn],suf[maxn];
void setTable()
{
    int h=0;
    for (int i=0;i<=n;i++) s[i]=0;
    for (int i=0;i<=n;i++) l[i]=r[i]=0;
    for (int i=1;i<=n;i++) {
        while (h>0&&a[i]<a[s[h-1]]) {
            r[s[h-1]]=i-1; h--;
        }
        s[h++]=i;
    }
    while (h>0) {
        r[s[h-1]]=n; h--;
    }
    for (int i=n;i>=1;i--) {
        while (h>0&&a[i]<a[s[h-1]]) {
            l[s[h-1]]=i+1; h--;
        }
        s[h++]=i;
    }
    while (h>0) {
        l[s[h-1]]=1; h--;
    }
}
bool isExist1(int L,int R,int v)
{
    return lower_bound(v1[v].begin(),v1[v].end(),L)!=upper_bound(v1[v].begin(),v1[v].end(),R);
}
bool isExist2(int L,int R,int v)
{
    return lower_bound(v2[v].begin(),v2[v].end(),L)!=upper_bound(v2[v].begin(),v2[v].end(),R);
}
int getPos1(int L,int R,int v)
{
    return lower_bound(v1[v].begin(),v1[v].end(),L)-v1[v].begin();
}
int getPos2(int L,int R,int v)
{
    return lower_bound(v2[v].begin(),v2[v].end(),L)-v2[v].begin();
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) e[i]=a[i];
        sort(e+1,e+n+1);
        int n0=unique(e+1,e+n+1)-(e+1);
        for (int i=1;i<=n;i++) a[i]=lower_bound(e+1,e+n0+1,a[i])-e;
        pre[0]=0; suf[n+1]=0;
        for (int i=1;i<=n;i++) pre[i]=max(pre[i-1],a[i]);
        for (int i=n;i>=1;i--) suf[i]=max(suf[i+1],a[i]);
        for (int i=1;i<=n;i++) v1[pre[i]].push_back(i);
        for (int i=1;i<=n;i++) v2[suf[i]].push_back(i);
        setTable();
        /*for (int i=1;i<=n;i++) {
            printf("debug stack %d %d %d\n",i,l[i],r[i]);
        }*/
        int ans=-1;
        for (int i=1;i<=n;i++) {
            if (isExist1(l[i]-1,i-1,a[i])&&isExist2(i+1,r[i]+1,a[i])) {
                ans=i; break;
            }
        }
        if (ans!=-1) {
            printf("YES\n");
            int L=v1[a[ans]][getPos1(l[ans]-1,ans-1,a[ans])];
            int R=v2[a[ans]][getPos2(ans+1,r[ans]+1,a[ans])];
            printf("%d %d %d\n",L,R-L-1,n-R+1);
        }
        else printf("NO\n");
        for (int i=1;i<=n;i++) v1[pre[i]].clear();
        for (int i=1;i<=n;i++) v2[suf[i]].clear();
    }
    return 0;
}

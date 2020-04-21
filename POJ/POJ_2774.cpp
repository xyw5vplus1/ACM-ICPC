#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int oldrk[maxn],cnt[maxn],ht[maxn],sa[maxn],rk[maxn],id[maxn],px[maxn];
char s[maxn],s1[maxn],s2[maxn];
int lg[maxn];
int dp[maxn][20];
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
void initST(int a[],int n)
{
    for (int i=1;i<=n;i++) dp[i][0]=a[i];
    for (int j=1;j<=lg[n];j++)
        for (int i=1;i+(1<<j)-1<=n;i++)
        dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int getMn(int l,int r)
{
    int k=lg[r-l+1];
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    int len1=strlen(s1+1);
    int len2=strlen(s2+1);
    for (int i=1;i<=len1;i++) s[i]=s1[i];
    s1[len1+1]='$';
    for (int i=1;i<=len2;i++) s[len1+i+1]=s2[i];
    s[len1+1+len2+1]='\0';
    int len=len1+len2+1;
    SA(s,len);
    calcH(s,len);
    lg[0]=-1;
    for (int i=1;i<=len;i++)
        if (i&(i-1)) lg[i]=lg[i-1];
        else lg[i]=lg[i-1]+1;
    initST(ht,len);
    int last1=-1,last2=-1;
    int ans=0;
    for (int i=1;i<=len;i++)
        if (sa[i]<=len1) {
            if (last2!=-1) ans=max(ans,getMn(last2+1,i));
            last1=i;
        }
        else if (sa[i]>len1+1){
            if (last1!=-1) ans=max(ans,getMn(last1+1,i));
            last2=i;
        }
    printf("%d\n",ans);
    return 0;
}

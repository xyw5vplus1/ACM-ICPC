#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
const int maxm=100;
int mp[maxn+5][maxm+5],a[maxn+5][maxm+5];
int pre[maxm+5],len[maxn+5];
int s[maxm+5];
int tem;
int n;
void calc_pre(int m)
{
    pre[1]=0;
    for (int i=2,j=0;i<=m;i++) {
        while (j>0&&s[i]!=s[j+1]) j=pre[j];
        if (s[i]==s[j+1]) j++;
        pre[i]=j;
    }
}
void kmp(int r,int m)
{
    int j=0;
    for (int i=1;i<=len[r];i++) {
        while (j>0&&(j==m||a[r][i]!=s[j+1])) j=pre[j];
        if (a[r][i]==s[j+1]) j++;
        tem=max(tem,j);
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&len[i]);
        for (int j=1;j<=len[i];j++) scanf("%d",&mp[i][j]);
        for (int j=1;j<len[i];j++) a[i][j]=mp[i][j+1]-mp[i][j];
        len[i]--;
    }
    if (n==1) {
        printf("%d\n",len[1]+1);
        return 0;
    }
    int ans=1;
    for (int i=len[1];i>=1;i--) {
        for (int j=i,k=1;j<=len[1];j++,k++) s[k]=a[1][j];
        calc_pre(len[1]-i+1);
        int mn=len[1]-i+1;
        for (int j=2;j<=n;j++) {
            tem=0;
            kmp(j,len[1]-i+1);
            mn=min(mn,tem);
        }
        ans=max(ans,mn+1);
    }
    printf("%d\n",ans);
    return 0;
}

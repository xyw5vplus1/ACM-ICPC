#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int T,len;
int z[maxn+5];
char s[maxn+5];
int rmx[maxn+5];
void pre_EKMP(int m)
{
    z[1]=m;
    int j=0;
    while (j+2<=m&&s[j+1]==s[j+2]) j++;
    z[2]=j;
    int k=2;
    for(int i=3;i<=m;i++) {
        int p=z[k]+k-1;
        int L=z[i-k+1];
        if (i+L<p+1) z[i]=L;
        else {
            j=max(0,p-i+1);
            while (i+j<=m&&s[i+j]==s[j+1]) j++;
            z[i]=j;
            k=i;
        }
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%s",s+1);
        len=strlen(s+1);
        pre_EKMP(len);
        rmx[len+1]=0;
        for (int i=len;i>=1;i--) rmx[i]=max(rmx[i+1],z[i]);
        int ans=0;
        for (int i=2;i<=len;i++) {
            int p=min(i-1,z[i]);
            ans=max(ans,min(p,rmx[i+p]));
        }
        printf("%d\n",ans);
    }
    return 0;
}

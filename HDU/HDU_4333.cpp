#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int z[maxn+5];
char s[maxn+5];
int T;
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
    for (int kase=1;kase<=T;kase++) {
        int num1=0,num2=0,num3=0;
        scanf("%s",s+1);
        int len=strlen(s+1);
        for (int i=len+1;i<=2*len;i++) s[i]=s[i-len];
        s[2*len+1]='\0';
        pre_EKMP(2*len);
        for (int i=1;i<=len;i++)
            if (z[i]>=len) num2++;
            else {
                int p=i+z[i]-1;
                if (s[z[i]+1]<s[p+1]) num3++;
                else num1++;
            }
        int p=1;
        for (int i=2;i<=len;i++)
            if (len%(i-1)==0&&z[i]==2*len-i+1) p=max(p,len/(i-1));
        printf("Case %d: %d %d %d\n",kase,num1/p,num2/p,num3/p);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10;
int a[10],b[10];
int dp[maxn];
int n;
int main()
{
    scanf("%d",&n);
    a[1]=1; b[1]=8;
    a[2]=6; b[2]=18;
    a[3]=28; b[23]=28;
    a[4]=88; b[4]=58;
    a[5]=198; b[5]=128;
    a[6]=328; b[6]=198;
    a[7]=648; b[7]=388;
    dp[0]=0;
    for (int i=1;i<=7;i++)
    for (int j=n;j>=0;j--)
    if (j>=a[i]) dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
    printf("%d\n",10*n+dp[n]);
    return 0;
}

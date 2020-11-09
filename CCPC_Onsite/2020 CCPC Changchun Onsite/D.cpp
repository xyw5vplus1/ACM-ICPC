#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=3000+10;
char s[maxn];
int pw[maxn];
int c;
int calc(int k)
{
    int ans=1;
    for (int i=1;i<=k;i++) ans=1LL*ans*(c+1)%mod;
    return ans;
}
int main()
{
    scanf("%s",s+1);
    scanf("%d",&c);
    int n=strlen(s+1);
    int cnt1=0;
    pw[0]=1;
    int ans=0;
    for (int i=1;i<=n;i++) pw[i]=1LL*pw[i-1]*c%mod;
    for (int i=1;i<=n;i++) {
        if (s[i]=='1') {
            ans=(ans+1LL*pw[cnt1]*calc(n-i)%mod)%mod;
            cnt1++;
            //printf("debug %d\n",ans);
        }
    }
    ans=(ans+pw[cnt1])%mod;
    printf("%d\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pw[20],fac[20];
int num[10];
int T;
ll dp[1025][1001];
int cnt[1025];
char s[15];
int n,mod;
int getCnt(int x)
{
    int cnt=0;
    while (x) {
        x=(x&(x-1));
        cnt++;
    }
    return cnt;
}
int main()
{
    scanf("%d",&T);
    pw[0]=1;
    for (int i=1;i<=10;i++) pw[i]=pw[i-1]*10;
    for (int i=0;i<1024;i++) cnt[i]=getCnt(i);
    fac[0]=1;
    for (int i=1;i<=10;i++) fac[i]=fac[i-1]*i;
    while (T--) {
        scanf("%s",s);
        scanf("%d",&mod);
        n=strlen(s);
        for (int i=0;i<(1<<n);i++)
            for (int j=0;j<mod;j++){
                dp[i][j]=0;
            }
        dp[0][0]=1;
        for (int i=0;i<(1<<n);i++)
            for (int k=0;k<n;k++)
            if (!(i&(1<<k))) {
                for (int j=0;j<mod;j++)
                    dp[(1<<k)|i][(j+(s[k]-'0')*pw[cnt[i]]%mod)%mod]+=dp[i][j];
            }
        ll ans=dp[(1<<n)-1][0];
        for (int i=0;i<=9;i++) num[i]=0;
        for (int i=0;i<n;i++) num[s[i]-'0']++;
        for (int i=0;i<=9;i++) ans/=fac[num[i]];
        printf("%lld\n",ans);
    }
    return 0;
}

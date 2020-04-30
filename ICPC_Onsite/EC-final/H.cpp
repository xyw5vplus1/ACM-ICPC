#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
int n,T,mod;
int getL(int pos,int q)
{
    int cur=pos-1,last=a[pos];
    int cnt=0;
    while (cur>=1) {
        if (1LL*a[cur]*q%mod==last) {
            last=a[cur]; cur--; cnt++;
        }
        else cur--;
    }
    return cnt;
}
int getR(int pos,int q)
{
    int cur=pos+1,last=a[pos];
    int cnt=0;
    while (cur<=n) {
        if (1LL*last*q%mod==a[cur]) {
            last=a[cur]; cur++; cnt++;
        }
        else cur++;
    }
    return cnt;
}
int quick_pow(int a,int b,int mod)
{
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans%mod;
}
int inv(int x,int mod)
{
    return quick_pow(x,mod-2,mod);
}
int main()
{
    scanf("%d",&T);
    mt19937 myrand(time(0));
    while (T--) {
        scanf("%d%d",&n,&mod);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        if (n<=25) {
            int ans=0,q;
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++) {
                    q=1LL*a[j]*inv(a[i],mod)%mod;
                    ans=max(ans,2+getL(i,q)+getR(j,q));
                }
            if (2*ans>=n) printf("%d\n",ans);
            else printf("-1\n");
        }
        else {
            int ans=0;
            int times=50;
            int Findlen=8;
            int x,q;
            while (times--) {
                x=(myrand()%n+n)%n+1;
                for (int j=x+1;j<=min(n,x+Findlen);j++) {
                    q=1LL*a[j]*inv(a[x],mod)%mod;
                    ans=max(ans,2+getL(x,q)+getR(j,q));
                }
                //if (2*ans>=n) break;
            }
            if (2*ans>=n) printf("%d\n",ans);
            else printf("-1\n");
        }
    }
    return 0;
}

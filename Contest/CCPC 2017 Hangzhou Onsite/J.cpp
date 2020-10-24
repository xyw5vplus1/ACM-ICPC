#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int c[maxn][2],p[maxn][2];
int T,n,m,l,r,x;
const int mod=998244353;
int lowbit(int x)
{
    return x&(-x);
}
void modify(int p,int x,int v)
{
    while (x<=n) {
        c[x][p]+=v;
        x+=lowbit(x);
    }
}
int getSum(int p,int x)
{
    int ans=0;
    while (x) {
        ans+=c[x][p];
        x-=lowbit(x);
    }
    return ans;
}
int quick_pow(int a,int b)
{
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) c[i][0]=c[i][1]=0;
        for (int i=1;i<=m;i++) {
            scanf("%d%d%d",&l,&r,&x);
            if (x==2) {
                modify(0,l,1);
                modify(0,r+1,-1);
            }
            else {
                modify(1,l,1);
                modify(1,r+1,-1);
            }
        }
        int mn0=-1,mn1=-1;
        for (int i=1;i<=n;i++) {
            p[i][0]=getSum(0,i);
            p[i][1]=getSum(1,i);
            if (mn0==-1) mn0=p[i][0];
            else mn0=min(mn0,p[i][0]);
            if (mn1==-1) mn1=p[i][1];
            else mn1=min(mn1,p[i][1]);
        }
        printf("%d\n",1LL*quick_pow(2,mn0)*quick_pow(3,mn1)%mod);
    }
    return 0;
}
/*
2
5 3
1 3 2
3 5 2
1 5 3
6 3
1 2 2
5 6 2
1 6 2
*/

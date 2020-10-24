#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=1010;
const int maxn=100000+10;
int c[maxm][maxm];
int a[maxn],b[maxn],cnt0[maxm];
int T,n,m,op,l,r,k,x,y;
ll sum=0;
int lowbit(int x)
{
    return x&(-x);
}
void modify(int n, int x, int v)
{
    while (x<=n) {
        c[n][x]+=v;
        x+=lowbit(x);
    }
}
int getSum(int n, int x)
{
    int ans=0;
    while (x) {
        ans+=c[n][x];
        x-=lowbit(x);
    }
    return ans;
}
bool check(ll t,int need)
{
    int cnt=0,d;
    ll ans=-sum;
    for (int i=1;i<=1000;i++) {
        d=getSum(i,t%i+1);
        ans+=(t/i)*cnt0[i];
        ans-=cnt0[i]-d;
        if (ans>=need+1000-i) return true;
    }
    //printf("debug %lld %lld\n",t,ans);
    return false;
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) scanf("%d",&b[i]);
        sum=0;
        for (int i=1;i<=n;i++) sum+=b[i]/a[i];
        for (int i=1;i<=1000;i++) {
            for (int j=1;j<=i;j++) c[i][j]=0;
            cnt0[i]=0;
        }
        for (int i=1;i<=n;i++) {
            modify(a[i],b[i]%a[i]+1,1);
            cnt0[a[i]]++;
        }
        ll l,r,mid;
        while (m--) {
            scanf("%d",&op);
            if (op==1) {
                scanf("%d%d",&x,&y);
                sum-=b[x]/a[x];
                modify(a[x],b[x]%a[x]+1,-1);
                cnt0[a[x]]--;
                a[x]=y;
                sum+=b[x]/a[x];
                modify(a[x],b[x]%a[x]+1,1);
                cnt0[a[x]]++;
            }
            else if (op==2) {
                scanf("%d%d",&x,&y);
                sum-=b[x]/a[x];
                modify(a[x],b[x]%a[x]+1,-1);
                b[x]=y;
                sum+=b[x]/a[x];
                modify(a[x],b[x]%a[x]+1,1);
            }
            else {
                scanf("%d",&k);
                l=1,r=2e12;
                while (l<r) {
                    mid=(l+r)>>1;
                    if (check(mid,k)) r=mid;
                    else l=mid+1;
                }
                printf("%lld\n",l);
            }
        }
    }
    return 0;
}

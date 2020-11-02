#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n,k;
ll calc(ll l,ll r,ll k)
{
    if (l>r) return 0;
    return r/k-(l-1)/k;
}
ll quick_pow(ll a,int b)
{
    ll ans=1;
    while (b) {
        if (b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&k);
        if (k>=30) printf("Case #%d: %d\n",kase,n);
        else {
            if (k==1) printf("Case #%d: %d\n",kase,n);
            else {
                ll ans=0;
                ll cur=1,nxt=(1LL<<k)-1;
                int val=1;
                while (cur<=n) {
                    ll up=min(1LL*n,nxt);
                    ans=ans+calc(cur,up,val);
                    //printf("debug %lld %lld ans=%lld\n",cur,nxt,ans);
                    val++;
                    cur=nxt+1; nxt=quick_pow(val+1,k)-1;
                }
                printf("Case #%d: %lld\n",kase,ans);
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int T;
ll getSum(ll st,ll num)
{
    return (st+num-1)*num;
}
ll L,R;
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%lld%lld",&L,&R);
        if (L>=R) {
            ll l=0,r=2e9;
            while (l<r) {
                ll mid=(l+r+1)>>1;
                if (L-mid*(mid+1)/2>=R) l=mid;
                else r=mid-1;
            }
            ll ans=l;
            L-=l*(l+1)/2;
            ll l0=0,r0=2e9;
            ll step=l;
            while (l0<r0) {
                ll mid=(l0+r0+1)>>1;
                if (getSum(step+1,mid)<=L&&getSum(step+2,mid)<=R) l0=mid;
                else r0=mid-1;
            }
            L-=getSum(step+1,l0); R-=getSum(step+2,l0);
            ans+=2*l0;
            if (L>=step+2*l0+1) {
                ans++; L-=step+2*l0+1;
            }
            printf("Case #%d: %lld %lld %lld\n",kase,ans,L,R);
        }
        else {
            ll l=0,r=2e9;
            while (l<r) {
                ll mid=(l+r)>>1;
                if (R-mid*(mid+1)/2<=L) r=mid;
                else l=mid+1;
            }
            ll ans=l;
            R-=l*(l+1)/2;
            if (R<0) {
                ans--; R+=l;
                printf("Case #%d: %lld %lld %lld\n",kase,ans,L,R);
                continue;
            }
            ll l0=0,r0=2e9;
            ll step=l;
            while (l0<r0) {
                ll mid=(l0+r0+1)>>1;
                if (getSum(step+1,mid)<=L&&getSum(step+2,mid)<=R) l0=mid;
                else r0=mid-1;
            }
            L-=getSum(step+1,l0); R-=getSum(step+2,l0);
            ans+=2*l0;
            if (L>=step+2*l0+1) {
                ans++; L-=step+2*l0+1;
            }
            printf("Case #%d: %lld %lld %lld\n",kase,ans,L,R);
        }
    }
    return 0;
}

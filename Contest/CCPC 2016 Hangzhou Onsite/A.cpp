#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int T,n,m;
int a[maxn];
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&m);
        ll sum=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if (sum%m!=0) {
            printf("Case #%d: %d\n",kase,-1);
            continue;
        }
        ll need=sum/m;
        sum=0;
        ll ans=0;
        for (int i=1;i<=n;i++) {
            if (sum) ans++;
            sum+=a[i];
            if (sum>=need) {
                int t=sum/need;
                if (sum%need!=0) {
                    ans+=t; sum%=need;
                }
                else {
                    sum=0; ans+=(t-1);
                }
            }
        }
        printf("Case #%d: %lld\n",kase,ans);
    }
    return 0;
}

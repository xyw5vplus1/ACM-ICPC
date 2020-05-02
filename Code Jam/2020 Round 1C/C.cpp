//只过了前两个部分
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
typedef double db;
int T;
map<ll,int> mp;
ll a[maxn];
int n,d;
ll e[maxn];
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&d);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        mp.clear();
        for (int i=1;i<=n;i++) mp[a[i]]++;
        sort(a+1,a+n+1);
        if (d==3) {
            int ans=2;
            for (int i=1;i+2<=n;i++)
            if (a[i]==a[i+1]&&a[i+1]==a[i+2]) {
                ans=0; break;
            }
            if (ans==0) {
                printf("Case #%d: %d\n",kase,ans);
                continue;
            }
            for (int i=1;i+1<=n;i++)
            if (a[i]==a[i+1]&&i+1<n) {
                ans=1; break;
            }
            for (int i=1;i<=n;i++)
                if (mp[2*a[i]]>0) {
                    ans=1; break;
                }
            if (ans==1) {
                printf("Case #%d: %d\n",kase,ans);
                continue;
            }
            printf("Case #%d: %d\n",kase,ans);
        }
        else if (d==2) {
            int ans=1;
            for (int i=1;i+1<=n;i++)
            if (a[i]==a[i+1]) ans=0;
            printf("Case #%d: %d\n",kase,ans);
            continue;
        }
        else {
            for (int i=1;i<=n;i++) e[i]=a[i];
            int m=unique(e+1,e+n+1)-(e+1);
            int ans=d-1;
            for (int i=1;i<=m;i++)
            for (int j=1;j<=d;j++){
                int k=lower_bound(a+1,a+n+1,e[i])-a;
                ll cnt=0,tot=0;
                bool bo=false;
                while (k<=n) {
                    if (a[k]*j%e[i]==0) {
                        if (cnt+a[k]*j/e[i]<=d) {
                            cnt+=a[k]*j/e[i];
                            tot+=a[k]*j/e[i]-1;
                        }
                        else {
                            bo=true;
                            tot+=d-cnt;
                            ans=min(1LL*ans,tot);
                            break;
                        }
                        if (cnt==d) {
                            bo=true; ans=min(1LL*ans,tot); break;
                        }
                    }
                    k++;
                }
                if (bo==false) {
                    k=lower_bound(a+1,a+n+1,e[i])-a;
                    while (k<=n) {
                        if (a[k]*j%e[i]!=0) {
                            int need=d-cnt;
                            if (a[k]*j/e[i]>=need) {
                                ans=min(1LL*ans,tot+need); bo=true; break;
                            }
                            else {
                                cnt+=need; tot+=need;
                            }
                        }
                        k++;
                    }
                }
            }
            printf("Case #%d: %d\n",kase,ans);
        }
    }
    return 0;
}


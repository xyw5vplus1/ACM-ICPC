#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
const int mod=1e9+7;
int a[maxn];
bool has[maxn];
int n,T,k;
int quick_pow(int a,int b)
{
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans%mod;
}
int gcd(int n,int m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
vector<int > v;
int mp[2*maxn];
int sum[maxn];
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) has[i]=false;
        v.clear();
        for (int i=1;i<=n;i++)
            if (a[i]==k) {
                v.pb(i);
                has[i]=true;
            }
        if (v.size()==0) {
            printf("no\n");
            continue;
        }
        bool bo=false;
        for (auto e:v) {
            if (e+1<=n&&a[e+1]>=k) {
                bo=true; break;
            }
            if (e-1>=1&&a[e-1]>=k) {
                bo=true; break;
            }
        }
        if (bo) {
            printf("yes\n");
            continue;
        }
            if (n==1) printf("yes\n");
            else {
                for (int i=1;i<=n;i++)
                    if (a[i]>k) a[i]=1;
                    else if (a[i]==k) a[i]=0;
                    else if (a[i]<k) a[i]=-1;
                memset(mp,-1,sizeof(int)*(2*(n+3)));
                sum[0]=0;
                mp[0+n+1]=0;
                int cur=0;
                for (int i=1;i<=n;i++) {
                    cur+=a[i];
                    sum[i]=sum[i-1]+(a[i]==0);
                    if (mp[cur+n+1]==-1) mp[cur+n+1]=i;
                    if (mp[cur+n+1]!=-1) {
                        if (i-mp[cur+n+1]>1&&sum[i]-sum[mp[cur+n+1]]>0) {
                            bo=true; break;
                        }
                    }
                    if (mp[cur+n+1-1]!=-1) {
                        if (i-mp[cur+n+1-1]>1&&sum[i]-sum[mp[cur+n+1-1]]>0) {
                            bo=true; break;
                        }
                    }
                }
                if (bo) {
                    printf("yes\n");
                    continue;
                }
                else {
                    for (int i=1;i<=n;i++)
                        if (a[i]>=0) sum[i]=sum[i-1]+1;
                        else sum[i]=sum[i-1]-1;
                    int t=0;
                    int mn=n;
                    for (int i=1;i<=n;i++) {
                        if (i>=2) t=max(t,sum[i]-mn);
                        mn=min(mn,sum[i-1]);
                    }
                    if (t>=1) printf("yes\n");
                    else printf("no\n");
                }
            }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
typedef long long ll;
typedef double db;
int T,n;
int a[maxn],b[maxn];
int gcd(int n,int m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
set<pair<int,int>> s;
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        s.clear();
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
        if (1LL*(a[i]-a[j])*(b[i]-b[j])<0) {
            int t1=a[i]-a[j],t2=b[i]-b[j];
            if (t1<0) {
                t1=-t1; t2=-t2;
            }
            t2=-t2;
            int d=gcd(t1,t2);
            t1/=d; t2/=d;
            s.insert(make_pair(t1,t2));
        }
        printf("Case #%d: %d\n",kase,s.size()+1);
    }
    return 0;
}

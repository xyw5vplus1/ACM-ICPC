#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
const int INF=1e9;
typedef long long ll;
typedef double db;
int a[maxn],b[maxn];
int T,n;
int gcd(int n,int m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
bool cmp(pair<int,int> e1,pair<int,int> e2)
{
    if (1LL*e1.first*e2.second>1LL*e1.second*e2.first) return true;
    return false;
}
int getR(int a,int b,int x)
{
    int y=b*x/a;
    if (y*a==b*x) y--;
    return y;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        pair<int,int> mx,mn;
        mx.first=0; mx.second=1; mn.first=1; mn.second=0;
        bool bo=true;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
            if (1LL*(a[i]-a[j])*(b[i]-b[j])<0) {
                if (a[i]<a[j]) {
                    int t1=a[j]-a[i],t2=b[i]-b[j];
                    int d=gcd(t1,t2);
                    t1/=d; t2/=d;
                    if (cmp(make_pair(t2,t1),mx)) mx=make_pair(t2,t1);
                }
                else {
                    int t1=a[i]-a[j],t2=b[j]-b[i];
                    int d=gcd(t1,t2);
                    t1/=d; t2/=d;
                    if (cmp(mn,make_pair(t2,t1))) mn=make_pair(t2,t1);
                }
            }
            else {
                if (a[i]>=a[j]&&b[i]>=b[j]) {
                    bo=false; break;
                }
            }
        if (!bo) {
            printf("Case #%d: IMPOSSIBLE\n",kase);
            continue;
        }
        if (!cmp(mn,mx)) printf("Case #%d: IMPOSSIBLE\n",kase);
        else {
            int a1=mx.first,b1=mx.second;
            int a2=mn.first,b2=mn.second;
            //printf("debug %d/%d %d/%d \n",a1,b1,a2,b2);
            if (a1!=0) {
                int ans1=0,ans2=0;
                for (int i=1;i<=10005;i++) {
                    int r=getR(a1,b1,i);
                    if (r!=0&&cmp(mn,make_pair(i,r))) {
                        ans1=i; break;
                    }
                }
                for (int i=1;i<=10005;i++)
                if (cmp(make_pair(ans1,i),mx)&&cmp(mn,make_pair(ans1,i))) {
                    ans2=i; break;
                }
                printf("Case #%d: %d %d\n",kase,ans1,ans2);
            }
            else {
                int ans1=0,ans2=0;
                for (int i=1;i<=10005;i++) {
                    int y=b2*i/a2;
                    if (!cmp(mn,make_pair(i,y))) y++;
                    if (y!=0) {
                        ans1=i; ans2=y; break;
                    }
                }
                printf("Case #%d: %d %d\n",kase,ans1,ans2);
            }
        }
    }
    return 0;
}


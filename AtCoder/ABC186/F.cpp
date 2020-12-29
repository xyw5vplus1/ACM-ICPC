#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
vector<int> a[maxn],b[maxn];
int c[maxn];
int h,w,n;
int x,y;
int lowbit(int x)
{
    return x&(-x);
}
void modify(int x,int v)
{
    while (x<=w) {
        c[x]+=v;
        x+=lowbit(x);
    }
}
int getSum(int x)
{
    int ans=0;
    while (x) {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&x,&y);
        a[x].push_back(y); b[y].push_back(x);
    }
    for (int j=1;j<=w;j++) sort(b[j].begin(),b[j].end());
    for (int i=1;i<=h;i++) sort(a[i].begin(),a[i].end());
    ll ans=0;
    for (int j=1;j<=w;j++) {
        if (!b[j].size()) ans+=h;
        else {
            if (b[j][0]==1) break;
            ans+=b[j][0]-1;
        }
    }
    for (int i=1;i<=h;i++) {
        if (a[i].size()&&a[i][0]==1) break;
        if (a[i].size()) {
            ans+=getSum(a[i][0]-1);
            if (i==1) {
                for (int j=a[i][0];j<=w;j++) {
                    if (getSum(j)-getSum(j-1)) continue;
                    modify(j,1);
                }
            }
            else {
                for (int j=0;j<a[i].size();j++) {
                    if (getSum(a[i][j])-getSum(a[i][j]-1)) continue;
                    modify(a[i][j],1);
                }
            }
        }
        else {
            ans+=getSum(w);
        }
    }
    printf("%lld\n",ans);
}

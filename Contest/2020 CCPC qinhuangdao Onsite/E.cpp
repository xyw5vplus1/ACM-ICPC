#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int T,n,p;
int e[maxn],c[maxn];
int n0;
int lowbit(int x)
{
    return x&(-x);
}
struct node
{
    int x,y;
}a[maxn];
bool cmp(node a,node b)
{
    return a.x>b.x;
}
int getPos(int val)
{
    return lower_bound(e+1,e+n0+1,val)-e;
}
void modify(int x,int v)
{
    while (x<=n0) {
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
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&p);
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&a[i].x,&a[i].y);
            e[i]=a[i].y;
        }
        sort(e+1,e+n+1);
        n0=unique(e+1,e+n+1)-(e+1);
        for (int i=1;i<=n;i++) c[i]=0;
        sort(a+1,a+n+1,cmp);
        int mx=0;
        int ans=0;
        for (int i=1;i<=n;i++) {
            int tem=0;
            if (a[i].x<mx) {
                mx=max(mx,a[i].y);
                continue;
            }
            else {
                int k=ceil(1.0*a[i].x*p/100.0);
                int p=getPos(k);
                tem=tem+i-1-getSum(p-1);
                int l=i,r=n;
                while (l<r) {
                    int mid=(l+r+1)>>1;
                    if (a[mid].x>=k) l=mid;
                    else r=mid-1;
                }
                tem+=(l-i+1);
                ans=max(ans,tem);
            }
            mx=max(mx,a[i].y);
            modify(getPos(a[i].y),1);
        }
        int k=ceil(1.0*mx*p/100.0);
        int tem=0;
        for (int i=1;i<=n;i++) {
            if (a[i].x<=mx) {
                if (a[i].x>=k) tem++;
            }
            else {
                if (a[i].y>=k) tem++;
            }
        }
        ans=max(ans,tem);
        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}
/*
5 23
100 50
97 49
80 37
25 25
9 6
*/

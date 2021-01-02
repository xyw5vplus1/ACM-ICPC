#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e3+10;
struct node
{
    int x,y;
}a[maxn];
bool cmp(node i,node j)
{
    if (i.x!=j.x) return i.x<j.x;
    return i.y<j.y;
}
bool check(int i,int j)
{
    int dx=a[j].x-a[i].x;
    int dy=a[j].y-a[i].y;
    if (dx==0) return false;
    if (dy+dx>=0&&dy<=dx) return true;
    return false;
}
int n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (check(i,j)) ans++;
    printf("%d\n",ans);
    return 0;
}


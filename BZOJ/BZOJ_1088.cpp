#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int a[maxn],b[maxn];
int n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    if (n==1) {
        if (b[1]>1) printf("0\n");
        else printf("1\n");
        return 0;
    }
    int ans=0;
    for (int i=0;i<=b[1];i++) {
        if (i>1) break;
        a[1]=i;
        a[2]=b[1]-a[1];
        for (int i=3;i<=n;i++) a[i]=b[i-1]-a[i-1]-a[i-2];
        bool bo=true;
        for (int i=1;i<=n;i++)
        if (a[i]<0||a[i]>1) {
            bo=false; break;
        }
        if (a[n-1]+a[n]!=b[n]) bo=false;
        if (bo) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

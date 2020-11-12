#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
int a[maxn];
int belong[maxn],sum[maxn],lef[maxn],rig[maxn],add[maxn];
int op,l,r,c,n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int sz=sqrt(n*1.0);
    for (int i=1;i<=n;i++) {
        belong[i]=(i-1)/sz+1;
        sum[belong[i]]+=a[i];
    }
    for (int i=1;i<=(n-1)/sz+1;i++) {
        add[i]=0;
        lef[i]=(i-1)*sz+1;
        rig[i]=min(i*sz,n);
    }
    for (int i=1;i<=n;i++) {
        scanf("%d%d%d%d",&op,&l,&r,&c);
        if (op==0) {
            if (belong[l]==belong[r]) {
                for (int j=l;j<=r;j++) {
                    a[j]+=c; sum[belong[j]]+=c;
                }
            }
            else {
                for (int j=l;j<=rig[belong[l]];j++) {
                    a[j]+=c; sum[belong[j]]+=c;
                }
                for (int j=lef[belong[r]];j<=r;j++) {
                    a[j]+=c; sum[belong[j]]+=c;
                }
                for (int j=belong[l]+1;j<=belong[r]-1;j++) {
                    add[j]+=c;
                }
            }
        }
        else {
            printf("%d\n",a[r]+add[belong[r]]);
        }
    }
    return 0;
}

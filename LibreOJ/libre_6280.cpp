#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+10;
int a[maxn];
int belong[maxn];
ll sum[maxn];
int lef[maxn],rig[maxn],add[maxn];
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
            int ans=0;
            if (belong[l]==belong[r]) {
                for (int j=l;j<=r;j++) {
                    ans=(ans+a[j])%(c+1); ans=(ans+add[belong[j]])%(c+1);
                }
            }
            else {
                for (int j=l;j<=rig[belong[l]];j++) {
                    ans=(ans+a[j])%(c+1); ans=(ans+add[belong[j]])%(c+1);
                }
                for (int j=lef[belong[r]];j<=r;j++) {
                    ans=(ans+a[j])%(c+1); ans=(ans+add[belong[j]])%(c+1);
                }
                for (int j=belong[l]+1;j<=belong[r]-1;j++) {
                    ans=(ans+sum[j])%(c+1); ans=(ans+1LL*(rig[j]-lef[j]+1)*add[j]%(c+1))%(c+1);
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}


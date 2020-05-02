//只过了第一个部分
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=100;
int T,n,m;
int a[maxn+5][maxn+5];
bool bo[maxn+5][maxn+5];
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) {
                scanf("%d",&a[i][j]); bo[i][j]=true;
            }
        ll sum=0;
        int exist=n*m,last=exist;
        while (true) {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            if (bo[i][j]) sum+=a[i][j];
            for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                if (bo[i][j]) {
                    ll tot=0;int cnt=0;
                    for (int k=i+1;k<=n;k++) {
                        if (a[k][j]) {
                            tot+=a[k][j]; cnt++; break;
                        }
                    }
                    for (int k=j+1;k<=m;k++) {
                        if (a[i][k]) {
                            tot+=a[i][k]; cnt++; break;
                        }
                    }
                    for (int k=i-1;k>=1;k--) {
                        if (a[k][j]) {
                            tot+=a[k][j]; cnt++; break;
                        }
                    }
                    for (int k=j-1;k>=1;k--) {
                        if (a[i][k]) {
                            tot+=a[i][k]; cnt++; break;
                        }
                    }
                    if (cnt&&tot>1LL*cnt*a[i][j]) bo[i][j]=0;
                }

            for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) {
                if (bo[i][j]==false&&a[i][j]>0) {
                    a[i][j]=0; exist--;
                }
            }
            if (last==exist) break;
            last=exist;
        }
        printf("Case #%d: %lld\n",kase,sum);
    }
    return 0;
}


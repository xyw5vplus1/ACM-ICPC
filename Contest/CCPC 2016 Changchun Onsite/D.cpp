/*#include <bits/stdc++.h>
using namespace std;
int a[22];
int sum[22];

inline bool test(int N)
{
    memset(sum,0,sizeof(sum));
    sum[0]=0;
    sum[1]=a[1];

    for (int i=1;i<=N;i++)
        sum[i]+=sum[i-1];
        int A=sum[N];
    for (int i=1;i<=N;i++)
        if (a[i]==1)
            for (int j=i+1;j<=N;j++)
                if (a[j]==1)
            {
              //  int cnt=min(i+j-1,N)-max()
                    int R=min(i+j,N);
                    int L=max(j-i,1);
                    cout<<i<<" "<<j<<" "<<L<<" "<<R<<" "<<endl;
                    system("pause");
                    if (sum[N]-sum[R-1]>0)
                         return 0;
                    if (sum[L]-sum[0]>0)
                        return 0;
            }
        return 1;
}
int C=0;
int ans=0;
inline void dfs(int N,int u)
{
    if (u!=N)
    {
        a[u]=1;
        C++;
        dfs(N,u+1);
        C--;
        a[u]=0;
        dfs(N,u+1);
    }
    if (u==N)
    {
        a[u]=1;
        C++;
        int x=test(N);
        if (x==1) ans=min(ans,N-C);
        C--;
        a[u]=0;
        x= test(N);
        if (x==1) ans=min(ans,N-C);
    }
}
int main()
{
    for (int i=3;i<=20;i++)
    {
      //  memset(a,0,sizeof(a));
        C=0;
        ans=i;
        dfs(i,1);
        cout<<i<<" "<<ans<<endl;
    }
}*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[50];
int T;
int main()
{
    scanf("%d",&T);
    f[1]=1; f[2]=2;
    for (int i=3;i<=30;i++) f[i]=f[i-1]+f[i-2];
    for (int kase=1;kase<=T;kase++) {
        scanf("%d",&n);
        int k=0;
        for (int j=1;j<=30;j++)
            if (f[j]<=n) k++;
        printf("Case #%d: %d\n",kase,n-k);
    }
    return 0;
}

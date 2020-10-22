#include<bits/stdc++.h>
#define maxn 1000010

using namespace std;

int a[maxn],b[maxn],c[maxn];
int f[maxn];
int vis[maxn];
int n,m,p;
int ans=0;
inline void getf()
{
    memset(f,0,sizeof(f));
    f[1]=0;
    for (int i=2,j=0;i<=m;i++)
    {
        while (j && b[i]!=b[j+1])
            j=f[j];
        if (b[j+1]==b[i]) j++;
        f[i]=j;
    }
}
int cnt=0;
inline void kmp()
{
    for (int i=1,j=0;i<=cnt;i++)
    {

        while (j && (j==m||c[i]!=b[j+1])) j=f[j];
        if (b[j+1]==c[i]) j++;
        if (j==m)
             ans++;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
            ans=0;
           scanf("%d%d%d",&n,&m,&p);
        for (int i=1;i<=n;i++) vis[i]=0;
           for (int i=1;i<=n;i++)
                scanf("%d",&a[i]);
           for (int i=1;i<=m;i++)
                scanf("%d",&b[i]);
            getf();
            for (int i=1;i<=n;i++)
            {
                if (vis[i]) continue;
                vis[i]=1;
                cnt=0;
                for (int j=0;i+j*p<=n;j++)
                {
                    vis[i+j*p]=1;
                    c[++cnt]=a[i+j*p];
                }
               // for (int i=0;i<cnt;i++)
             //      cout<<c[i]<<" ";
            //    puts("");
                kmp();

            }
            printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}


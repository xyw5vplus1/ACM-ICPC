#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxm=2e4+10;
const int maxn=2e3+10;
int T;
int d[maxn],v[maxm];
int n,m,x,y;
int e1[maxn],e2[maxn],a[maxn],b[maxn],r[maxn],t[maxn];
bool cmp1(int a,int b)
{
    return d[a]>d[b];
}
bool cmp2(int a,int b)
{
    return d[a]<d[b];
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&m);
        bool bo=false;
        for (int i=2;i<=n;i++) {
            scanf("%d",&d[i]);
            if (d[i]>0) bo=true;
        }
        if (!bo) {
            for (int i=1;i<=m;i++) {
                scanf("%d%d",&x,&y);
                if (d[x]!=d[y]) v[i]=abs(d[x]-d[y]);
                else v[i]=1;
            }
            printf("Case #%d:",kase);
            for (int i=1;i<=m;i++) printf(" %d",v[i]); printf("\n");
        }
        else {
            for (int i=1;i<=n;i++)
            if (d[i]>0) t[i]=d[i];
            else r[i]=-d[i];
            int n1=0,n2=0;
            for (int i=2;i<=n;i++) {
                if (d[i]<0) e1[++n1]=i;
                else e2[++n2]=i;
            }
            sort(e1+1,e1+n1+1,cmp1); sort(e2+1,e2+n2+1,cmp2);
            int p1=1,p2=1; int k=1;
            for (int i=2;i<=n;i++) {
                if (p1<=n1) {
                    if (r[e1[p1]]<=i-1) {
                        if (r[e1[p1]]==r[k]) t[e1[p1]]=t[k];
                        else t[e1[p1]]=t[k]+1;
                        k=e1[p1]; p1++;
                    }
                    else {
                        if (t[e2[p2]]==t[k]) r[e2[p2]]=r[k];
                        else r[e2[p2]]=i-1;
                        k=e2[p2]; p2++;
                    }
                }
                else {
                    if (t[e2[p2]]==t[k]) r[e2[p2]]=r[k];
                    else r[e2[p2]]=i-1;
                }
            }
            for (int i=1;i<=m;i++) {
                scanf("%d%d",&x,&y);
                if (t[x]!=t[y]) v[i]=abs(t[x]-t[y]);
                else v[i]=1;
            }
            printf("Case #%d:",kase);
            for (int i=1;i<=m;i++) printf(" %d",v[i]); printf("\n");
        }
    }
    return 0;
}


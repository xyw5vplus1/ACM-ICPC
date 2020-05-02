#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int ans[maxn+5];
int T,n;
struct node
{
    int l,r;
    int id;
}a[maxn+5];
bool cmp(node a,node b)
{
    return a.l<b.l;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&a[i].l,&a[i].r);
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        int last1=0,last2=0;
        bool bo=true;
        for (int i=1;i<=n;i++) {
            if (last1<=last2) {
                if (last1>a[i].l) {
                    bo=false; break;
                }
                else {
                    ans[a[i].id]=1;
                    last1=a[i].r;
                }
            }
            else {
                if (last2>a[i].l) {
                    bo=false; break;
                }
                else {
                    ans[a[i].id]=2;
                    last2=a[i].r;
                }
            }
        }
        if (!bo) printf("Case #%d: IMPOSSIBLE\n",kase);
        else {
            printf("Case #%d: ",kase);
            for (int i=1;i<=n;i++)
                if (ans[i]==1) printf("C");
                else printf("J");
            printf("\n");
        }
    }
    return 0;
}

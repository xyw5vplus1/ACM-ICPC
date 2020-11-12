#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
const int maxk=1e3+10;
vector<int> v[maxk];
int be[maxn],a[maxn],add[maxk];
int l,r,d,op;
int n,q;
int main()
{
    scanf("%d",&n);
    q=n;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int block=sqrt(n*1.0);
    for (int i=1;i<=n;i++) be[i]=(i-1)/block+1;
    for (int i=1;i<=n;i++) v[be[i]].push_back(a[i]);
    for (int i=1;i<=be[n];i++) sort(v[i].begin(),v[i].end());
    for (int i=1;i<=be[n];i++) add[i]=0;
    while (q--) {
        scanf("%d%d%d%d",&op,&l,&r,&d);
        if (op==0) {
            int p1=be[l],p2=be[r];
            if (p1+1>=p2) {
                for (int i=l;i<=r;i++) a[i]+=d;
                v[p1].clear();
                for (int i=(p1-1)*block+1;i<=p1*block;i++) v[p1].push_back(a[i]);
                sort(v[p1].begin(),v[p1].end());
                if (p1!=p2) {
                    v[p2].clear();
                    for (int i=(p2-1)*block+1;i<=p2*block;i++) v[p2].push_back(a[i]);
                    sort(v[p2].begin(),v[p2].end());
                }
            }
            else {
                for (int i=l;i<=p1*block;i++) a[i]+=d;
                for (int i=(p2-1)*block+1;i<=r;i++) a[i]+=d;
                v[p1].clear(); v[p2].clear();
                for (int i=(p1-1)*block+1;i<=p1*block;i++) v[p1].push_back(a[i]);
                for (int i=(p2-1)*block+1;i<=p2*block;i++) v[p2].push_back(a[i]);
                sort(v[p1].begin(),v[p1].end()); sort(v[p2].begin(),v[p2].end());
                for (int i=p1+1;i<=p2-1;i++) add[i]+=d;
            }
        }
        else {
            d=d*d;
            int cnt=0;
            int p1=be[l],p2=be[r];
            if (p1+1>=p2) {
                for (int i=l;i<=r;i++)
                    if (a[i]+add[be[i]]<d) cnt++;
                printf("%d\n",cnt);
            }
            else {
                for (int i=l;i<=p1*block;i++)
                    if (a[i]+add[be[i]]<d) cnt++;
                for (int i=(p2-1)*block+1;i<=r;i++)
                    if (a[i]+add[be[i]]<d) cnt++;
                for (int i=p1+1;i<=p2-1;i++) {
                    int tem=v[i].end()-lower_bound(v[i].begin(),v[i].end(),d-add[i]);
                    cnt+=v[i].end()-v[i].begin()-tem;
                }
                printf("%d\n",cnt);
            }
        }
    }
    return 0;
}

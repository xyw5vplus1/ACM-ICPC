#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
int a[maxn];
int T;
int pw[10];
void modify(int x,int n)
{
    a[x]=(a[x]+a[n]-1)/a[n];
}
int n;
vector<pair<int,int> > ans;
void write()
{
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}
bool check()
{
    for (int i=1;i<=n;i++) a[i]=i;
    for (int i=0;i<ans.size();i++)
        modify(ans[i].first,ans[i].second);
    if (ans.size()>n+5) return false;
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (a[i]>2) return false;
        else if (a[i]==2) cnt++;
    return cnt==1;
}
int main()
{
    int l,r;
    //scanf("%d%d",&l,&r);
    pw[0]=1;
    for (int i=1;i<=5;i++) pw[i]=pw[i-1]*16;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        //n=kase;
        ans.clear();
        if (n<=16) {
            for (int j=3;j<=n-1;j++) ans.push_back(make_pair(j,n));
            int cur=n;
            while (cur>1) {
                ans.push_back(make_pair(n,2));
                cur=(cur+1)/2;
            }
            write();
            continue;
        }
        else {
            for (int i=1;i<=n;i++) a[i]=i;
            int k;
            for (int i=0;i<=5;i++)
                if (pw[i]<=n) k=i;
                else break;
            for (int i=pw[k]+1;i<n;i++) {
                ans.push_back(make_pair(i,n));
                modify(i,n);
            }
            if (pw[k]!=n) {
                ans.push_back(make_pair(n,pw[k]));
                modify(n,pw[k]);
            }
            int cur=k;
            while (cur>=2) {
                for (int i=pw[cur-1]+1;i<pw[cur];i++) {
                    ans.push_back(make_pair(i,pw[cur]));
                    modify(i,pw[cur]);
                }
                ans.push_back(make_pair(pw[cur],pw[cur-1]));
                modify(pw[cur],pw[cur-1]);
                cur--;
            }
            for (int i=3;i<=15;i++) {
                ans.push_back(make_pair(i,16));
                modify(i,16);
            }
            for (int i=1;i<k;i++) {
                ans.push_back(make_pair(pw[i],pw[i+1]));
                modify(pw[i],pw[i+1]);
            }
            if (n!=pw[k]) ans.push_back(make_pair(n,pw[k]));
            while (a[pw[k]]>1) {
                ans.push_back(make_pair(pw[k],2));
                a[pw[k]]/=2;
            }
            write();
            //if (!check()) printf("%d\n",n);
            //else printf("debug %d\n",n);
        }
    }
    return 0;
}

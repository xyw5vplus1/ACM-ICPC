#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5;
const ll INF=1e12;
int T;
int n;
int b[maxn+5],c[maxn+5];
ll dp[maxn+5][6][6][6];
string s1[maxn+5],s2[maxn+5];
string ss[10],st;
int l[maxn+5],r[maxn+5];
struct node
{
    string s1,s2;
    int v;
}a[maxn+5];
bool cmp(node a,node b)
{
    if (a.s1!=b.s1) return a.s1<b.s1;
    if (a.s2!=b.s2) return a.s2<b.s2;
    return a.v<b.v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    //scanf("%d",&T);
    while (T--) {
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>a[i].s1>>a[i].s2>>a[i].v;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=5;i++) cin>>ss[i];
        memset(b,0,sizeof(b)); memset(c,0,sizeof(c));
        cin>>st;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=5;j++)
                if (a[i].s1==ss[j]) {
                    b[i]=1; break;
                }
            if (a[i].s2==st) c[i]=1;
        }
        //for (int i=1;i<=n;i++) cout<<a[i].s1<<" "<<a[i].s2<<" "<<a[i].v<<" "<<b[i]<<" "<<c[i]<<endl;
        int cur=1;
        int cnt=0;
        while (cur<=n) {
            int tem=cur;
            while (tem<=n&&a[cur].s1==a[tem].s1) tem++;
            cnt++; l[cnt]=cur; r[cnt]=tem-1;
            cur=tem;
        }
        for (int i=0;i<=cnt;i++)
        for (int j=0;j<=5;j++)
            for (int k1=0;k1<=j;k1++)
            for (int k2=0;k2<=j;k2++) dp[i][j][k1][k2]=-INF;
        dp[0][0][0][0]=0;
        for (int i=0;i<cnt;i++)
            for (int k=l[i+1];k<=r[i+1];k++)
            for (int j=0;j<=5;j++)
            for (int k1=0;k1<=j;k1++)
            for (int k2=0;k2<=j;k2++) {
                if (j<5) dp[i+1][j+1][k1+b[k]][k2+c[k]]=max(dp[i+1][j+1][k1+b[k]][k2+c[k]],dp[i][j][k1][k2]+a[k].v);
                dp[i+1][j][k1][k2]=max(dp[i+1][j][k1][k2],dp[i][j][k1][k2]);
            }
        ll ans=0;
        for (int k1=0;k1<=5;k1++)
        for (int k2=0;k2<=5;k2++) {
            ll tem=floor(((10+k1+2*k2)*dp[cnt][5][k1][k2])/10.0);
            if (tem>ans) ans=tem;
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4;
typedef double db;
bool bo[100];
int p[100];
int T;
ll pw[100];
int up[100];
int zero[100];
char ans[100];
struct node
{
    ll x;
    int len;
    string s;
}a[maxn+5];
bool cmp(int a,int b)
{
    return up[a]<up[b];
}
bool cmp1(int a,int b)
{
    return zero[a]>zero[b];
}
int u;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    pw[0]=1;
    for (int i=1;i<=16;i++) pw[i]=1LL*pw[i-1]*10;
    for (int kase=1;kase<=T;kase++) {
        cin>>u;
        for (int i=1;i<=maxn;i++) cin>>a[i].x>>a[i].s;
        memset(bo,false,sizeof(bo));
        for (int i=0;i<26;i++) up[i]=10;
        if (a[1].x!=-1) {
            for (int i=1;i<=maxn;i++) {
                ll x=a[i].x;
                int cnt=0;
                while (x) {
                    cnt++; x/=10;
                }
                a[i].len=cnt;
            }
            for (int i=1;i<=maxn;i++)
                for (int j=0;j<a[i].s.length();j++) bo[a[i].s[j]-'A']=true;
            for (int i=1;i<=maxn;i++)
            if (a[i].len==a[i].s.length()) {
                up[a[i].s[0]-'A']=min(1LL*up[a[i].s[0]-'A'],a[i].x/pw[a[i].len-1]);
            }
            for (int i=0;i<26;i++) p[i]=i;
            sort(p,p+26,cmp);
            for (int i=0;i<26;i++)
            if (up[p[i]]!=10) {
                ans[i+1]=p[i]+'A';
                bo[p[i]]=false;
            }
            for (int i=0;i<26;i++)
                if (bo[i]) ans[0]=i+'A';
            cout<<"Case #"<<kase<<": ";
            for (int i=0;i<10;i++) cout<<ans[i]; cout<<endl;
        }
        else {
            for (int i=0;i<26;i++) zero[i]=0;
            for (int i=1;i<=maxn;i++) {
                for (int j=0;j<a[i].s.length();j++) bo[a[i].s[j]-'A']=true;
                zero[a[i].s[0]-'A']++;
            }
            for (int i=0;i<26;i++) p[i]=i;
            sort(p,p+26,cmp1);
            for (int i=0;i<26;i++)
            if (zero[i]!=0) {
                ans[i+1]=p[i]+'A';
                bo[p[i]]=false;
            }
            for (int i=0;i<26;i++)
                if (bo[i]) {
                    ans[0]=i+'A'; break;
                }
            cout<<"Case #"<<kase<<": ";
            for (int i=0;i<10;i++) cout<<ans[i]; cout<<endl;
        }
    }
    return 0;
}


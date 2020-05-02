#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
typedef long long ll;
typedef double db;
string s[maxn+5],suf[maxn+5],pre[maxn+5];
int p1[maxn+5],p2[maxn+5];
int T,n;
bool cmp(string a,string b)
{
    return a.length()<b.length();
}
bool isOK1(string a,string b)
{
    int len=a.length();
    for (int i=0;i<len;i++)
        if (a[i]!=b[i]) return false;
    return true;
}
bool isOK2(string a,string b)
{
    for (int i=a.length()-1,j=b.length()-1;i>=0;i--,j--)
        if (a[i]!=b[j]) return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    for (int kase=1;kase<=T;kase++) {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>s[i];
        for (int i=1;i<=n;i++) {
            int pos1=-1,pos2=-1;
            for (int j=0;j<s[i].length();j++)
            if (s[i][j]=='*') {
                pos1=j;
                break;
            }
            for (int j=0;j<s[i].length();j++)
                if (s[i][j]=='*') pos2=j;
            p1[i]=pos1; p2[i]=pos2;
            pre[i]=s[i].substr(0,pos1);
            suf[i]=s[i].substr(pos2+1,s[i].length()-pos2-1);
        }
        sort(pre+1,pre+n+1,cmp);
        sort(suf+1,suf+n+1,cmp);
        bool bo=true;
        for (int i=1;i<n;i++)
            if (!isOK1(pre[i],pre[i+1])) {
                bo=false; break;
            }
        for (int i=1;i<n;i++)
        if (!isOK2(suf[i],suf[i+1])) {
            bo=false; break;
        }
        if (!bo) cout<<"Case #"<<kase<<": *"<<endl;
        else {
            string ans;
            ans+=pre[n];
            for (int i=1;i<=n;i++) {
                for (int j=p1[i];j<=p2[i];j++)
                if (s[i][j]!='*') ans+=s[i][j];
            }
            ans+=suf[n];
            cout<<"Case #"<<kase<<": "<<ans<<endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int main()
{
    cin>>T;
    for (int kase=1;kase<=T;kase++) {
        cin>>s;
        string ans;
        int len=s.length();
        int last=0;
        for (int i=0;i<len;i++) {
            if (s[i]-'0'>last) {
                for (int j=0;j<s[i]-'0'-last;j++) ans+='(';
            }
            else if (s[i]-'0'<last) {
                for (int j=0;j<last-(s[i]-'0');j++) ans+=')';
            }
            ans+=s[i];
            last=s[i]-'0';
        }
        if (last) {
            for (int j=0;j<last;j++) ans+=')';
        }
        cout<<"Case #"<<kase<<": "<<ans<<endl;
    }
    return 0;
}

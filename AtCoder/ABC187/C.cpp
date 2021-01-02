#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
map<string,bool> mp1;
map<string,bool> mp2;
int n;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>s;
        if (s[0]=='!') {
            string ss;
            for (int j=1;j<s.length();j++) ss+=s[j];
            mp1[ss]=true;
            if (mp2[ss]) {
                cout<<ss<<endl; return 0;
            }
        }
        else {
            mp2[s]=true;
            if (mp1[s]) {
                cout<<s<<endl;
                return 0;
            }
        }
    }
    cout<<"satisfiable"<<endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int T;
char s[1010];
vector<int> ans[100];
int sz=0;
vector<int> getVec(int x)
{
    vector<int> p;
    p.push_back(x);
    return p;
}
vector<int> VecMinus(vector<int> a,vector<int> b)
{
    vector<int> a0;
    vector<int> b0;
    a0.resize(a.size()); b0.resize(b.size());
    for (int i=0;i<a0.size();i++) a0[i]=a[a.size()-i-1];
    for (int i=0;i<b0.size();i++) b0[i]=b[b.size()-i-1];
    for (int i=0;i<a0.size();i++) {
        if (i<b0.size()) {
            a0[i]=a0[i]-b0[i];
            if (a0[i]<0) {
                a0[i]+=10; a0[i+1]--;
            }
        }
        if (a0[i]<0) {
            a0[i]+=10; a0[i+1]--;
        }
    }
    while(!a0[a0.size()-1])
    {
            a0.pop_back();
    }
    vector<int> v;
    for (int i=0;i<a0.size();i++) v.push_back(a0[a0.size()-i-1]);
    return v;
}
void solve(vector<int> v)
{
    if (v.size()==1) {
        ++sz;
        ans[sz]=v;
        return ;
    }
    if (v.size()==2) {
        int x=v[0]*10+v[1];
        if (x<=20)
        {
            if (x>11)
            {
                ++sz;
                vector<int> gg=getVec(11);
                ans[sz]=gg;
                x=x-11;
                ++sz;
                gg=getVec(x);
                ans[sz]=gg;
                return ;
            }
            if (x==10)
            {
                ++sz;
                vector<int> gg=getVec(9);
                ans[sz]=gg;
                ++sz;
                gg=getVec(1);
                ans[sz]=gg;
                return ;
            }
        }
        if (v[0]==v[1]) {
            ans[++sz]=v;
            return ;
        }
    }
    int len=v.size()/2;
    bool bo=true;
    for (int i=0;i<len;i++) {
        if (i==0) {
            if (v[i]!=1) {
                bo=false; break;
            }
        }
        else {
            if (v[i]!=0) {
                bo=false; break;
            }
        }
    }
    if (bo) {
        vector<int> p;
        for (int i=0;i<v.size()-1;i++) p.push_back(9);
        ans[++sz]=p;
        vector<int> v0=VecMinus(v,p);
        solve(v0);
        return ;
    }
    vector<int> p;
    for (int i=0;i<len;i++) p.push_back(v[i]);
    vector<int> p1=VecMinus(p,getVec(1));//减完一之后

    vector<int> p2;
    for (int i=0;i<len;i++) p2.push_back(p1[i]);
    if (v.size()%2==1) p2.push_back(9);
    reverse(p1.begin(),p1.end());
    for (int i=0;i<len;i++) p2.push_back(p1[i]);
    ans[++sz]=p2;
    vector<int> p3=VecMinus(v,p2);
    solve(p3);
    return ;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%s",s);
        sz=0;
        vector<int> v;
        int len=strlen(s);
        for (int i=0;i<len;i++)
            v.push_back(s[i]-'0');
        solve(v);
        printf("Case #%d:\n",kase);
        printf("%d\n",sz);
        for (int i=1;i<=sz;i++) {
            for (int j=0;j<ans[i].size();j++) printf("%d",ans[i][j]); printf("\n");
        }
    }
    return 0;
}


#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn=10000;
string str[maxn];
int tot=0,num=0;
struct node
{
    int lc,rc;
    char ch;
}a[maxn];
void build(char ch)
{
    a[++tot].ch=ch;
    a[tot].lc=a[tot].rc=0;
}
void InsertTree(char ch)
{
    int u=1,fa,k;
    while (u) {
        if (a[u].ch>ch) {
            fa=u; k=0; u=a[u].lc;
        }
        else {
            fa=u; k=1; u=a[u].rc;
        }
    }
    build(ch);
    if (k==0) a[fa].lc=tot;
    else a[fa].rc=tot;
}
void dfs(int u)
{
    cout<<a[u].ch;
    if (a[u].lc) dfs(a[u].lc);
    if (a[u].rc) dfs(a[u].rc);
}
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin>>s) {
        str[1]=s;
        num=1;
        while (cin>>s&&s[0]!='*'&&s[0]!='$') {
            str[++num]=s;
        }
        tot=0;
        build(str[num][0]);
        for (int i=num-1;i>=1;i--) {
            for (int j=0;j<str[i].length();j++) InsertTree(str[i][j]);
        }
        dfs(1);
        cout<<endl;
        if (s[0]=='$') break;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
vector<char> ans;
char s[maxn+5];
int T,x;
struct node
{
    int len,fa;
    int ch[26];
}b[2*maxn+5];
int tot=1,last=1;
void add(int c)
{
    int p=last; int np=last=++tot;
    b[np].len=b[p].len+1;
    for (;p&&b[p].ch[c]==0;p=b[p].fa) b[p].ch[c]=np;
    if (!p) b[np].fa=1;
    else {
        int q=b[p].ch[c];
        if (b[q].len==b[p].len+1) b[np].fa=q;
        else {
            int nq=++tot; b[nq]=b[q];
            b[nq].len=b[p].len+1;
            b[q].fa=b[np].fa=nq;
            for (;p&&b[p].ch[c]==q;p=b[p].fa) b[p].ch[c]=nq;
        }
    }
}
struct edge
{
    int to,_next;
}G[4*maxn+5];
int num=0;
int head[2*maxn+5],dp[2*maxn+5];
void add(int u,int v)
{
    G[++num].to=v;
    G[num]._next=head[u];
    head[u]=num;
}
int dfs(int u)
{
    int v;
    if (dp[u]!=-1) return dp[u];
    dp[u]=1;
    for (int i=0;i<26;i++) {
        v=b[u].ch[i];
        if (v) dp[u]+=dfs(v);
    }
    return dp[u];
}
void kth(int k)
{
    ans.clear();
    int u=1;
    while (k) {
        for (int i=0;i<26;i++)
        if (b[u].ch[i]) {
            if (dp[b[u].ch[i]]<k) k-=(dp[b[u].ch[i]]);
            else {
                u=b[u].ch[i]; ans.push_back((char)'a'+i); k--; break;
            }
        }
    }
}
int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    for (int i=1;i<=len;i++) add(s[i]-'a');
    //for (int i=1;i<=tot;i++) printf("debug %d %d\n",i,b[i].fa);
    //for (int i=1;i<=tot;i++) printf("debug %d %d\n",i,dp[i]);
    memset(dp,-1,sizeof(dp));
    for (int i=1;i<=tot;i++) dfs(i);
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&x);
        kth(x);
        for (int i=0;i<ans.size();i++) printf("%c",ans[i]); printf("\n");
    }
    return 0;
}

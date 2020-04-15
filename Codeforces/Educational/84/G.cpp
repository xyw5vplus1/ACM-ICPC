#include<bits/stdc++.h>
using namespace std;
struct AC_Automaton
{
    const int N=1005;
    int trie[N][14];
    int tot=0;
    int fail[N];
    bool ed[N];
    void insertTrie(char s[],int k)
    {
        int len=strlen(s);
        int cur=0;
        for (int i=0;i<len;i++) {
            int x=s[i]-'a';
            if (!trie[cur][x]) trie[cur][x]=++tot;
            cur=trie[cur][x];
        }
        ed[cur]=k;
    }
    queue<int> q;
    void build()
    {
        for (int i=0;i<26;i++)
            if (trie[0][i]) q.push(trie[0][i]);
        while (q.size()) {
            int u=q.front(); q.pop();
            for (int i=0;i<26;i++) {
                if (trie[u][i]) {
                    fail[trie[u][i]]=trie[fail[u]][i]; q.push(trie[u][i]);
                    ed[trie[u][i]]+=ed[fail[trie[u][i]]];
                }
                else trie[u][i]=trie[fail[u]][i];
            }
        }
    }
    void dp()
    {

    }
}S;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%s",s); scanf("%d",&x);
        S.insertTrie(s,x);
    }
    S.build();

}

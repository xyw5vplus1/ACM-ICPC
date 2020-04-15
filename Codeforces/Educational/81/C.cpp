/*#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
vector<int> v[26];
int T;
char s1[maxn+5],s2[maxn+5];
int main()
{
    scanf("%d",&T);
    while (T--) {
        for (int i=0;i<26;i++) v[i].clear();
        scanf("%s",s1);
        int len1=strlen(s1);
        for (int i=0;i<len1;i++) {
            v[s1[i]-'a'].push_back(i);
        }
        scanf("%s",s2);
        int len2=strlen(s2);
        int cur=-1;
        int ans=1;
        bool bo=true;
        for (int i=0;i<len2;i++) {
            int x=s2[i]-'a';
            if (v[x].size()==0) {
                bo=false;
                printf("-1\n");
                break;
            }
            int nxt=upper_bound(v[x].begin(),v[x].end(),cur)-v[x].begin();
            if (nxt==v[x].size()) {
                ans++; cur=v[x][0];
            }
            else {
                cur=v[x][nxt];
            }
        }
        if (bo) printf("%d\n",ans);
    }
    return 0;
}*/



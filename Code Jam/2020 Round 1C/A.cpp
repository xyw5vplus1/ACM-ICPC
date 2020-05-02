#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000;
typedef double db;
int T;
char s[maxn];
int x,y,len;
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&x,&y);
        scanf("%s",s+1);
        len=strlen(s+1);
        if (x==0&&y==0) {
            printf("Case #%d: %d\n",kase,0);
            continue;
        }
        int ans=-1;
        for (int i=1;i<=len;i++) {
            if (s[i]=='N') y++;
            else if (s[i]=='S') y--;
            else if (s[i]=='E') x++;
            else if (s[i]=='W') x--;
            if (abs(x)+abs(y)<=i) {
                ans=i; break;
            }
        }
        if (ans==-1) printf("Case #%d: IMPOSSIBLE\n",kase);
        else printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}

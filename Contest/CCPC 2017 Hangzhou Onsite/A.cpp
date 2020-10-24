#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
char s[maxn];
int T;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%s",s);
        int len=strlen(s);
        int mn=len;
        for (int i=0;i<26;i++)
        for (int j=0;j<26;j++) {
            int cnt=0;
            for (int k=0;k<len;k++) {
                if (k&1) {
                    if (s[k]!='a'+i) cnt++;
                }
                else
                    if (s[k]!='a'+j) cnt++;
            }
            mn=min(mn,cnt);
        }
        printf("%d\n",mn);
    }
    return 0;
}

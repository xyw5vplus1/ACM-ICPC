#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+10;
int sum[maxn];
char s[maxn],s1[maxn];
int T;
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1);
        bool ans=false;
        for (int k=1;k<=n;k++) {
            for (int j=1;j<=k;j++)
                if (s[j]=='?') s1[j]='(';
                else s1[j]=s[j];
            for (int j=k+1;j<=n;j++)
                if (s[j]=='?') s1[j]=')';
                else s1[j]=s[j];
            for (int i=1;i<=n;i++)
                if (s1[i]=='(') sum[i]=sum[i-1]+1;
                else if (s1[i]==')') sum[i]=sum[i-1]-1;
            bool bo=true;
            for (int i=1;i<=n;i++)
                if (sum[i]<0) bo=false;
            if (sum[n]!=0) bo=false;
            if (bo) ans=true;
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

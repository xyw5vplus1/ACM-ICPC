#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a-1;i>=b;i--)
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
clock_t startTime;
const int maxn=1e5+10;
mt19937 mrand(random_device{}());
db getCurrentTime()
{
    return (db)(clock()-startTime)/CLOCKS_PER_SEC;
}
char s[maxn];
int T,x,y;
int main()
{
    startTime=clock();
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&x,&y);
        scanf("%s",s);
        int cntL=0,cntR=0,cntU=0,cntD=0;
        int len=strlen(s);
        rep(i,0,len) {
            if (s[i]=='L') cntL++;
            else if (s[i]=='R') cntR++;
            else if (s[i]=='U') cntU++;
            else if (s[i]=='D') cntD++;
        }
        if (x>=-cntL&&x<=cntR&&y>=-cntD&&y<=cntU) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

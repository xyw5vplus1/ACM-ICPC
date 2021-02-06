#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a-1;i>=b;i--)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int maxn=2e3+10;
const int maxm=2e5+10;
const int INF=0x3f3f3f3f;
int T,n,m;
int mx;
char mp[maxn][maxn];
int b[maxn];
bool cmp(int x,int y)
{
    return mp[x][y]=='a';
}
int main()
{
    int TT;
    scanf("%d",&T); TT=T;
    rep(kase,1,T+1){
        scanf("%d%d",&n,&m);
        rep(i,1,n+1) {
            scanf("%s",mp[i]+1);
        }
        int x=-1,y=-1;
        rep(i,1,n+1) {
            rep(j,i+1,n+1)
            if (mp[i][j]==mp[j][i]) {
                x=i; y=j; break;
            }
            if (x!=-1) break;
        }
        if (x!=-1) {
            printf("YES\n");
            rep(i,1,m+2) {
                if (i%2) printf("%d ",x);
                else printf("%d ",y);
            }
            printf("\n");
            continue;
        }
        if (m%2==1) {
            printf("YES\n");
            rep(i,1,m+2) {
                if (i%2==1) printf("%d ",1);
                else printf("%d ",2);
            }
            printf("\n");
        }
        else if (n<=2) {
            printf("NO\n");
            continue;
        }
        else {
            if (mp[1][2]==mp[2][3]&&mp[2][3]==mp[3][1]) {
                printf("YES\n");
                rep(i,1,m+2) {
                    printf("%d ",i%3+1);
                }
                printf("\n");
                continue;
            }
            printf("YES\n");
            rep(i,1,4) b[i]=i;
            sort(b+1,b+4,cmp);
            int x=b[1],y=b[2],z=b[3];
            assert(mp[x][y]=='a'&&mp[x][z]=='a'&&mp[y][z]=='a');
            int d=m/2;
            if (d%2==1) {
                rep(i,0,d/2) printf("%d %d ",x,z); printf("%d ",x);
                printf("%d ",y); printf("%d ",z);
                rep(i,0,d/2) printf("%d %d ",y,z);
            }
            else {
                rep(i,0,d/2) printf("%d %d ",y,z); printf("%d ",y);
                printf("%d ",x);
                rep(i,0,d/2-1) printf("%d %d ",y,x); printf("%d ",y);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
2 6
*a
a*
3 5
*aa
b*a
bb*
4 7
*aaa
b*aa
bb*a
bbb*
4 6
*aaa
b*aa
bb*a
bbb*
4 8
*aaa
b*aa
bb*a
bbb*
4 2
*aaa
b*aa
bb*a
bbb*
*/

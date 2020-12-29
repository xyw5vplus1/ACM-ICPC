#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=3e6+10;
int T,n,k;
char s[maxn],sf[maxn];
int cnt[maxn],sum[maxn];
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        for (int i=1;i<=n;i++) sf[i]='1'-s[i]+'0';
        sum[0]=0;
        for (int i=1;i<=n;i++) sum[i]=sum[i-1]+sf[i]-'0';
        int t=0;
        while ((1<<t)<=n-k+1) t++;
        t=min(t,k);
        //printf("debug %d\n",t);
        for (int i=0;i<(1<<t);i++) cnt[i]=0;
        for (int i=k;i<=n;i++) {
            int cur=0;
            if (sum[i-t]-sum[i-k]) continue;
            for (int j=i,base=1;j>=i-t+1;j--,base<<=1) {
                cur=(cur+(sf[j]-'0')*base);
            }
            cnt[cur]++;
        }
        //for (int i=0;i<(1<<t);i++) printf("%d ",cnt[i]); printf("\n");
        int ans=-1;
        for (int i=0;i<(1<<t);i++)
            if (!cnt[i]) {
                ans=i; break;
            }
        //printf("ans=%d\n",ans);
        if (ans==-1) printf("NO\n");
        else {
            printf("YES\n");
            for (int i=0;i<k-t;i++) printf("%d",0);
            for (int i=t-1;i>=0;i--)
                if (ans&(1<<i)) printf("1");
                else printf("0");
            printf("\n");
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7;
const ll INF=1e18;
int a,b;
char st[maxn+5],s[maxn+5];
int pre[maxn+5];
int len;
void calc_pre()
{
    pre[1]=0;
    for (int i=2,j=0;i<=len;i++) {
        while (j>0&&s[i]!=s[j+1]) j=pre[j];
        if (s[i]==s[j+1]) j++;
        pre[i]=j;
    }
}
int main()
{
    scanf("%d%d",&a,&b);
    scanf("%s",st+1);
    len=strlen(st+1);
    int k=-1;
    for (int i=1;i<=len;i++)
        if (st[i]=='.') k=i;
    for (int i=k;i<=len+1;i++) s[i-k]=st[i];
    len=strlen(s+1);
    for (int i=1;i<len-i+1;i++) swap(s[i],s[len-i+1]);
    calc_pre();
    ll ans=-INF;
    for (int i=1;i<=len;i++) {
        int x=i-pre[i];
        ans=max(ans,1LL*a*i-1LL*b*x);
    }
    printf("%lld\n",ans);
    return 0;
}

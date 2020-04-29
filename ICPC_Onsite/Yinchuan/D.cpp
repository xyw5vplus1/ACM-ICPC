#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5;
const int mod=59964251;
const int p1=643;
const int p2=93257;
int primes[maxn+5],mob[maxn+5],sum[maxn+5];
int num=0;
bool is_prime[maxn+5];
char s[maxn+5];
int m,k,d;
void Sieve(int n)
{
    mob[1]=1;
    for (int i=2;i<=n;i++) is_prime[i]=true;
    for (int i=2;i<=n;i++) {
        if (is_prime[i]) {
            primes[num++]=i; mob[i]=-1;
        }
        for (int j=0;j<num&&1LL*primes[j]*i<=n;j++) {
            is_prime[i*primes[j]]=false;
            if (i%primes[j]==0) {
                mob[i*primes[j]]=0; break;
            }
            else {
                mob[i*primes[j]]=-mob[i];
            }
        }
    }
}
int quick_pow(int a,int b,int mod)
{
    int ans=1;
    while (b) {
        if (b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans;
}
int g(int n,int d,int md)
{
    int t=sum[m/d];
    if (t==0) return 0;
    int ans=quick_pow(t,n,md);
    ans=1LL*ans*quick_pow(d,1LL*k*n%(md-1),md)%md;
    return ans;
}
int calc(int md)
{
    int up=m/d;
    sum[0]=0;
    for (int i=1;i<=m;i++) sum[i]=(sum[i-1]+quick_pow(i,k,md))%md;
    int n=0;
    int len=strlen(s);
    for (int i=0;i<len;i++) n=(n*10+s[i]-'0')%(md-1);
    int ans=0;
    for (int i=1;i<=up;i++) {
        ans=(ans+mob[i]*g(n,i*d,md))%md;
        //printf("debug %d %d %d\n",i*d,md,g(i*d,md));
        if (ans<0) ans+=md;
    }
    return ans;
}
int T;
int main()
{
    Sieve(maxn);
    scanf("%d",&T);
    while (T--) {
        scanf("%s%d%d%d",s,&m,&d,&k);
        int r1=calc(p1),r2=calc(p2);
        int t1=quick_pow(p2,p1-2,p1),t2=quick_pow(p1,p2-2,p2);
        int ans=0;
        ans=(ans+1LL*r1*p2%mod*t1%mod)%mod;
        ans=(ans+1LL*r2*p1%mod*t2%mod)%mod;
        printf("%d\n",ans);
    }
    return 0;
}

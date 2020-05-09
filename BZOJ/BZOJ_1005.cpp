#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int a[maxn];
int n;
int primes[maxn];
bool is_prime[maxn];
int num=0;
struct BigInt
{
    const static int mod=10000;
    const static int DLEN=4;
    int a[2000],len;
    BigInt()
    {
        memset(a,0,sizeof(a));
        len=1;
    }
    BigInt(int v)
    {
        memset(a,0,sizeof(a));
        len=0;
        do{
            a[len++]=v%mod;
            v/=mod;
        }while(v);
    }
    BigInt(const char s[])
    {
        memset(a,0,sizeof(a));
        int L=strlen(s);
        len=L/DLEN;
        if(L%DLEN)len++;
        int index=0;
        for (int i=L-1;i>=0;i-=DLEN) {
            int t=0;
            int k=i-DLEN+1;
            if (k<0) k=0;
            for (int j=k;j<=i;j++) t=t*10+s[j]-'0';
            a[index++]=t;
        }
    }
    BigInt operator +(const BigInt &b) const
    {
        BigInt res;
        res.len=max(len,b.len);
        for (int i=0;i<=res.len;i++) res.a[i]=0;
        for (int i=0;i<res.len;i++)
        {
            res.a[i]+=((i<len)?a[i]:0)+((i<b.len)?b.a[i]:0);
            res.a[i+1]+=res.a[i]/mod;
            res.a[i]%=mod;
        }
        if (res.a[res.len]>0) res.len++;
        return res;
    }
    BigInt operator *(const BigInt &b) const
    {
        BigInt res;
        for (int i=0;i<len;i++) {
            int up=0;
            for (int j=0;j<b.len;j++) {
                int temp=a[i]*b.a[j]+res.a[i+j]+up;
                res.a[i+j]=temp%mod;
                up=temp/mod;
            }
            if (up!=0) res.a[i+b.len]=up;
        }
        res.len=len+b.len;
        while (res.a[res.len-1]==0&&res.len>1) res.len--;
        return res;
    }
    void output()
    {
        printf("%d",a[len-1]);
        for(int i=len-2;i>=0;i--) printf("%04d",a[i]);
        printf("\n");
    }
};
BigInt C(int n,int m)
{
    BigInt ans(1);
    if (n<m) return BigInt(0);
    for (int i=1;i<=m;i++) {

    }
}
BigInt quick_pow(BigInt a,int b)
{
    BigInt ans(1);
    while (b) {
        if (b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
void Sieve(int n)
{
    for (int i=2;i<=n;i++) is_prime[i]=true;
    for (int i=2;i<=n;i++) {
        if (is_prime[i]) primes[num++]=i;
        for (int j=0;j<num&&1LL*i*primes[j]<=n;j++) {
            is_prime[i*primes[j]]=false;
            if (i%primes[j]==0) break;
        }
    }
}
int calc(int p,int x)
{
    int ans=0;
    while (x) {
        ans+=(x/p);
        x/=p;
    }
    return ans;
}
int main()
{
    Sieve(1000);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int cnt=0,sum=0;
    for (int i=1;i<=n;i++)
        if (a[i]==-1) cnt++;
        else sum+=a[i]-1;
    if (sum>n-2) printf("0\n");
    else {
        BigInt ans(1);
        for (int i=0;i<num;i++) {
            int tem=calc(primes[i],n-2);
            for (int j=1;j<=n;j++)
                if (a[j]!=-1) tem-=calc(primes[i],a[j]-1);
            tem-=calc(primes[i],n-2-sum);
            ans=ans*quick_pow(BigInt(primes[i]),tem);
        }
        for (int i=0;i<n-2-sum;i++) ans=ans*BigInt(cnt);
        ans.output();
    }
    return 0;
}

#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
const int maxn=1000+10;
int d[maxn][30],father[maxn];
int T,n,m,x,y,u,v;
int a[30];
bool is_prime[105];
int primes[30];
int num=0;
int _find(int x)
{
	if (x==father[x]) return x;
	int u=_find(father[x]);
    rep(j,1,26) d[x][j]+=d[father[x]][j];
    d[x][0]^=d[father[x]][0];
	father[x]=u;
	return father[x];
}
bool _merge(int u,int v,int a[])
{
	int fu=_find(u),fv=_find(v);
	if (fu==fv) {
        rep(i,1,26)
            if (d[u][i]-d[v][i]!=a[i]) return false;
        if ((d[u][0]^d[v][0])!=a[0]) return false;
        return true;
	}
    rep(i,1,26) d[fu][i]=d[v][i]-d[u][i];
    d[fu][0]=(d[v][0]^d[u][0]);
    rep(i,1,26) d[fu][i]=d[fu][i]+a[i];
    d[fu][0]=(d[fu][0]^a[0]);
	father[fu]=fv;
	return true;
}
void Sieve(int n)
{
    rep(i,2,n+1) is_prime[i]=true;
    rep(i,2,n+2) {
        if (is_prime[i]) primes[++num]=i;
        for (int j=1;j<=num&&1LL*primes[j]*i<=n;j++) {
            is_prime[i*primes[j]]=false;
            if (i%primes[j]==0) break;
        }
    }
}
void calc(int a[],int x,int d)
{
    rep(i,1,num+1) {
        while (x%primes[i]==0) {
            x/=primes[i]; a[i]+=d;
        }
        if (x==1) break;
    }
}
int main()
{
    Sieve(100);
    scanf("%d",&T);
	rep(kase,1,T+1) {
		scanf("%d%d",&n,&m);
		rep(i,1,n+1) {
			father[i]=i;
			rep(j,0,26) d[i][j]=0;
		}
		bool bo=true;
		while (m--) {
			scanf("%d%d%d%d",&x,&y,&u,&v);
			if (!bo) continue;
			memset(a,0,sizeof(a));
			calc(a,u,1); calc(a,abs(1.0*v),-1);
			if (v<0) a[0]=1;
			bo&=_merge(x,y,a);
		}
		printf("Case #%d: %s\n",kase,bo?"Yes":"No");
	}
	return 0;
}

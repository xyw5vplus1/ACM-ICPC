#include<iostream>
#include<vector>
using namespace std;
vector<int> primes;
const int maxn=1e5;
bool is_prime[maxn+5];
int phi[maxn+5];
void set_phi_table(int n)
{
    for (int i=2;i<=n;i++) {
        is_prime[i]=true;
        phi[i]=i;
    }
    for (int i=2;i<=n;i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            phi[i]=i-1;
        }
        phi[1]=1;
        for (int j=0;j<primes.size()&&i*primes[j]<=n;j++) {
            is_prime[i*primes[j]]=false;
            if (i%primes[j]==0) {
                phi[i*primes[j]]=phi[i]*primes[j];break;
            }
            else phi[i*primes[j]]=phi[i]*(primes[j]-1);
        }
    }
}
int main()
{
    int n,m,i,x;
    long long ans;
    ios::sync_with_stdio(false);
    cin>>n;
    set_phi_table(n);
    if (n==1) cout<<0<<endl;
    else {
        ans=0;
        for (i=1;i<n;i++) ans+=phi[i];
        ans=ans*2+1;
        cout<<ans<<endl;
    }
    return 0;
}

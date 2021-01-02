#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int f(int x)
{
    int ans=0;
    while (x) {
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d\n",max(f(n),f(m)));
    return 0;
}

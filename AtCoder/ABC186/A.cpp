#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define pb push_back
#define first fi
#define second se
using namespace std;
typedef long long ll;
typedef double db;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    printf("%d\n",n/k);
    return 0;
}

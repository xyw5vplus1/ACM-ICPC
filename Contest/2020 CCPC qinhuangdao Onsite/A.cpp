#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int C2(int n)
{
    return n*(n-1)/2;
}
int gcd(int n,int m)
{
    if (m==0) return n;
    return gcd(m,n%m);
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&a,&b);
        int x=C2(a);
        int y=C2(a+b);
        int d=gcd(x,y);
        printf("Case #%d: %d/%d\n",kase,x/d,y/d);
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int calc(int cnt,int add)
{
    int n0=n-add;
    if (n0%cnt) return -1;
    return n0/cnt;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d",&n);
        printf("Case #%d: ",kase);
        if (n==6) {
            printf("-1\n");
            continue;
        }
        if (n%4==1) {
            printf("1\n");
            continue;
        }
        if (n%4==3) {
            printf("1\n");
            continue;
        }
        if (n%4==0) {
            printf("2\n");
            continue;
        }
        int t=calc(3,3);
        if (t!=-1&&__gcd(t,t+2)==1) {
            printf("2\n");
            continue;
        }
        t=calc(3,4);
        if (t!=-1&&__gcd(t,t+3)==1&&__gcd(t+1,t+3)==1) {
            printf("3\n");
            continue;
        }
        t=calc(3,5);
        if (t!=-1&&__gcd(t,t+2)==1&&__gcd(t,t+3)==1) {
            printf("3\n");
            continue;
        }
        printf("4\n");
    }
    return 0;
}

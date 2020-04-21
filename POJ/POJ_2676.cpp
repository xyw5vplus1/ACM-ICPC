#include<cstdio>
using namespace std;
int r[10],c[10],b[10];
char s[10][20];
int lg[1000];
int T;
bool bo;
int lowbit(int x)
{
    return x&(-x);
}
int getCnt(int x)
{
    int cnt=0;
    while (x) {
        x&=(x-1);
        cnt++;
    }
    return cnt;
}
void dfs(int last)
{
    if (bo) return ;
    if (last==0) {
        for (int i=0;i<9;i++) printf("%s\n",s[i]);
        bo=true;
        return ;
    }
    int px=-1,py=-1;
    int mn=10;
    for (int i=0;i<9;i++)
    for (int j=0;j<9;j++) {
        if (s[i][j]=='0') {
            //printf("debug %d %d\n",i,j);
            int x=((r[i]&c[j])&(b[(i/3)*3+j/3]));
            int t=getCnt(x);
            if (t<mn) {
                mn=t; px=i; py=j;
            }
        }
    }
    int x=((r[px]&c[py])&(b[(px/3)*3+py/3]));
    while (x) {
        if (bo) return ;
        int t=lg[lowbit(x)];
        //printf("%d\n",t+1);
        s[px][py]='0'+t+1;
        r[px]^=(1<<t);
        c[py]^=(1<<t);
        b[(px/3)*3+py/3]^=(1<<t);
        dfs(last-1);
        s[px][py]='0';
        r[px]^=(1<<t);
        c[py]^=(1<<t);
        b[(px/3)*3+py/3]^=(1<<t);
        x-=lowbit(x);
    }
}
int main()
{
    lg[1]=0;
    for (int i=1;i<=9;i++) lg[1<<i]=i;
    scanf("%d",&T);
    while (T--) {
        bo=false;
        int last=0;
        for (int i=0;i<9;i++) scanf("%s",s[i]);
        for (int i=0;i<9;i++) {
            int t=(1<<9)-1;
            for (int j=0;j<9;j++) {
                int x=s[i][j]-'0'-1;
                if (x>=0) t^=(1<<x);
            }
            r[i]=t;
        }
        for (int j=0;j<9;j++) {
            int t=(1<<9)-1;
            for (int i=0;i<9;i++) {
                int x=s[i][j]-'0'-1;
                if (x>=0) t^=(1<<x);
            }
            c[j]=t;
        }
        for (int i=0;i<3;i++)
        for (int j=0;j<3;j++) {
            int t=(1<<9)-1;
            for (int l=i*3;l<i*3+3;l++)
            for (int r=j*3;r<j*3+3;r++) {
                int x=s[l][r]-'0'-1;
                if (x>=0) t^=(1<<x);
            }
            b[i*3+j]=t;
        }
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                if (s[i][j]=='0') last++;
        dfs(last);
    }
    return 0;
}

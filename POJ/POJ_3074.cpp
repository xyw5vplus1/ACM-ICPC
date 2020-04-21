#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int r[10],c[10],b[10];
char s[10][20];
int lg[1000];
char str[100];
int a[2000];
int T;
bool bo;
vector<pair<int,int> > v;
bool cmp(pair<int,int> e1,pair<int,int> e2)
{
    int x1,t1,x2,t2;
    x1=((r[e1.first]&c[e1.second])&(b[(e1.first/3)*3+e1.second/3]));
    t1=a[x1];
    x2=((r[e2.first]&c[e2.second])&(b[(e2.first/3)*3+e2.second/3]));
    t2=a[x2];
    return t1>t2;
}
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
    //printf("debug %d\n",last);
    if (bo) return ;
    if (last==0) {
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++) printf("%c",s[i][j]);
        printf("\n");
        bo=true;
        return ;
    }
    int px=-1,py=-1;
    int x,t;
    sort(v.begin(),v.end(),cmp);
    //for (int i=0;i<v.size();i++) printf("debug %d %d %d\n",i,v[i].first,v[i].second);
    px=v[v.size()-1].first,py=v[v.size()-1].second;
    //printf("debug %d %d\n",px,py);
    x=((r[px]&c[py])&(b[(px/3)*3+py/3]));
    v.pop_back();
    while (x) {
        if (bo) return ;
        t=lg[lowbit(x)];
        //printf("%d\n",t+1);
        s[px][py]='0'+t+1;
        r[px]^=(1<<t);
        c[py]^=(1<<t);
        b[(px/3)*3+py/3]^=(1<<t);
        dfs(last-1);
        s[px][py]='.';
        r[px]^=(1<<t);
        c[py]^=(1<<t);
        b[(px/3)*3+py/3]^=(1<<t);
        x-=lowbit(x);
    }
    v.push_back(make_pair(px,py));
}
int main()
{
    lg[1]=0;
    for (int i=1;i<=9;i++) lg[1<<i]=i;
    for (int i=0;i<1024;i++) a[i]=getCnt(i);
    while (scanf("%s",str)!=EOF) {
        bo=false;
        int last=0;
        v.clear();
        if (str[0]=='e') return 0;
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++) s[i][j]=str[i*9+j];
        for (int i=0;i<9;i++) {
            int t=(1<<9)-1;
            for (int j=0;j<9;j++)
            if (s[i][j]!='.'){
                int x=s[i][j]-'0'-1;
                t^=(1<<x);
            }
            r[i]=t;
        }
        for (int j=0;j<9;j++) {
            int t=(1<<9)-1;
            for (int i=0;i<9;i++)
            if (s[i][j]!='.'){
                int x=s[i][j]-'0'-1;
                t^=(1<<x);
            }
            c[j]=t;
        }
        for (int i=0;i<3;i++)
        for (int j=0;j<3;j++) {
            int t=(1<<9)-1;
            for (int l=i*3;l<i*3+3;l++)
            for (int r=j*3;r<j*3+3;r++)
            if (s[i][j]!='.'){
                int x=s[l][r]-'0'-1;
                t^=(1<<x);
            }
            b[i*3+j]=t;
        }
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                if (s[i][j]=='.') {
                    last++;
                    v.push_back(make_pair(i,j));
                }
        sort(v.begin(),v.end(),cmp);
        dfs(last);
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[50][100][100][50];
int x;
int dfs(vector<int> v)
{
    int sum=0;
    for (int i=0;i<4;i++) sum+=v[i];
    //printf("debug %d %d %d %d\n",v[0],v[1],v[2],v[3]);
    if (sum<=1) return 0;
    if (dp[v[0]][v[1]][v[2]][v[3]]!=-1) return dp[v[0]][v[1]][v[2]][v[3]];
    set<int> s;
    for (int i=0;i<4;i++)
        for (int j=i;j<4;j++)
        if (v[i]>0&&v[j]>0&&i+j<=3) {
            vector<int> tem;
            for (int k=0;k<4;k++) tem.push_back(v[k]);
            tem[i]--; tem[j]--;
            if (tem[i]<0) continue;
            if (tem[j]<0) continue;
            tem[i+j]++;
            s.insert(dfs(tem));
        }
    int ans=0;
    while (s.count(ans)) ans++;
    return dp[v[0]][v[1]][v[2]][v[3]]=ans;
}
void lose()
{
    printf("Horse\n");
}
void win()
{
    printf("Rabbit\n");
}
int T;
bool check(vector<int> v)
{
    int n0,n1,n2,n3;
    n0=v[0]; n1=v[1]; n2=v[2]; n3=v[3];
    if (!(n0>0||n1>0||n2>0||n3>0)) {
        return false;
    }
    if (n0&1) {
        if (n1==0) {
            if (n2==0&&n3==0) return false;
            else return true;
        }
        else if (n1%3==1) {
            if (n2==0) return true;
            else return false;
        }
        else if (n1%3==2) {
            if (n2==0||n2==1) return false;
            else return true;
        }
        else return true;
    }
    else {
        if (n1==0) {
            if (n2==0&&n3==0) return true;
            else return false;
        }
        else if (n1%3==1) {
            if (n2==0) return false;
            else return true;
        }
        else if (n1%3==2) return true;
        else if (n1%3==0) return false;
    }
}
int main()
{

    /*memset(dp,-1,sizeof(dp));
    for (int i=0;i<=15;i++)
        for (int j=0;j<=15;j++)
        for (int k=0;k<=15;k++)
    for (int l=0;l<=15;l++) {
        vector<int> v;
        v.push_back(i); v.push_back(j); v.push_back(k); v.push_back(l);
        if ((dfs(v)!=0)!=check(v)) {
            printf("debug %d %d %d %d (%d %d)\n",i,j,k,l,dfs(v),check(v));
            break;
        }
        //printf("SG (%d %d %d %d) : %d\n",i,j,k,l,dfs(v));
    }*/
    scanf("%d",&T);
    int n0,n1,n2,n3;
    for (int kase=1;kase<=T;kase++){
        scanf("%d%d%d%d",&n0,&n1,&n2,&n3);
        printf("Case #%d: ",kase);
        vector<int> v;
        v.push_back(n0); v.push_back(n1); v.push_back(n2); v.push_back(n3);
        if (check(v)) win();
        else lose();
    }
    return 0;
}

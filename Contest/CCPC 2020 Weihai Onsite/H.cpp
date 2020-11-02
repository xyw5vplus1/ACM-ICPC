#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int maxm=2e5+10;
vector<int> tim[maxm];
map<int,int> mp[maxm];
int ans[maxm];
int n,m,t,op,x,y;
int getCnt(int group,int L,int R)
{
    return lower_bound(tim[group].begin(),tim[group].end(),R)-lower_bound(tim[group].begin(),tim[group].end(),L);
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for (int i=1;i<=t;i++) {
        scanf("%d%d%d",&op,&x,&y);
        if (op==3) {
            tim[y].push_back(i);
            ans[x]--;
        }
        else if (op==1) {
            mp[x][y]=i;
        }
        else {
            int l=mp[x][y];
            int r=i;
            ans[x]+=getCnt(y,l,r);
            mp[x][y]=-1;
        }
    }
    for (int i=1;i<=m;i++) {
        for (map<int,int>::iterator iter=mp[i].begin();iter!=mp[i].end();iter++) {
            if ((*iter).second!=-1) {
                ans[i]+=getCnt((*iter).first,(*iter).second,t+1);
            }
        }
    }
    for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}

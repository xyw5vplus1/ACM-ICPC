#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
typedef long long ll;
unordered_map<int,int> root[maxn];
int father[maxn],a[maxn];
int n,m,u,v,x,op;
vector<int> vec[maxn];
ll ans=0;
int getFather(int x)
{
    if (x==father[x]) return x;
    father[x]=getFather(father[x]);
    return father[x];
}
void _merge(int u,int v)
{
    int fu=getFather(u),fv=getFather(v);
    if (fu==fv) return ;
    if (root[fu].size()>root[fv].size()) swap(fu,fv);
    for (auto e:root[fu]) {
        int p=e.first;
        for (auto q:vec[p])
            if (root[fv].count(q)) ans+=1LL*e.second*root[fv][q];
    }
    for (auto e:root[fu]) {
        int p=e.first;
        root[fv][p]+=e.second;
    }
    root[fu].clear();
    father[fu]=fv;
}
int main()
{
    for (int c=1;c<=200000;c++)
        for (int a=c;a<=200000;a+=c) {
            int b=a-c;
            if (c==(a^b)) {
                vec[a].push_back(b);
                vec[b].push_back(a);
            }
        }
    /*for (int i=1;i<10;i++) {
        for (auto j:vec[i]) printf("%d ",j);
        printf("\n");
    }*/
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) father[i]=i;
    for (int i=1;i<=n;i++) root[i][a[i]]=1;
    while (m--) {
        scanf("%d",&op);
        if (op==1) {
            scanf("%d%d",&x,&v);
            a[x]=v;
            father[x]=x;
            root[x][v]=1;
        }
        else if (op==2) {
            scanf("%d%d",&u,&v);
            _merge(u,v);
            //for (auto e:root[fu]) printf("debug %d %d\n",e.first,e.second);
        }
        else if (op==3) {
            scanf("%d%d",&x,&v);
            int fx=getFather(x);
            for (auto e:vec[a[x]])
                if (root[fx].count(e)) ans-=root[fx][e];
            root[fx][a[x]]--;
            a[x]=v;
            for (auto e:vec[a[x]])
                if (root[fx].count(e)) ans+=root[fx][e];
            root[fx][v]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
10 7
6 6 4 7 7 4 6 4 6 5
2 5 1
2 10 7
2 8 7
2 7 2
2 6 2
3 9 5
2 9 1
*/

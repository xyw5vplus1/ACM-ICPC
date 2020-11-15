#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
vector<int> v0,v1;
vector<int> v;
int n,m,T,x;
ll ans1=0,ans2=0;
bool bo[maxn+5];
int a[maxn+5],b[maxn+5];
struct node
{
    int id;
    int val;
    node (int _d=0,int _v=0)
    {
        id=_d; val=_v;
    }
    bool operator < (const node &e) const
    {
        return val>e.val;
    }
};
priority_queue<node> q;
bool calc()
{
    int cur=1;
    while (q.size()) q.pop();
    for (int i=0;i<v1.size();i++) {
        int t=v1[i];
        while (cur<=n&&a[cur]>=t) {
            q.push(node(cur,a[cur]));
            cur++;
        }
        if (q.empty()) return false;
        node e=q.top(); q.pop();
        bo[e.id]=false;
    }
    return true;
}
void Init()
{
    for (int i=1;i<=n;i++) bo[i]=true;
    v0.clear(); v1.clear(); v.clear();
    ans1=0; ans2=0;
}
int main()
{
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++){
        scanf("%d%d",&n,&m);
        Init();
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=m;i++) scanf("%d",&b[i]);
        for (int i=1;i<=m;i++) {
            scanf("%d",&x);
            if (x==0) v0.push_back(b[i]);
            else v1.push_back(b[i]);
        }
        sort(a+1,a+n+1,greater<int>());
        sort(v1.begin(),v1.end(),greater<int>());
        sort(v0.begin(),v0.end());
        if (calc()) {
            for (int i=1;i<=n;i++)
                if (bo[i]) v.push_back(a[i]);
            sort(v.begin(),v.end(),greater<int>());
            for (int i=0;i<v.size();i++)
                if (i<v0.size()) ans1+=max(0,v[i]-v0[i]);
                else ans1+=v[i];
        }
        else {
            v.clear();
            for (int i=1;i<=n;i++) v.push_back(a[i]);
            for (int i=0;i<min(n,(int)v0.size());i++) ans2+=max(0,v[i]-v0[i]);
        }
        printf("Case %d: %lld\n",kase,max(ans1,ans2));
    }
    return 0;
}


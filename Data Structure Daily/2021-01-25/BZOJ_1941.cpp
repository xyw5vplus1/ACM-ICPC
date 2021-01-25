#include<bits/stdc++.h>
#define lson(p) p<<1
#define rson(p) p<<1|1
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a-1;i>=b;i--)
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int maxn=5e5+10;
const int INF=0x3f3f3f3f;
int n,qx,qy,mx,mn,cmpd,ans;
struct node
{
    int l,r;
    int mx[2],mn[2];
    int d[2];
}tr[maxn];
bool cmp(node a,node b)
{
    return a.d[cmpd]<b.d[cmpd]||(a.d[cmpd]==b.d[cmpd]&&a.d[cmpd^1]<b.d[cmpd^1]);
}
void updateMax(int &x,int y)
{
    x=max(x,y);
}
void updateMin(int &x,int y)
{
    x=min(x,y);
}
void pushup(int p)
{
    int l,r;
    l=tr[p].l; r=tr[p].r;
    if (l) {
        updateMax(tr[p].mx[0],tr[l].mx[0]);
        updateMax(tr[p].mx[1],tr[l].mx[1]);
        updateMin(tr[p].mn[0],tr[l].mn[0]);
        updateMin(tr[p].mn[1],tr[l].mn[1]);
    }
    if (r) {
        updateMax(tr[p].mx[0],tr[r].mx[0]);
        updateMax(tr[p].mx[1],tr[r].mx[1]);
        updateMin(tr[p].mn[0],tr[r].mn[0]);
        updateMin(tr[p].mn[1],tr[r].mn[1]);
    }
}
int build(int l,int r,int d)
{
    int mid=(l+r)>>1;
    int p=mid;
    cmpd=d;
    nth_element(tr+l,tr+mid+1,tr+r+1,cmp);
    tr[p].mx[0]=tr[p].mn[0]=tr[p].d[0];
    tr[p].mx[1]=tr[p].mn[1]=tr[p].d[1];
    if (l<mid) tr[p].l=build(l,mid-1,d^1);
    if (mid<r) tr[p].r=build(mid+1,r,d^1);
    pushup(p);
    return p;
}
int getDistMin(int p,int qx,int qy)
{
    int dist=0;
    if (qx<tr[p].mn[0]) dist+=abs(qx-tr[p].mn[0]);
    if (qx>tr[p].mx[0]) dist+=abs(qx-tr[p].mx[0]);
    if (qy<tr[p].mn[1]) dist+=abs(qy-tr[p].mn[1]);
    if (qy>tr[p].mx[1]) dist+=abs(qy-tr[p].mx[1]);
    return dist;
}
int getDistMax(int p,int qx,int qy)
{
    int dist=0;
    dist+=max(abs(qx-tr[p].mn[0]),abs(qx-tr[p].mx[0]));
    dist+=max(abs(qy-tr[p].mn[1]),abs(qy-tr[p].mx[1]));
    return dist;
}
void queryMin(int p)
{
    if (!p) return ;
    int d=abs(qx-tr[p].d[0])+abs(qy-tr[p].d[1]);
    if (d) updateMin(mn,d);
    int dl=INF,dr=INF;
    if (tr[p].l) dl=getDistMin(tr[p].l,qx,qy);
    if (tr[p].r) dr=getDistMin(tr[p].r,qx,qy);
    if (dl<dr) {
        if (dl<mn) queryMin(tr[p].l);
        if (dr<mn) queryMin(tr[p].r);
    }
    else {
        if (dr<mn) queryMin(tr[p].r);
        if (dl<mn) queryMin(tr[p].l);
    }
}
void queryMax(int p)
{
    if (!p) return ;
    int d=abs(qx-tr[p].d[0])+abs(qy-tr[p].d[1]);
    if (d) updateMax(mx,d);
    int dl=0,dr=0;
    if (tr[p].l) dl=getDistMax(tr[p].l,qx,qy);
    if (tr[p].r) dr=getDistMax(tr[p].r,qx,qy);
    if (dl>dr) {
        if (dl>mx) queryMax(tr[p].l);
        if (dr>mx) queryMax(tr[p].r);
    }
    else {
        if (dr>mx) queryMax(tr[p].r);
        if (dl>mx) queryMax(tr[p].l);
    }
}
int main()
{
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d%d",&tr[i].d[0],&tr[i].d[1]);
    int root=build(1,n,0);
    ans=INF;
    //rep(i,1,n+1) printf("debug %d %d %d\n",i,tr[i].l,tr[i].r);
    rep(i,1,n+1) {
        qx=tr[i].d[0]; qy=tr[i].d[1];
        mx=0; mn=INF;
        queryMin(root); queryMax(root);
        //printf("debug %d %d\n",mx,mn);
        updateMin(ans,mx-mn);
    }
    printf("%d\n",ans);
    return 0;
}

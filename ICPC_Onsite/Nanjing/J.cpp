#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=400;
const int INF=0x3f3f3f3f;
int son_x[maxn+5],son_y[maxn+5],prev_x[maxn+5],prev_y[maxn+5];
int w[maxn+5][maxn+5];
int n;
int slack[maxn+5];
int x[maxn+5],y[maxn+5],par[maxn+5];
ll a[maxn+5],b[maxn+5],c[maxn+5];
int p[maxn+5];
void adjust(int v)
{
    son_y[v]=prev_y[v];
    if (prev_x[son_y[v]]!=-2) adjust(prev_x[son_y[v]]);
}
bool find(int v)
{
    for (int i=0;i<n;i++)
    if (prev_y[i]==-1) {
        if (slack[i]>x[v]+y[i]-w[v][i]) {
            slack[i]=x[v]+y[i]-w[v][i];
            par[i]=v;
        }
        if (x[v]+y[i]==w[v][i]) {
            prev_y[i]=v;
            if (son_y[i]==-1) {
                adjust(i); return true;
            }
            if (prev_x[son_y[i]]!=-1) continue;
            prev_x[son_y[i]]=i;
            if (find(son_y[i])) return true;
        }
    }
    return false;
}
int km()
{
    int m;
    for (int i=0;i<n;i++) {
        son_y[i]=-1; y[i]=0;
    }
    for (int i=0;i<n;i++) {
        x[i]=-INF;
        for (int j=0;j<n;j++) x[i]=max(x[i],w[i][j]);
    }
    bool flag;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            prev_x[j]=prev_y[j]=-1;
            slack[j]=INF;
        }
        prev_x[i]=-2;
        if (find(i)) continue;
        flag=false;
        while (!flag) {
            m=INF;
            for (int j=0;j<n;j++)
                if (prev_y[j]==-1) m=min(m,slack[j]);
            for (int j=0;j<n;j++){
                if (prev_x[j]!=-1) x[j]-=m;
                if (prev_y[j]!=-1) y[j]+=m;
                else slack[j]-=m;
            }
            for (int j=0;j<n;j++)
            if (prev_y[j]==-1&&!slack[j]) {
                prev_y[j]=par[j];
                if (son_y[j]==-1) {
                    adjust(j); flag=true; break;
                }
                prev_x[son_y[j]]=j;
                if (find(son_y[j])) {
                    flag=true; break;
                }
            }
        }
    }
    int ans=0;
    for (int i=0;i<n;i++) ans+=w[son_y[i]][i];
    return ans;
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lld",&a[i]);
    for (int i=0;i<n;i++) scanf("%d",&p[i]);
    for (int i=0;i<n;i++) scanf("%lld",&b[i]);
    for (int i=0;i<n;i++) scanf("%lld",&c[i]);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        for (int k=0;k<n;k++)
        if (b[i]+c[j]>a[k]) w[i][j]+=p[k];
    printf("%d\n",km());
    return 0;
}

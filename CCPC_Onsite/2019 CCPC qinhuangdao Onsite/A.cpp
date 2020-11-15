#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
typedef double db;
typedef long long ll;
#define cross(p1,p2,p3) (1LL*(p2.x-p1.x)*(p3.y-p1.y)-1LL*(p2.y-p1.y)*(p3.x-p1.x))
#define cross0p(p1,p2,p3) sign(cross(p1,p2,p3))
using namespace std;
const db eps=1e-8;
const int maxn=4000;
int n,q;
int sum[2*maxn+5];
ll ans[maxn+5];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}
int mymax(int x,int y)
{
    if (x>y) return x;
    return y;
}
int sign(db x)
{
    return x<-eps?-1:x>eps;
}
int dcmp(db x,db y)
{
    return sign(x-y);
}
struct point
{
    int x,y;
    point (int _x=0,int _y=0){ x=_x; y=_y; }
    point operator + (const point &p) const {return point(x+p.x,y+p.y);}
    point operator - (const point &p) const {return point(x-p.x,y-p.y);}
    point operator * (db k) const{return point(x*k,y*k);}
    point operator / (db k) const{return point(x/k,y/k);}
    bool operator < (const point &p) const
    {
        int k=dcmp(x,p.x);
        if (k) return k==-1;
        return dcmp(y,p.y)==-1;
    }
    bool operator == (const point &p) const{
        return dcmp(x,p.x)==0&&dcmp(y,p.y)==0;
    }
    point turn90(){return (point){-y,x};}
    ll dot(point p){return 1LL*x*p.x+1LL*y*p.y;}
    ll det(point p){return 1LL*x*p.y-1LL*y*p.x;}
    int quad() const {return sign(y)==-1||(sign(y)==0&&sign(x)>=0);}
    int type;
};
int compareangle(point a,point b)//极角排序
{
    if (a.quad()!=b.quad()) return a.quad()<b.quad();
    return sign(a.det(b))==-1;
}
vector<point> ps,qs;
point p;
int main()
{
    n=read(); q=read();
    for (int i=1;i<=n;i++) {
        p.x=read(); p.y=read();
        p.type=0;
        ps.push_back(p);
    }
    for (int i=1;i<=q;i++) {
        p.x=read(); p.y=read();
        p.type=i;
        ps.push_back(p);
    }
    for (int i=0;i<n;i++) {
        point o=ps[i];
        qs.clear();
        for (int j=0;j<n+q;j++)
            if (j!=i) {
                point tem=ps[j]-o; tem.type=ps[j].type;
                qs.push_back(tem);
            }
        sort(qs.begin(),qs.end(),compareangle);
        reverse(qs.begin(),qs.end());
        //printf("debug state %d\n",i);
        //for (int j=0;j<qs.size();j++) printf("%.0f %.0f %d\n",qs[j].x,qs[j].y,qs[j].type);
        int n0=qs.size();
        for (int j=0;j<n0;j++) qs.push_back(qs[j]);
        memset(sum,0,sizeof(sum));
        for (int j=0;j<2*n0;j++) sum[j]=j==0?(qs[j].type==0):sum[j-1]+(qs[j].type==0);
        int l=0,r1=0,r2=0,r3=0;
        while (l<n0) {
            while (r1<l+n0&&qs[l].dot(qs[r1])>0&&qs[l].det(qs[r1])==0) r1++;
            r2=mymax(r2,r1);
            while (r2<l+n0&&qs[l].dot(qs[r2])>0&&qs[l].det(qs[r2])>0) r2++;
            r3=mymax(r3,r2);
            while (r3<l+n0&&qs[l].dot(qs[r3])==0&&qs[l].det(qs[r3])>0) r3++;
            for (int j=l;j<=r1-1;j++)
                if (qs[j].type>0) ans[qs[j].type]+=sum[r3-1]-sum[r2-1];
            for (int j=r2;j<=r3-1;j++)
                if (qs[j].type>0) ans[qs[j].type]+=sum[r1-1]-sum[l-1];
            l=r1;
        }
        //for (int j=1;j<=q;j++) printf("%d %d\n",j,ans[j]);
    }
    for (int i=n;i<n+q;i++) {
        point o=ps[i];
        qs.clear();
        for (int j=0;j<n;j++)
            if (j!=i) {
                point tem=ps[j]-o; tem.type=ps[j].type;
                qs.push_back(tem);
            }
        sort(qs.begin(),qs.end(),compareangle);
        reverse(qs.begin(),qs.end());
        int n0=qs.size();
        for (int j=0;j<n0;j++) qs.push_back(qs[j]);
        int l=0,r1=0,r2=0,r3=0;
        while (l<n0) {
            while (r1<l+n0&&qs[l].dot(qs[r1])>0&&qs[l].det(qs[r1])==0) r1++;
            r2=mymax(r2,r1);
            while (r2<l+n0&&qs[l].dot(qs[r2])>0&&qs[l].det(qs[r2])>0) r2++;
            r3=mymax(r3,r2);
            while (r3<l+n0&&qs[l].dot(qs[r3])==0&&qs[l].det(qs[r3])>0) r3++;
            if (l) ans[i-n+1]+=1LL*(r1-l)*(r3-r2);
            else ans[i-n+1]+=1LL*r1*(r3-r2);
            l=r1;
        }
        //printf("debug state %d\n",i);
        //for (int j=1;j<=q;j++) printf("%d %d\n",j,ans[j]);
    }
    for (int i=1;i<=q;i++) printf("%I64d\n",ans[i]);
    return 0;
}

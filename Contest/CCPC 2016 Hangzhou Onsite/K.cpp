#include <bits/stdc++.h>
#define maxn 2000+10
#define maxm maxn*maxn
#define cla(a) memset(a,0,sizeof(a))
#define INF 0x3f3f3f3f
using namespace std;
int vis[maxn],dis[maxn],cur[maxn];
struct Edge{
    int from,to,cap,flow,next;
}edges[maxm*2];
int head[maxn];
int n,m,s,t,b_cnt;
struct Dinic{
    int n,m,s,t;
    inline init(int n,int m,int s,int t)
    {
        b_cnt=-1;
        memset(head,-1,sizeof(head));
        memset(edges,0,sizeof(edges));
        this->n=n;
        this->m=m;
        this->s=s;
        this->t=t;
    }
    inline void addedge(int u,int v,int cap)
    {
     //   cout<<u<<" "<<v<<" "<<cap<<endl;
        edges[++b_cnt].next=head[u];
        edges[b_cnt].to=v;
        edges[b_cnt].from=u;
        edges[b_cnt].cap=cap;
        edges[b_cnt].flow=0;
        head[u]=b_cnt;
        edges[++b_cnt].next=head[v];
        edges[b_cnt].to=u;
        edges[b_cnt].from=v;
        edges[b_cnt].cap=0;
        edges[b_cnt].flow=0;
        head[v]=b_cnt;
    }
    inline bool BFS()
    {
        queue<int> Q;
        cla(vis);
        memset(dis,INF,sizeof(dis));
        Q.push(s);
        vis[s]=1;
        dis[s]=0;
        while (!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            for (int i=head[u];i!=-1;i=edges[i].next)
            {
               int v=edges[i].to;
               Edge &e=edges[i];
               if (e.cap>e.flow && !vis[v])
               {
                   Q.push(v);
                   vis[v]=1;
                   dis[v]=dis[u]+1;
               }
            }
        }
        return vis[t];
    }
    inline int dfs(int u,int a)
    {
        if (u==t || a==0) return a;
        int flow=0,f;
        for (int &i=cur[u];i!=-1;i=edges[i].next)
        {
            Edge &e=edges[i];
            int v=e.to;
            if (dis[v]==dis[u]+1)
                if (f=dfs(e.to,min(a,e.cap-e.flow))>0)
                {
                    e.flow+=f;
                    edges[i^1].flow-=f;
                    flow+=f;
                    a-=f;
                }
                if (a==0)break;
            }
            return flow;
        }
        inline int Maxflow()
        {
            int flow=0;
            while (BFS())
            {

                for (int i=0;i<n+1;i++) cur[i]=head[i];
                flow+=dfs(s,INF);
            }
            return flow;
        }

}D;
bool check(int SS,int NN)
{
    n=2*NN+2;
            s=0;
            t=2*NN+1;
            D.init(n,n*n,s,t);
            for (int i=1;i<=NN;i++)
                {
                    D.addedge(s,i,1);
                    D.addedge(i+NN,t,1);
                }

            for (int i=1;i<=NN;i++)
            {
                int x=SS+i;
                for (int j=1;j<=NN;j++)
                {
                    if (x%j==0){
                            D.addedge(i,j+NN,1);
                            //cout<<x<<" "<<j<<endl;
                          }
                }
            }
    if (D.Maxflow()==NN) return true;
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++) {
        scanf("%d%d",&n,&s);
        if (n>=800&&s>=800) printf("Case #%d: No\n",kase);
        else if (n<800) {
            if (check(s,n)) printf("Case #%d: Yes\n",kase);
            else printf("Case #%d: No\n",kase);
        }
        else {
            int NN=s*2+2;
            int SS=0,TT=s*2+1;
            D.init(NN,NN*NN,SS,TT);
            for (int i=1;i<=s;i++)
            {
                D.addedge(SS,i,1);
                D.addedge(i+s,TT,1);
            }
            for (int i=1;i<=s;i++)
                for (int j=1;j<=s;j++)
            {
                int U=n+i;
                int V=j;
                if (U%V==0)
                        D.addedge(i,j+s,1);
            }
            if (D.Maxflow()==s)
                printf("Case #%d: Yes\n",kase);
            else printf("Case #%d: No\n",kase);
        }
    }
    return 0;
}

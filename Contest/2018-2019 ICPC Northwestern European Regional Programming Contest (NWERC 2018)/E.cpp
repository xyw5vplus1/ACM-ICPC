#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e6+10;
int tot=0,num=0;
int head[maxn],sum[maxn];
std::vector<int> tem;
std::vector<int> E[maxn];
vector<int> ans[4];
int st1[maxn],st2[maxn];
int h1,h2;
struct node
{
	std::vector<int> v;
	int sorted;
}b[maxn];
void newNode()
{
	node e;
	e.v.clear();
	e.sorted=0;
	b[++tot]=e;
}
void dfs_sorted(int u,int k)
{
	for (int i=0;i<(int)E[u].size();i++) {
		int v=E[u][i];
		dfs_sorted(v,k);
	}
	for (int i=0;i<(int)b[u].v.size();i++) tem.push_back(b[u].v[i]);
}
void dfs(int u,int k)
{
	if (b[u].sorted==1) {
		dfs_sorted(u,k);
		sort(tem.begin(),tem.end());
		for (int i=0;i<(int)tem.size();i++) ans[k].pb(tem[i]);
		tem.clear();
	}
	else if (b[u].sorted==-1) {
        dfs_sorted(u,k);
		sort(tem.begin(),tem.end());
		for (int i=(int)tem.size()-1;i>=0;i--) ans[k].pb(tem[i]);
		tem.clear();
	}
	else {
		for (int i=0;i<(int)E[u].size();i++) {
			int v=E[u][i];
			dfs(v,k);
		}
		if ((int)E[u].size()==0) {
			for (int i=0;i<(int)b[u].v.size();i++) ans[k].pb(b[u].v[i]); //printf("\n");
		}
	}
}
void solve(char s[],bool rev,int k)
{
	int len=strlen(s);
	int h1=0,h2=0;
	int pos=0;
	if (rev) {
        while (pos<len) {
            //printf("debug %d\n",pos);
            if (s[pos]=='c') {
                ++h2;
                newNode();
                if (sum[h1]>0) b[tot].sorted=1;
                else if (sum[h1]<0) b[tot].sorted=-1;
                st2[h2]=tot;
                pos+=7;
            }
            else if (s[pos]=='s') {
                ++h1; st1[h1]=++tot;
                if (s[pos+1]=='h') {
                    pos+=8;
                    sum[h1]=-1;
                }
                else {
                    if (sum[h1-1]==0) sum[h1]=1;
                    else sum[h1]=sum[h1-1];
                    pos+=7;
                }
            }
            else if (s[pos]=='['){
                ++h2; ++pos; newNode();
                st2[h2]=tot;
                int x=0;
                while (s[pos]!=']') {
                    if (s[pos]==',') {
                        b[tot].v.push_back(x); x=0;
                    }
                    else {
                        x=x*10+s[pos]-'0';
                    }
                    pos++;
                }
                b[tot].v.push_back(x); x=0;
                if (sum[h1]>0) b[tot].sorted=1;
                else if (sum[h1]<0) b[tot].sorted=-1;
                ++pos;
                E[st2[h2-1]].push_back(st2[h2]); h2--;
            }
            else if (s[pos]==')'){
                if (st1[h1]>st2[h2]) h1--;
                else {
                    E[st2[h2-1]].push_back(st2[h2]);
                    h2--;
                }
                pos++;
            }
            else if (s[pos]==',') pos++;
            //show();
        }
	}
	else {
        while (pos<len) {
            //printf("debug %d\n",pos);
            if (s[pos]=='c') {
                ++h2;
                newNode();
                if (sum[h1]>0) b[tot].sorted=1;
                st2[h2]=tot;
                pos+=7;
            }
            else if (s[pos]=='s') {
                ++h1; st1[h1]=++tot;
                if (sum[h1-1]==0) sum[h1]=1;
                else sum[h1]=sum[h1-1];
                if (s[pos+1]=='h') pos+=8;
                else pos+=7;
            }
            else if (s[pos]=='['){
                ++h2; ++pos; newNode();
                st2[h2]=tot;
                int x=0;
                while (s[pos]!=']') {
                    if (s[pos]==',') {
                        b[tot].v.push_back(x); x=0;
                    }
                    else {
                        x=x*10+s[pos]-'0';
                    }
                    pos++;
                }
                b[tot].v.push_back(x); x=0;
                if (sum[h1]>0) b[tot].sorted=1;
                ++pos;
                E[st2[h2-1]].push_back(st2[h2]); h2--;
            }
            else if (s[pos]==')'){
                if (st1[h1]>st2[h2]) h1--;
                else {
                    E[st2[h2-1]].push_back(st2[h2]);
                    h2--;
                }
                pos++;
            }
            else if (s[pos]==',') pos++;
            //show();
        }
	}
	dfs(st2[1],k);
}
bool check(int k1,int k2)
{
    if (ans[k1].size()!=ans[k2].size()) return false;
    for (int i=0;i<(int)ans[k1].size();i++)
        if (ans[k1][i]!=ans[k2][i]) return false;
    return true;
}
char s1[maxn],s2[maxn];
int main()
{
    scanf("%s",s1);
    scanf("%s",s2);
    solve(s1,false,0); solve(s1,true,1);
    solve(s2,false,2); solve(s2,true,3);
	//for (int i=0;i<(int)ans[0].size();i++) printf("%d ",ans[0][i]); printf("\n");
    //for (int i=0;i<(int)ans[1].size();i++) printf("%d ",ans[1][i]); printf("\n");
    if (check(0,2)&&check(1,3)) printf("equal\n");
    else printf("not equal\n");
    return 0;
}

#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e4+10;
const int maxm=5e5+10;
std::vector<int> v;
multiset<int> s;
int n,k,x;
int cnt[maxn];
bool bo[maxm];
int main()
{
	scanf("%d%d",&n,&k);
	//srand(time(NULL));
	//n=5e5; k=8000;
	for (int i=1;i<=n;i++) {
		scanf("%d",&x);
		//x=rand()%8000+1;
		//printf("x=%d\n",x);
		cnt[x]++;
	}
	sort(cnt+1,cnt+k+1,greater<int>());
	bo[cnt[1]]=true;
	for (int i=1;i<=k;i++)
		for (int j=i+1;j<=k;j++) 
			if (cnt[i]+cnt[j]>=cnt[1]&&cnt[i]+cnt[j]<=cnt[1]+cnt[2]) bo[cnt[i]+cnt[j]]=true;
	for (int i=0;i<=n;i++) 
		if (bo[i]) v.push_back(i);
	//for (int i=0;i<(int)v.size();i++) printf("%d\n",v[i]);
	int len,cnt0;
	ll ans=1LL*n*n;
	for (int i=0;i<(int)v.size();i++) {
		len=v[i];
		s.clear();
		cnt0=0;
		for (int j=1;j<=k;j++) s.insert(cnt[j]);
		multiset<int>::iterator iter;
		//printf("len=%d\n",len);	
		while (s.size()) {
			cnt0++;
			iter=s.end(); 
			iter--;
			int u=(*iter); 
			//printf("min %d\n",u);
			iter=(s.find(u)); s.erase(iter);
			//for (set<int>::iterator iter0=s.begin();iter0!=s.end();iter0++) printf("show0 %d\n",(*iter0));
			if (!s.size()) break;
			iter=s.upper_bound(len-u);
			if (iter==s.begin()) continue;
			iter--; 
			//printf("iter1 %d\n",(*iter1));
			s.erase(iter);
			//for (set<int>::iterator iter0=s.begin();iter0!=s.end();iter0++) printf("show1 %d\n",(*iter0));
		}
		//printf("debug %d %d\n",len,cnt0);
		ans=min(ans,1LL*len*cnt0);
	}
	printf("%I64d\n",ans);
	//printf("Time used=%.2f\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
/*
12 4
1 2 3 1 2 3 4 1 2 1 2 1
*/
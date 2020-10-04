#include <bits/stdc++.h>
using namespace std;
typedef double lf;
typedef complex<lf> Coord;
const int N = 1023, NPOS = -1;
Coord ans[N];
vector<int> g[N];
int n, siz[N];
void dfs(int u, int fa, lf b)
{
	++siz[u];
	for (auto to : g[u])
		if (to != fa)
		{
			ans[to] = ans[u] + polar(1.0, b);
			dfs(to, u, b);
			b += siz[to] * acos(-1) / N;
			siz[u] += siz[to];
		}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, NPOS, 0);
	for (int i = 1; i <= n; ++i)
		printf("%.9f %.9f\n", ans[i].real(), ans[i].imag());
}

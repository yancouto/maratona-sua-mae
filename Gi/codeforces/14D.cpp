#include <bits/stdc++.h>
using namespace std;
#define u first
#define v second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 205;

pii ed[N];
vector<int> g[N];
int n, tmp, tmp2;
int seen[N], seen2[N];

bool check(int u, int v, int i) {
	return (u == ed[i].u && v == ed[i].v) || (u == ed[i].v && v == ed[i].u);
}

int dfs(int v, int e, int d) {
	seen2[v] = tmp2;
	int ans = -1;
	for(int i = 0; i < g[v].size(); i++) 
		if(seen2[g[v][i]] != tmp2 && !check(g[v][i], v, e)) 
			ans = max(ans, dfs(g[v][i], e, d+1));
	if(ans == -1) return d;
	return ans;
}

int dfsl(int v, int e) {
	seen[v] = tmp;
	int ans = -1;
	for(int i = 0; i < g[v].size(); i++)
		if(seen[g[v][i]] != tmp && !check(g[v][i], v, e)) 
			ans = max(ans, dfsl(g[v][i], e));
	if(ans == -1) { tmp2++; return dfs(v, e, 0); }
	return ans;
}

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n-1; i++) {
		scanf("%d %d", &ed[i].u, &ed[i].v);
		g[ed[i].u].pb(ed[i].v);
		g[ed[i].v].pb(ed[i].u);
	}
	int ans = 0;
	for(i = 0; i < n-1; i++) {
		tmp++;
		int d1 = dfsl(ed[i].u, i);
		int d2 = dfsl(ed[i].v, i);
		ans = max(ans, d1 * d2);
	}
	printf("%d\n", ans);
	return 0;
}

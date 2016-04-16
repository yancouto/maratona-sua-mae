#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 212345;

vector<int> adj[N];
int lc[N][20], nv[N];

void dfs(int u, int p, int h) {
	nv[u] = h;
	lc[u][0] = p;
	for(int i = 1; i < 20; i++)
		lc[u][i] = lc[lc[u][i - 1]][i - 1];
	for(int v : adj[u])
		if(v != p)
			dfs(v, u, h + 1);
}

int lca(int a, int b) {
	if(nv[a] < nv[b]) swap(a, b);
	for(int i = 19; i >= 0; i--)
		if(nv[lc[a][i]] >= nv[b])
			a = lc[a][i];
	if(a == b) return a;
	for(int i = 19; i >= 0; i--)
		if(lc[a][i] != lc[b][i])
			a = lc[a][i], b = lc[b][i];
	return lc[a][0];
}

int dist(int a, int b) {
	return nv[a] + nv[b] - 2 * nv[lca(a, b)] + 1;
}

int main() {
	int i, n, a, b, j;
	scanf("%d", &n);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 1, 0);
	ll tot = 0;
	for(i = 1; i <= n; i++)
		for(j = i+i; j <= n; j += i)
			tot += dist(i, j);
	printf("%lld\n", tot);

}

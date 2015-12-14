#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

const int MAX = 50009;
vector<int> adj[MAX];
int pai[18][MAX];
int nv[MAX];
int v[MAX];

void dfs(int u, int p, int l) {
	pai[0][u] = p;
	nv[u] = l;
	for(int i = 1; i < 18; i++)
		pai[i][u] = pai[i-1][pai[i-1][u]];
	for(int v : adj[u])
		if(v != p)
			dfs(v, u, l + 1);
}

int dfs2(int u, int p) {
	for(int w : adj[u])
		if(w != p)
			v[u] += dfs2(w, u);
	return v[u];
}

int lca(int a, int b) {
	if(nv[a] < nv[b]) swap(a, b);
	for(int i = 17; i >= 0; i--)
		if(nv[pai[i][a]] >= nv[b])
			a = pai[i][a];
	if(a == b) return a;
	for(int i = 17; i >= 0; i--)
		if(pai[i][a] != pai[i][b])
			a = pai[i][a], b = pai[i][b];
	return pai[0][a];
}

int main() {
	int i, n, q, a, b, c;
	for_tests(t, tt) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) adj[i].clear(), v[i] = 0;
		for(i = 0; i < n - 1; i++) {
			scanf("%d %d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(0, 0, 0);
		scanf("%d", &q);
		for(i = 0; i < q; i++) {
			scanf("%d %d %d", &a, &b, &c);
			int x = lca(a, b);
			v[a] += c; v[b] += c;
			v[x] -= c;
			if(x) v[pai[0][x]] -= c;
		}
		dfs2(0, 0);
		printf("Case #%d:\n", tt);
		for(i = 0; i < n; i++)
			printf("%d\n", v[i]);
	}
}

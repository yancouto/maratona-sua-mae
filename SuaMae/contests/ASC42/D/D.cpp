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
const int N = 112345;

vector<int> adj[N];
int d[N], f[N], h[N], lc[N][20], tempo;

int dfs(int u, int p, int h) {
	d[u] = tempo++;
	::h[u] = h;
	lc[u][0] = p;
	for(int i = 1; i < 20; i++)
		lc[u][i] = lc[lc[u][i - 1]][i - 1];
	for(int v : adj[u])
		if(v != p)
			dfs(v, u, h + 1);
	f[u] = tempo++;
}

int lca(int u, int v) {
	if(h[u] < h[v]) swap(u, v);
	for(int i = 0; (1 << i) <= (h[u] - h[v]); i++)
		if((1 << i) & (h[u] - h[v]))
			u = lc[u][i];
	if(u == v) return u;
	for(int i = 19; i >= 0; i--)
		if(lc[u][i] != lc[v][i])
			u = lc[u][i], v = lc[v][i];
	return lc[u][0];
}

int to_root(int u, int r) {
	if(d[r] >= d[u] && f[r] <= f[u]) return u;
	for(int i = 19; i >= 0; i--)
		if(!(d[r] >= d[lc[u][i]] && f[r] <= f[lc[u][i]]))
			u = lc[u][i];
	return lc[u][0];
}

int main() {
	// DONT FORGET FREOPEN
	freopen("dynamic.in", "r", stdin);
	freopen("dynamic.out", "w", stdout);
	int i, a, b, n; char op;
	while(scanf("%d", &n) && n) {
		for(i = 0; i < n; i++) adj[i].clear();
		for(i = 0; i < n - 1; i++) {
			scanf("%d %d", &a, &b); a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		tempo = 0;
		dfs(0, 0, 0);
		int r = 0;
		for_tests(t, tt) {
			scanf(" %c %d", &op, &a); a--;
			if(op == '?') {
				scanf("%d", &b); b--;
				int c = lca(a, b);
				if(d[r] > d[c] && f[r] < f[c]) {
					a = to_root(a, r);
					b = to_root(b, r);
					if(h[a] > h[b]) printf("%d\n", a + 1);
					else printf("%d\n", b + 1);
				} else printf("%d\n", c + 1);
			} else if(op == '!') r = a;
		}
	}
}

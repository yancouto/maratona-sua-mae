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
const int MAX = 10005;

vector<int> g[MAX];
int seen[MAX], id[MAX], sz[MAX];

int get(int v) {
	if(v == id[v]) return v;
	return id[v] = get(id[v]);
}

void join(int u, int v) {
	u = get(u); v = get(v);
	if(u == v) return;
	if(sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v];
	id[v] = u;
}

int path[MAX];
void dfs(int v, int pai) {
	seen[v] = 1;
	for(int i = 0; i < g[v].size(); i++) {
		if(seen[g[v][i]]) { path[g[v][i]] = g[v][i] != pai; continue; }
		join(g[v][i], v);
		dfs(g[v][i], v);
	}
}

int main() {
	int r, c, q, u, v;
	while(42) {
		memset(seen, 0, sizeof seen);
		memset(path, 0, sizeof path);
		scanf("%d %d %d", &r, &c, &q);
		if(r+c+q == 0) return 0;
		for(int i = 1; i <= r; i++) g[i].clear();
		for(int i = 0; i < c; i++) {
			scanf("%d %d", &u, &v);
			g[u].pb(v); g[v].pb(u);
		}
		for(int i = 1; i <= r; i++)
			sz[i] = 1, id[i] = i;
		for(int i = 1; i <= r; i++)
			if(!seen[i]) dfs(i, i);
		for(int i = 0; i < q; i++) {
			scanf("%d %d", &u, &v);
			if(get(u) == get(v) && !path[v]) puts("Y");
			else puts("N");
		}
		puts("-");
	}
	return 0;	
}

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
vector<pii> adj[100009];

void dfs(int u, int p) {
	if(p != -1) {
		int i;
		for(i = 0; adj[u][i].fst != p; i++);
		swap(adj[u][i], adj[u].back());
		adj[u].pop_back();
	}
	for(pii e : adj[u])
		dfs(e.fst, u);
}

int memo[100009][2];
int solve(int u, bool must) {
	int &r = memo[u][must];
	if(r != -1) return r;
	if(adj[u].empty()) return r = 0;
	r = distr(u, adj[u].size(), must);
	return r;
}

int memo2[100009][2];
int distr(int u, int m, bool must) {
	int &r = memo[adj[u][m-1].fst][must];
	if(r != -1) return r;
	if(m == 1) {
		r = max(0, adj[u][0].snd + solve(adj[u][0].fst, true));
		if(!must) r = max(r, solve(adj[u][0].fst, false));
		return r;
	}

}

int x[200009], y[200009];
int main() {
	int t = 0;
	while(true) {
		t++;
		scanf("%d", &n);
		if(!n) return 0;
		int sz = 0;
		for(i = 0; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			if(x[a] < t) { x[a] = t; y[a] = sz++; adj[y[a]].clear(); }
			if(x[b] < t) { x[b] = t; y[b] = sz++; adj[y[b]].clear(); }
			adj[y[a]].pb(pii(y[b], c));
			adj[y[b]].pb(pii(y[a], c));
		}
		dfs(0, -1);
		memset(memo, -1, sizeof memo);
		printf("%d\n", solve(0, -1, false));
	}
}

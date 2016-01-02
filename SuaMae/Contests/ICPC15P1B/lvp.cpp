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

const int N = 500009;
int nx[N], best[N], seen[N], d0[N], dn[N];
vector<int> adj[N];
void dfs(int u, int d) {
	if(seen[u] == 2) return;
	seen[u] = 2;
	best[u] = dn[u] = d;
	for(int v : adj[u]) {
		dfs(v, d + 1);
		if(d0[v] == INT_MAX)
			best[u] = max(best[u], best[v]);
	}
}


int main() {
	int i, n;
	for_tests(t, tt) {
		scanf("%d", &n);
		for(i = 0; i <= n; i++) {
			adj[i].clear();
			d0[i] = dn[i] = INT_MAX;
			seen[i] = 0;
		}
		for(i = 0; i < n; i++) {
			scanf("%d", &nx[i]);
			if(nx[i] == -1) nx[i] = n;
			adj[nx[i]].pb(i);
		}
		int v = 0, d = 0;
		while(!seen[v]) {
			seen[v] = 1;
			d0[v] = d++;
			if(v == n) break;
			v = nx[v];
		}
		dfs(n, 0);
		if(d0[n] == INT_MAX)
			printf("%d\n", d + best[n]);
		else {
			v = 0;
			int res = 0;
			while(v != n) {
				v = nx[v];
				res = max(res, d0[v] + best[v]);
			}
			printf("%d\n", res);
		}
	}
}

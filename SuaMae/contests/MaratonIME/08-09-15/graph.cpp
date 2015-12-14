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

int seen[2509], tempo;
vector<int> adj[2509];
int dfs(int u) {
	if(seen[u] == tempo) return 0;
	seen[u] = tempo;
	int x = 1;
	for(int v : adj[u])
		x += dfs(v);
	return x;
}

int main() {
	int n, m, i, a, b;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) adj[i].clear();
		for(i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			adj[--a].pb(--b);
		}
		int tot = 0;
		memset(seen, 0, sizeof seen);
		tempo = 0;
		for(i = 0; i < n; i++) {
			tempo++;
			tot += dfs(i) - 1;
		}
		printf("%d\n", tot);
	}
}

// TLE, fazer bottom up (e entender direito)
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
int n, k;
vector<int> adj[150009];
int root;
int w[150009];

int d(int, int);

int memo[150009][302];
int c(int v, int i, int j) {
	 if(j == 0) return 0;
	 if(i == 1) return d(adj[v][0], j);
	 if(memo[adj[v][i-1]][j] != -1)
		 return memo[adj[v][i-1]][j];
	 int best = -1500000000;
	 for(int kk = 0; kk <= j; kk++)
		 best = max(best, c(v, i - 1, j - kk) + d(adj[v][i-1], kk));
	return memo[adj[v][i-1]][j] = best;
}

int d(int v, int j) {
	 if(j == 0) return 0;
	 if(adj[v].size() == 0) return (j > 1)? -1500000000 : w[v];
	 if(j == 1) return max(w[v], c(v, adj[v].size(), 1));
	 return c(v, adj[v].size(), j);
}

/* WRONG
void dfs(int u, int *best) {
	 int bs[303], bs2[303];
	 for(int i = 0; i <= k; i++) {  bs[i] = 0; bs2[i] = best[i]; }
	 if(adj[u].empty()) {
		  best[1] = w[u];
		  return;
	 }
	 for(int v : adj[u]) {
		  dfs(v, bs);
	 }
	 best[0] = 0;
	 bs2[1] = max(w[u], bs[1]);
	 for(int i = 1; i <= k; i++) {
		 for(int kk = 0; kk <= i; kk++)
			 best[i] = max(bs2[i], bs2[i-kk] + bs[kk]);
	 }
}*/

int main() {
	int i, j, x;
	while(scanf("%d %d", &n, &k) != EOF) {
		for(i = 0; i < n; i++) adj[i].clear();
		for(i = 0; i < n; i++) {
			scanf("%d %d", &x, &w[i]);
			if(x == 0) { root = i; continue; }
			adj[--x].pb(i);
		}
		int bs[303];
		memset(memo, -1, sizeof memo);
		//dfs(root, bs);
		int r = d(root, k);
		if(r < 0) puts("impossible");
		else printf("%d\n", r);
	}
	return 0;	 
}

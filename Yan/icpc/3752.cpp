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

map<pair<int, pii>, int> s;
int c(int v, int i, int j) {
	 if(j == 0) return 0;
	 if(i == 1) return d(adj[v][0], j);
	 if(s.count(make_pair(v, pii(i, j))))
		 return s[make_pair(v, pii(i, j))];
	 int best = -1500000000;
	 for(int kk = 0; kk <= j; kk++)
		 best = max(best, c(v, i - 1, j - kk) + d(adj[v][i-1], kk));
	return s[make_pair(v, pii(i, j))] = best;
}

int d(int v, int j) {
	 if(j == 0) return 0;
	 if(adj[v].size() == 0) return (j > 1)? -1500000000 : w[v];
	 if(j == 1) return max(w[v], c(v, adj[v].size(), 1));
	 return c(v, adj[v].size(), j);
}

int main() {
	int i, j, x;
	int be[303];
	while(scanf("%d %d", &n, &k) != EOF) {
		s.clear();
		for(i = 0; i < n; i++) adj[i].clear();
		for(i = 0; i < n; i++) {
			scanf("%d %d", &x, &w[i]);
			if(x == 0) { root = i; continue; }
			adj[--x].pb(i);
		}
		for(i = 0; i <= k; i++) be[i] = 0;
		int r = d(root, k);
		if(r < 0) puts("impossible");
		else printf("%d\n", r);
	}
	return 0;	 
}

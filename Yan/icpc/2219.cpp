// WAAA
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
#ifndef ONLINE_JUDGE
#	define debug(args...) {fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");}
#else
#	define debug(args...) {}
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n, c;
vector<pii> adj[103];
int deg[103], br[103];
int c1[503], c2[503];
int seen[103];
void dfs(int u) {
	if(seen[u]) return;
	seen[u] = 1;
	for(pii v : adj[u])
		dfs(v.fst);
}

int main() {
	int k, a, i, j;
	while(true) {
		scanf("%d %d", &n, &c);
		if(!n) return 0;
		for(i = 0; i < c; i++) {
			adj[i].clear();
			seen[i] = 0;
		}
		memset(c1, -1, sizeof c1);
		memset(c2, -1, sizeof c2);
		for(i = 0; i < c; i++) {
			scanf("%d", &k);
			br[i] = k;
			for(j = 0; j < k; j++) {
				scanf("%d", &a);
				if(c1[a] != -1) c2[a] = i;
				else c1[a] = i;
			}
		}
		for(i = 0; i < n; i++) {
			if(c2[i] == -1) c2[i] = c1[i];
			adj[c2[i]].pb(pii(c1[i], i));
			adj[c1[i]].pb(pii(c2[i], i));
		}
		for(i = 0; i < c; i++)
			if(br[i]) {
				dfs(i);
				break;
			}
		for(i = 0; i < c; i++)
			if(!seen[i] && br[i])
				break;
		if(i < c) { puts("-1"); continue; }
		vector<int> imp;
		for(i = 0; i < c; i++)
			if(adj[i].size() & 1)
				imp.pb(i);
		if(imp.size() > 2) puts("-1");
		else if(imp.empty()) puts("0");
		else {
			int mn = INT_MAX;
			for(int u : imp)
				for(pii v : adj[u])
					mn = min(v.snd, mn);
			printf("%d\n", mn);
		}
	}
}

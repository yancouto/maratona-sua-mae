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
int m, n, s;
vector<pii> adj[103];
int seen[103], comp[103], cn;
bool dfs(int u, int p) {
	if(seen[u]) return true;
	seen[u] = 1; comp[u] = cn;
	for(pii e : adj[u])
		if(e.fst != p)
			if(dfs(e.fst, u))
				return true;
	return false;
}

int mv, md;
bool dfs2(int u, int p, int dist) {
	if(dist > md) { mv = u; md = dist; }
	for(pii e : adj[u])
		if(e.fst != p)
			dfs2(e.fst, u, dist + e.snd);
}

void yes() {
	puts("YES");
	exit(0);
}
int adjM[103][103];
int vis[103];
int main() {
	int i, j, p, q, r;
	scanf("%d %d %d", &m, &n, &s);
	bool fudeu = false;
	for(i = 0; i < n; i++) {
		scanf("%d %d %d", &p, &q, &r);
		adj[--p].pb(pii(--q, r));
		adj[q].pb(pii(p, r));
		if(p == q) fudeu = true;
		if(adjM[p][q]) fudeu = true;
		adjM[p][q] = adjM[q][p] = 1;
	}
	if(fudeu) yes();
	for(i = 0; i < m; i++)
		if(!seen[i]) {
			cn++;
			if(dfs(i, i)) yes();
		}
	for(i = 0; i < m; i++)
		if(!vis[comp[i]]) {
			vis[comp[i]] = 1;
			mv = i; md = 0;
			dfs2(i, i, 0);
			md = 0;
			dfs2(mv, mv, 0);
			if(md >= s) yes();
		}
	puts("NO");
}

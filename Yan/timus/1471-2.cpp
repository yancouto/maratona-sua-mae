// Incompleto
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

void dfs(int u, int p, int c) {
	pai[u] = p;
	ac[u] = c;
	d[u] = ++tempo;
	I[u] = d[u];
	for(pii e : adj[u])
		if(e.fst != p) {
			dfs(e.fst, u, c + e.snd);
			if(r1[d[e.fst]] > r1[I[u]])
				I[u] = d[e.fst];
		}
}

void dfs2(int u, int p) {
	A[u] = A[pai[u]] | (1 << r1[I[u]]);
	if(!u || I[pai[u]] != I[u]) L[u] = u;
	else L[u] = L[pai[u]];
	for(pii e : adj[u])
		if(e.fst != p) {
			dfs2(e.fst, u);
		}
}

int lca_bin(int a, int b) {
	if(r1[a] < r1[b]) swap(a, b);
	if((a >> r1[a]) == (b >> r1[a])) return a;
	int c = a ^ b;
	return ((a >> l1[c]) << l1[c]) | (1 << (l1[c] - 1));
}

int main() {
	for(i = 1; i <= 500000; i++) {
		if(i & 1) r1[i] = 1;
		else r1[i] = 1 + ri[i>>1];
		l1[i] = 1 + l1[i>>1];
	}
	scanf("%d", &n);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &c); a--; b--;
		adj[a].pb(pii(b, c));
		adj[b].pb(pii(a, c));
	}
	dfs(0, 0, 0);
}

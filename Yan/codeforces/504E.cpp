#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif
const ll b = 263;
const int N = 312345;

int lc[N][20], nv[N];
vector<int> adj[N];
ll hd[N], hu[N], pot[N], inv[N];
char c[N];

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}
int g[N];

inline int anc(int u, int d) {
	//printf("anc(%d, %d)\n", u, d);
	while(d) {
		u = lc[u][g[d]];
		d ^= (1 << g[d]);
	}
	return u;
}

int lca(int u, int v) {
	if(nv[u] > nv[v]) swap(u, v);
	v = anc(v, nv[v] - nv[u]);
	if(u == v) return u;
	for(int i = 19; i >= 0; i--)
		if(lc[v][i] != lc[u][i])
			u = lc[u][i], v = lc[v][i];
	return lc[u][0];
}

void dfs(int u, int p, ll hs, ll hr, int nv) {
	if(u) adj[u].erase(search_n(adj[u].begin(), adj[u].end(), 1, p));
	::nv[u] = nv;
	lc[u][0] = p;
	for(int i = 1; i < 20; i++)
		lc[u][i] = lc[lc[u][i - 1]][i - 1];
	hu[u] = hs = mod(hs * b + c[u]);
	hd[u] = hr = mod(hr + ll(c[u]) * pot[nv]);
	//debug("dfs(%d, %d): %lld %lld\n", u, p, hs, hr);
	for(int v : adj[u])
		dfs(v, u, hs, hr, nv + 1);
}

inline ll get_up(int a, int b) {
	//printf("get_up(%d, %d)\n", a, b);
	ll h = mod(hd[a] - hd[b] + modn);
	return mod(h * inv[nv[b]+1]);
}

inline ll get_down(int a, int b) {
	//printf("get_down(%d, %d)\n", a, b);
	return mod(hu[a] - mod(hu[b] * pot[nv[a] - nv[b]]) + modn);
}

ll get_hash(int a, int b, int ab, int m) {
	int pa = nv[a] - nv[ab] + 1, pb = nv[b] - nv[ab];
	ll f, s; int sz;
	if(m <= pa) {
		f = get_up(a, anc(a, m)); s = 0;
		sz = 0;
	} else {
		f = get_up(a, lc[ab][0]);
		sz = m - pa;
		s = get_down(anc(b, pa + pb - m), ab);
	}
	//debug("(%d, %d, %d) %lld %lld = %lld\n", a, ab, b, f, s, mod(f * pot[sz] + s));
	return mod(f * pot[sz] + s);
}

int main() {
	srand(time(NULL));
	int i, j, n, a, b, c, d, q;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf(" %c", &::c[i]);
	for(i = 1; i <= n; i++)
		if(i & 1) g[i] = 0;
		else g[i] = g[i >> 1] + 1;
	int o = (rand() % n) + 1;
	adj[0].pb(o); adj[o].pb(0);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	pot[0] = 1;
	for(i = 1; i < N; i++) pot[i] = mod(pot[i - 1] * ::b);
	for(i = 0; i < N; i++) inv[i] = fexp(pot[i], modn - 2);
	dfs(0, 0, 0, 0, 0);
	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(::c[a] != ::c[c]) { puts("0"); continue; }
		int ab = lca(a, b), cd = lca(c, d);
		int l = 1, r = min(nv[a] + nv[b] - 2*nv[ab] + 1, nv[c] + nv[d] - 2*nv[cd] + 1);
		while(l < r) {
			int m = (l + r + 1) / 2;
			ll hab = get_hash(a, b, ab, m), hcd = get_hash(c, d, cd, m);
			if(hab == hcd) l = m;
			else r = m - 1;
		}
		printf("%d\n", l);
	}
}

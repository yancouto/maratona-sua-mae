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
const int N = 300009;
inline int he(int u) { return 300003 + u; }
int root = 0, tn = 0;
int pr[N+100000], nx[N+100000];
int L[N], R[N], sz[N], lazy[N], par[N], mn[N], h[N], y[N];

int acc(int u) {
	if(!u) return 0;
	h[u] += lazy[u];
	lazy[L[u]] += lazy[u];
	lazy[R[u]] += lazy[u];
	lazy[u] = 0;
	return u;
}

void calc(int u) {
	mn[u] = u;
	if(h[acc(L[u])] < h[u]) mn[u] = mn[L[u]];
	if(h[acc(R[u])] < h[mn[u]]) mn[u] = mn[R[u]];
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	par[L[u]] = par[R[u]] = u; par[u] = 0;
}

int up(int u) {
	int tot = 0;
	while(u && par[u]) {
		if(R[par[u]] == u) tot += 1 + sz[L[par[u]]];
		u = par[u];
	}
	return tot;
}

void split(int u, int s, int &l, int &r) {
	if(!acc(u)) return (void) (l = r = 0);
	if(s > sz[L[u]]) split(R[u], s - sz[L[u]] - 1, l, r), R[u] = l, l = u;
	else split(L[u], s, l, r), L[u] = r, r = u;
	calc(u);
}

int merge(int l, int r) {
	if(!acc(l) || !acc(r)) return max(l, r);
	int u;
	if(y[l] > y[r]) R[l] = merge(R[l], r), u = l;
	else L[r] = merge(l, L[r]), u = r;
	calc(u);
	return u;
}

vector<int> adj[N];

void dfs(int u, int hh) {
	h[tn + 1] = hh; mn[tn + 1] = u;
	root = merge(root, ++tn);
	nx[he(u)] = pr[he(u)] = tn;
	for(int v : adj[u]) {
		dfs(v, hh + 1); h[tn + 1] = hh; mn[tn + 1] = u;
		root = merge(root, ++tn);
		pr[tn] = pr[he(u)]; nx[tn] = he(u);
		nx[pr[tn]] = tn; pr[he(u)] = tn;
	}
}

int main() {
	int i, u, v, x, n; char q;
	for(i = 0; i < N; i++) y[i] = i, sz[N] = 1;
	sz[0] = 0; h[0] = INT_MAX;
	random_shuffle(y, y + N);
	scanf("%d", &n);
	for(i = 1; i < n; i++) {
		scanf("%d", &x);
		adj[x - 1].pb(i);
	}
	dfs(0, 0);
	for_tests(qn, qi) {
		scanf(" %c %d %d", &q, &u, &v); u--; v--;
		if(q == 'Q') {
			int l = up(nx[he(u)]), r = up(pr[he(v)]), t1, t2, t3;
			if(l > r) swap(l, r);
			split(root, l, t1, t2);
			split(t2, r - l, t2, t3);
			printf("%d\n", mn[t2] + 1);
			root = merge(merge(t1, t2), t3);
		} else {
			int l = up(nx[he(u)]), r = up(pr[he(u)]), t1, t2, t3, t4;
			split(root, l, t1, t2);
			split(t2, r - l, t2, t3);
			split(t3, 1, t3, t4);
			nx[pr[t3]] = nx[t3];
			pr[nx[t3]] = pr[t3];
			lazy[t2] += h[pr[he(v)]] - h[t2] + 1;
			root = merge(t1, t4);
			int o = up(pr[he(v)]);
			split(root, o + 1, t1, t3);
			h[tn + 1] = h[pr[he(v)]]; mn[tn + 1] = v;
			root = merge(merge(t1, t2), merge(++tn, t3));
			pr[tn] = pr[he(v)]; nx[tn] = he(v);
			pr[he(v)] = tn; nx[pr[tn]] = tn;
		}
	}
}

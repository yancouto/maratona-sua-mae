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

inline double rnd() { return double(rand()) / RAND_MAX; }
const int N = 10010009;
int L[N], R[N], sz[N]; ll val[N], sum[N], lz[N];

int root = 1, tn = 1;
int cp(int u, int v) {
	sz[u] = sz[v];
	L[u] = L[v];
	R[u] = R[v];
	val[u] = val[v];
	sum[u] = sum[v];
	lz[u] = lz[v];
	return u;
}

void unlaze(int u) {
	if(lz[u]) {
		val[u] += lz[u];
		sum[u] += ll(sz[u]) * lz[u];
		if(L[u]) L[u] = cp(++tn, L[u]); lz[L[u]] += lz[u];
		if(R[u]) R[u] = cp(++tn, R[u]); lz[R[u]] += lz[u];
		lz[u] = 0;
	}
}

int calc(int u) {
	//printf("calc(%d)\n", u);
	//unlaze(u);
	//val[u] += lz[u];
	//if(L[u] && (lz[u] || lz[L[u]])) lz[L[u] = cp(++tn, L[u])] += lz[u], unlaze(L[u]);
	//if(R[u] && (lz[u] || lz[R[u]])) lz[R[u] = cp(++tn, R[u])] += lz[u], unlaze(R[u]);
	//lz[u] = 0;
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
	//sum[u] = sum[L[u]] + (ll(sz[L[u]]) * lz[L[u]]) + val[u] + sum[R[u]] + (ll(sz[R[u]]) * lz[R[u]]);
	//printf("calc[%d]: sz %d val %lld sum %lld\n", u, sz[u], val[u], sum[u]);
	return u;
}

void split(int u, int s, int &l, int &r) {
	if(!u) return (void) (l = r = 0);
	int v = ++tn; cp(v, u);
	//unlaze(v);
	if(sz[L[v]] < s) split(R[v], s - sz[L[v]] - 1, l, r), R[v] = l, l = v;
	else split(L[v], s, l, r), L[v] = r, r = v;
	calc(v);
}

int merge(int l, int r) {
	if(!l || !r) return max(l, r);
	//if(lz[l]) unlaze(l = cp(++tn, l));
	//if(lz[r]) unlaze(r = cp(++tn, r));
	int u = ++tn;
	if(rnd() * (sz[l] + sz[r]) <= sz[l]) cp(u, l), R[u] = merge(R[u], r);
	else cp(u, r), L[u] = merge(l, L[u]);
	return calc(u);
}

ll get_sum(int u, int s, ll l) {
	if(!u) return 0;
	l += lz[u];
	if(sz[L[u]] >= s) return get_sum(L[u], s, l);
	return sum[L[u]] + (ll(sz[L[u]]) * (l + lz[l])) + val[u] + l + get_sum(R[u], s - sz[L[u]] - 1, l);
}

int add(int u, int s, ll v) {
	if(!u) return 0;
	u = cp(++tn, u);
	if(sz[L[u]] >= s) L[u] = add(L[u], s, v);
	else { lz[u] += v; R[u] = add(R[u], s - sz[L[u]] - 1, v); if(R[u]) lz[R[u]] -= v; }
	return calc(u);
}

int main() {
	int i, l, r, v, op;
	srand(time(NULL));
	for_tests(t, tt) {
		root = 1;
		sz[root] = 1; val[root] = sum[root] = L[root] = R[root] = lz[root] = 0;
		for(i = 0; i < 17; i++)
			root = merge(root, root);
		scanf("%*d");
		for_tests(qn, qc) {
			scanf("%d %d %d", &op, &l, &r); l--; r--;
			if(op) {
				printf("%lld\n", get_sum(root, r + 1, 0) - get_sum(root, l, 0));
			} else {
				scanf("%d", &v);
				root = add(root, r + 1, v);
				root = add(root, l, -v);
			}
			if(tn > 10000000) return 0;
		}
	}
}

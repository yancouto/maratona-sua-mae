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
inline int L(int i) { return i << 1; }
inline int R(int i) { return L(i) + 1; }
const int N = 400009;

int tr[N << 2], lazy[N << 2];
int vv[N], d[N], f[N], inv[N], seen[N], tempo;
vector<int> adj[N];


void unlaze(int i, int l, int r) {
	if(lazy[i] == -1) return;
	tr[i] = (r - l + 1) * lazy[i];
	if(l != r) lazy[L(i)] = lazy[R(i)] = lazy[i];
	lazy[i] = -1;
}

void upd(int i, int l, int r, int ql, int qr, int x) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		lazy[i] = x;
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	upd(L(i), l, m, ql, qr, x);
	upd(R(i), m + 1, r, ql, qr, x);
	tr[i] = tr[L(i)] + tr[R(i)];
}

int get(int i, int l, int r, int ql, int qr) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return 0;
	if(l >= ql && r <= qr) return tr[i];
	int m = (l + r) / 2;
	return get(L(i), l, m, ql, qr) + get(R(i), m + 1, r, ql, qr);
}

void dfs(int u) {
	if(seen[u]) return;
	seen[u] = true;
	d[u] = tempo++;
	inv[d[u]] = u;
	for(int v : adj[u])
		dfs(v);
	f[u] = tempo++;
}

inline void change(set<int> &a, set<int> &b, int v) {
	a.erase(v);
	b.insert(v);
}

void deb() {
	for(int i = 0; i < tempo; i++)
		printf("%d ", get(1, 0, tempo-1, i, i));
	putchar('\n');
}

void solve(int *v, set<int> &ord, set<int> &desc) {
	if(ord.empty()) return;
	int mn = *ord.begin();

	ord.erase(mn);
	desc.erase(d[mn]);
	upd(1, 0, tempo-1, d[mn], d[mn], 0);

	int pos = get(1, 0, tempo-1, d[mn], f[mn]);	
	v[pos] = mn;

	auto left = desc.lower_bound(d[mn]), right = desc.upper_bound(f[mn]);
	set<int> sord, sdesc;

	if(pos <= ord.size() / 2) {
		upd(1, 0, tempo-1, d[mn], f[mn], 0);
		for(; left != right;) {
			change(ord, sord, inv[*left]);
			sdesc.insert(*left);
			left = desc.erase(left);
		}
		solve(v + pos + 1, ord, desc);
		ord.clear(); desc.clear();
		upd(1, 0, tempo-1, 0, tempo-1, 0);
		for(int d : sdesc)
			upd(1, 0, tempo-1, d, d, 1);
		solve(v, sord, sdesc);
	} else {
		if(d[mn]) upd(1, 0, tempo-1, 0, d[mn]-1, 0);
		if(f[mn] != tempo - 1) upd(1, 0, tempo-1, f[mn] + 1, tempo-1, 0);
		for(auto it = desc.begin(); it != left;) {
			change(ord, sord, inv[*it]);
			sdesc.insert(*it);
			it = desc.erase(it);
		}
		for(; right != desc.end();) {
			change(ord, sord, inv[*right]);
			sdesc.insert(*right);
			right = desc.erase(right);
		}

		solve(v, ord, desc);
		ord.clear(); desc.clear();
		upd(1, 0, tempo-1, 0, tempo-1, 0);
		for(int d : sdesc) upd(1, 0, tempo-1, d, d, 1);
		solve(v + pos + 1, sord, sdesc);
	}
}

int main() {
	int i, n, m, a, b;
	scanf("%d %d", &n, &m);
	set<pii> s;
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		if(s.count(pii(a, b))) continue;
		s.insert(pii(a, b));
		adj[b].pb(a);
	}
	set<int> ord, desc;
	for(i = 0; i < n; i++) dfs(i);
	for(i = 0; i < n; i++) {
		ord.insert(i);
		desc.insert(d[i]);
		upd(1, 0, tempo-1, d[i], d[i], 1);
	}
	solve(vv, ord, desc);
	for(i = 0; i < n; i++)
		printf("%d ", vv[i] + 1);
	putchar('\n');
}

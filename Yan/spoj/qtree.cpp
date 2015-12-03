// RE??
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

const int N = 10009;
vector<pii> adj[N];
int val[N], c[N], nv[N], pai[N][15], so[N];
int inv[N], cost[N];
int dfs(int u, int p, int c, int nv) {
	int &f = so[u];
	::nv[u] = nv;
	pai[u][0] = p;
	for(int i = 1; i < 15; i++)
		pai[u][i] = pai[pai[u][i-1]][i-1];
	if(p != u)  {
		for(f = 0; adj[u][f].fst != p; f++);
		adj[u].erase(adj[u].begin() + f);
		val[u] = c; inv[c] = u;
	}
	f = 1;
	cost[u] = ::c[c];
	for(pii v : adj[u])
		f += dfs(v.fst, u, v.snd, nv + 1);
	return f;
}

int lca(int u, int v) {
	if(nv[u] > nv[v]) swap(u, v);
	for(int i = 14; i >= 0; i--)
		if(nv[pai[v][i]] >= nv[u])
			v = pai[v][i];
	if(u == v) return u;
	for(int i = 14; i >= 0; i--)
		if(pai[u][i] != pai[v][i])
			u = pai[u][i], v = pai[v][i];
	return pai[u][0];
}

int cur, ci[N], cp[N], cs[N], pr[N], th[N], tr[N << 4], tc, L[N << 4], R[N << 4], ch[N];
void build(int i, int l, int r) {
	if(l == r) { tr[i] = (!!l) * pr[l]; return; }
	int m = (l + r) / 2;
	build(L[i] = tc++, l, m);
	build(R[i] = tc++, m + 1, r);
	tr[i] = max(tr[L[i]], tr[R[i]]);
}

int get(int i, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return INT_MIN;
	if(l >= ql && r <= qr) return tr[i];
	int m = (l + r) / 2;
	return max(get(L[i], l, m, ql, qr), get(R[i], m + 1, r, ql, qr));
}

void set_tree(int i, int l, int r, int x, int val) {
	if(l == r) { tr[i] = val; return; }
	int m = (l + r) / 2;
	if(x <= m) set_tree(L[i], l, m, x, val);
	else set_tree(R[i], m + 1, r, x, val);
	tr[i] = max(tr[L[i]], tr[R[i]]);
}

void hld(int u) {
	pr[cs[cur]] = cost[u];
	cp[u] = cs[cur];
	if(!cs[cur]) ch[cur] = u;
	cs[cur]++;
	ci[u] = cur;
	if(adj[u].empty()) return build(th[cur] = tc++, 0, cs[cur] - 1);
	int bi = adj[u].front().fst;
	for(int i = 1; i < adj[u].size(); i++)
		if(so[adj[u][i].fst] > so[bi])
			bi = adj[u][i].fst;
	hld(bi);
	for(pii v : adj[u])
		if(v.fst != bi) {
			cur++;
			hld(v.fst);
		}
}

int mx(int a, int b) {
	int x = INT_MIN;
	while(a != b) {
		if(cp[a]) {
			int d = 0;
			if(ci[a] == ci[b]) d = cp[b] + 1;
			x = max(x, get(th[ci[a]], 0, cs[ci[a]] - 1, d, cp[a]));
			a = ch[ci[a]];
			if(ci[a] == ci[b]) a = b;
		} else {
			x = max(x, cost[a]);
			a = pai[a][0];
		}
	}
	return x;
}

int main() {
	int i, n, a, b; char c;
	for_tests(t, tt) {
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			adj[i].clear();
		for(i = 0; i < n - 1; i++) {
			scanf("%d %d %d", &a, &b, &::c[i]); a--; b--;
			adj[a].pb(pii(b, i));
			adj[b].pb(pii(a, i));
		}
		dfs(0, 0, 0, 0);
		memset(cs, 0, sizeof cs);
		cur = tc = 0;
		hld(0);
		while(scanf(" %c%*s %d %d", &c, &a, &b) == 3) {
			if(c == 'C') {
				int u = inv[--a];
				if(cp[u]) set_tree(th[ci[u]], 0, cs[ci[u]] - 1, cp[u], b);
				else cost[u] = b;
			} else {
				a--; b--;
				int l = lca(a, b);
				printf("%d\n", max(mx(a, l), mx(b, l)));
			}
		}
	}
}

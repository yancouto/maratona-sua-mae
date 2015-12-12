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
const int N = 11000;
vector<pii> adj[N];
int nv[N], pai[N][15], vs[N], c[N];
int vp[N], vc[N], ev[N], ct[N], cs[N], ch[N], cost[N], cur, pv[N];
int tr[N << 2], L[N << 2], R[N << 2], tn;

int dfs(int u, int p, int nv) {
	int i;
	::nv[u] = nv;
	pai[u][0] = p;
	for(i = 1; i < 15; i++)
		pai[u][i] = pai[pai[u][i-1]][i-1];
	if(u != p) {
		for(i = 0; adj[u][i].fst != p; i++);
		ev[adj[u][i].snd] = u;
		cost[u] = c[adj[u][i].snd];
		swap(adj[u][i], adj[u].back());
		adj[u].pop_back();
	}
	int &f = vs[u];
	for(pii p : adj[u])
		f += dfs(p.fst, u, nv + 1);
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

void build(int i, int l, int r) {
	if(l == r) return (void) (tr[i] = pv[l]);
	int m = (l + r) / 2;
	build(L[i] = tn++, l, m);
	build(R[i] = tn++, m + 1, r);
	tr[i] = max(tr[L[i]], tr[R[i]]);
}

int query(int i, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return INT_MIN;
	if(l >= ql && r <= qr) return tr[i];
	int m = (l + r) / 2;
	return max(query(L[i], l, m, ql, qr), query(R[i], m + 1, r, ql, qr));
}

void change(int i, int l, int r, int pos, int x) {
	if(l == r) return (void) (tr[i] = x);
	int m = (l + r) / 2;
	if(pos <= m) change(L[i], l, m, pos, x);
	else change(R[i], m + 1, r, pos, x);
	tr[i] = max(tr[L[i]], tr[R[i]]);
}

void hld(int u) {
	vp[u] = cs[cur]++;
	if(vp[u] == 0) ch[cur] = u;
	vc[u] = cur;
	pv[vp[u]] = cost[u];
	if(adj[u].empty() && cs[cur] > 1) return build(ct[cur] = tn++, 1, cs[cur] - 1);
	if(adj[u].empty()) return;
	int bi = adj[u].front().fst;
	for(pii p : adj[u])
		if(vs[p.fst] > vs[bi])
			bi = p.fst;
	hld(bi);
	for(pii p : adj[u])
		if(p.fst != bi) {
			cur++;
			hld(p.fst);
		}
}

int path(int a, int b) {
	int mx = INT_MIN;
	while(a != b) {
		if(vp[a]) {
			int v = ch[vc[a]];
			if(vc[a] == vc[b]) v = b;
			mx = max(mx, query(ct[vc[a]], 1, cs[vc[a]] - 1, vp[v] + 1, vp[a]));
			a = v;
		} else {
			mx = max(mx, cost[a]);
			a = pai[a][0];
		}
	}
	return mx;
}

char s[100];
int main() {
	int i, n, a, b;
	for_tests(t, tt) {
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			adj[i].clear(), cs[i] = 0, vs[i] = 1;
		for(i = 0; i < n - 1; i++) {
			scanf("%d %d %d", &a, &b, &c[i]); a--; b--;
			adj[a].pb(pii(b, i));
			adj[b].pb(pii(a, i));
		}
		tn = cur = 0;
		dfs(0, 0, 0);
		hld(0);
		while(true) {
			scanf("%s", s);
			if(s[0] == 'D') break;
			scanf("%d %d", &a, &b);
			if(s[0] == 'C') {
				int v = ev[--a]; int c = vc[v];
				if(vp[v]) change(ct[c], 1, cs[c] - 1, vp[v], b);
				else cost[v] = b;
			} else {
				int c = lca(--a, --b);
				printf("%d\n", max(path(a, c), path(b, c)));
			}
		}
	}
}

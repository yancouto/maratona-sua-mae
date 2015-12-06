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
int vs[N], nv[N], pai[N][15], ev[N], cost[N], c[N];

int dfs(int u, int p, int nv) {
	int i; int &f = vs[u];
	::nv[u] = nv;
	pai[u][0] = p;
	for(i = 1; i < 15; i++)
		pai[u][i] = pai[pai[u][i-1]][i-1];
	if(p != u) {
		for(i = 0; adj[u][i].fst != p; i++);
		ev[adj[u][i].snd] = u;
		cost[u] = c[adj[u][i].snd];
		adj[u].erase(adj[u].begin() + i);
	}
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

int cs[N], ch[N], ct[N], tr[N << 2], L[N << 2], R[N << 2], tc, cur, vc[N], vp[N], pr[N];
void build(int i, int l, int r) {
	if(l == r) return (void) (tr[i] = pr[l]);
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

void set_t(int i, int l, int r, int p, int x) {
	if(l == r) return (void) (tr[i] = x);
	int m = (l + r) / 2;
	if(p <= m) set_t(L[i], l, m, p, x);
	else set_t(R[i], m + 1, r, p, x);
}

void hld(int u) {
	printf("cur=%d cs[cur]=%d\n", cur, cs[cur]);
	vc[u] = cur;
	vp[u] = cs[cur]++;
	pr[vp[u]] = cost[u];
	if(adj[u].empty()) return build(ct[cur] = tc++, 1, cs[cur] - 1);
	int bi = 0;
	for(int i = 1; i < adj[u].size(); i++)
		if(vs[adj[u][i].fst] > vs[adj[u][bi].fst])
			bi = i;
	hld(adj[u][bi].fst);
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
			int c = vc[a]; int d = ch[c];
			if(vc[b] == c) d = b;
			mx = max(mx, get(ct[c], 1, cs[c] - 1, vp[d] + 1, vp[a]));
			a = d;
		} else {
			mx = max(mx, cost[a]);
			a = pai[a][0];
		}
	}
	return mx;
}


int main() {
	int i, n, a, b;
	for_tests(t, tt) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) adj[i].clear(), cs[i] = 0, vs[i] = 1;
		for(i = 0; i < n - 1; i++) {
			scanf("%d %d %d", &a, &b, &c[i]); a--; b--;
			adj[a].pb(pii(b, i));
			adj[b].pb(pii(a, i));
		}
		dfs(0, 0, 0);
		tc = cur = 0;
		printf("%d\n", cs[0]);
		hld(0); char c;
		while(scanf(" %c%*s %d %d", &c, &a, &b) == 3) {
			if(c == 'C') {
				int v = ev[--a]; int ch = vc[v];
				if(vp[v]) set_t(ct[ch], 1, cs[ch] - 1, vp[v], b);
				else cost[v] = b;
			} else {
				int c = lca(--a, --b);
				printf("%d\n", max(path(a, c), path(b, c)));
			}
		}
	}
}

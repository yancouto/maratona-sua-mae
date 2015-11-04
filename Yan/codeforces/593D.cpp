// WA
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
const int N = 200019;
int d[N], f[N], lv[N], pai[N][19], vr[N], tempo;
int va[N], vb[N]; ull vx[N];
ull mult[N][19];
vector<int> adj[N];
int ot(int e, int u) { return va[e] == u? vb[e] : va[e]; }
const ull alot = 10000000000000000000ull, d18 = 1000000000000000000ull;
bool explode(ull a, ull b) {
	if(a > d18 || b > d18) return true;
	int la = 63 - __builtin_clzll(a), lb = 63 - __builtin_clzll(b);
	return la + lb >= 63 - __builtin_clzll(alot);
}
void dfs(int u, int pe, int lv) {
	::lv[u] = lv;
	vr[pe] = u;
	d[u] = tempo++;
	pai[u][0] = ((pe == -1)? 0 : ot(pe, u));
	mult[u][0] = ((pe == -1)? 1 : vx[pe]);
	for(int i = 1; i < 19; i++) {
		pai[u][i] = pai[pai[u][i - 1]][i - 1];
		ull m1 = mult[u][i - 1], m2 = mult[pai[u][i - 1]][i - 1];
		if(explode(m1, m2)) mult[u][i] = alot;
		else mult[u][i] = m1 * m2;
	}
	for(int e : adj[u]) {
		if(e == pe) continue;
		int v = ot(e, u);
		dfs(v, e, lv + 1);
	}
	f[u] = tempo++;
}

int lca(int u, int v) {
	if(lv[u] > lv[v]) swap(u, v);
	if(lv[u] < lv[v])
		for(int i = 18; i >= 0; i--)
			if(lv[pai[v][i]] >= lv[u])
				v = pai[v][i];
	if(u == v) return u;
	for(int i = 18; i >= 0; i--)
		if(pai[u][i] != pai[v][i])
			u = pai[u][i], v = pai[v][i];
	return pai[u][0];
}

inline bool is_anc(int p, int u) {
	return d[p] <= d[u] && f[u] <= f[p];
}


int st[600], sn;
ull vy[600]; int vn;
int pt[600], pn;

ull path(int a, int p) {
	if(lv[a] <= lv[p]) { return 1ull; }
	ull tot = 1;
	for(int i = 18; i >= 0; i--)
		if(lv[pai[a][i]] >= lv[p]) {
			if(explode(tot, mult[a][i])) return alot;
			tot *= mult[a][i];
			a = pai[a][i];
		}
	return tot;
}
ull np[N];

ull solve(int a, int p) {
	if(a == p) return 1ull;
	int i, j;
	pt[0] = a; pt[1] = p;
	pn = 2;
	ull tot = 1ull;
	for(j = 0; j < sn; j++)
		if(st[j] != p && is_anc(st[j], a) && is_anc(p, st[j])) {
			pt[pn++] = st[j];
			if(explode(tot, np[st[j]])) return alot;
			tot *= np[st[j]];
		}
	sort(pt, pt + pn, [](int u, int v) { return d[u] > d[v]; });
	for(i = 0; i < pn - 1; i++) {
		ull a;
		if(i) a = path(pai[pt[i]][0], pt[i + 1]);
		else a = path(pt[i], pt[i + 1]);
		if(explode(tot, a)) return alot;
		assert(a);
		tot *= a;
	}
	return tot;
}
void reset() {
	for(int i = 0; i < sn; i++)
		np[st[i]] = 0;
	sn = 0;
	tempo = 0;
	dfs(0, -1, 0);
}

int main() {
	int n, m, i, a, b, j, op;
	ull y, x;
	//while(true) {
	//	scanf("%I64u %I64u", &x, &y);
	//	printf("%I64u exploded %d\n", x * y, explode(x, y));
	//}
	scanf("%d %d", &n, &m);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d %I64u", &va[i], &vb[i], &vx[i]); 
		va[i]--; vb[i]--;
		adj[va[i]].pb(i);
		adj[vb[i]].pb(i);
	}
	dfs(0, -1, 0);
	int sq = ceil(sqrt(m)), tot = 0;
	for(i = 0; i < m; i++) {
		if(sn == sq) { reset(); }
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d %d %I64u", &a, &b, &y); a--; b--;
			int c = lca(a, b);
			ull tot = solve(a, c);
			if(tot == alot) { puts("0"); continue; }
			ull t2 = solve(b, c);
			if(explode(tot, t2)) { puts("0"); continue; }
			printf("%I64u\n", y / (tot * t2));
		} else {
			scanf("%d %I64u", &a, &y);
			if(!np[vr[a - 1]]) st[sn++] = vr[a - 1];
			np[vr[a - 1]] = y;
		}
	}
}

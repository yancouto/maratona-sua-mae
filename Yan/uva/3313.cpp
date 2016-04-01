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
#define dmg first
#define len second
const int N = 112345;

vector<int> adj[N];
int D[N], L[N], to[N];

int m;
ll best;
struct info {
	set<pii> p;
	int d, l;
	void clear() { p.clear(); d = l = 0; p.insert(pii(0, 0)); }
	void join(info &o);
	void add(pii a);
	ll bs(pii a);
} st[N];

void info::add(pii a) {
	a.dmg -= d;
	a.len += l;
	auto it = p.insert(a).fst;
	if(it != p.begin() && -prev(it)->len >= -a.len) { p.erase(it); return; }
	while(next(it) != p.end() && -a.len >= -next(it)->len)
		p.erase(next(it));
}

ll info::bs(pii a) {
	int M = m - a.dmg - d;
	auto it = p.upper_bound(pii(M, INT_MAX));
	if(it != p.begin()) assert(prev(it)->dmg + d + a.dmg <= m);
	if(it != p.begin()) return -prev(it)->len + l - a.len;
	else return -1e8;
}

void info::join(info &o) {
	if(p.size() < o.p.size()) {
		p.swap(o.p);
		swap(d, o.d);
		swap(l, o.l);
	}
	for(pii a : o.p) {
		a.dmg += o.d;
		a.len -= o.l;
		//printf("dmg=%d len=%d and got %d\n", a.dmg, -a.len, bs(a));
		best = max<ll>(best, bs(a));
		add(a);
	}
}

void dfs(int u, int p) {
	st[u].clear();
	for(int e : adj[u]) {
		if(to[e] == p) continue;
		dfs(to[e], u);
		st[to[e]].d += D[e];
		st[to[e]].l += L[e];
		//printf("joining %d to son %d\n\n", u+1, to[e]+1);
		st[u].join(st[to[e]]);
		//puts("------------------------\n\n");
	}
}

int main() {
	int i, n, a, b, l, d;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		best = 0;
		for(i = 0; i < n; i++) adj[i].clear();
		for(i = 0; i < n - 1; i++) {
			scanf("%d %d %d %d", &a, &b, &d, &l);
			a--; b--;
			D[2*i] = D[2*i+1] = d;
			L[2*i] = L[2*i+1] = l;
			to[2*i] = b; to[2*i+1] = a;
			adj[a].pb(2*i); adj[b].pb(2*i+1);
		}
		dfs(0, 0);
		printf("Case %d: %lld\n", tt, best);
	}
}

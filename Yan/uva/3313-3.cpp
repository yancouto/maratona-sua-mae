#include <bits/stdc++.h>
using namespace std;
#define dmg first
#define len second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 512345;

struct edge { int v, d, l; edge(int a, int b, int c) : v(a), d(b), l(c) {} };
vector<edge> adj[N];
int d[N], l[N];
set<pii> s[N];
typedef set<pii>::iterator sit;

sit prev(sit i) {
	--i;
	return i;
}

sit next(sit i) {
	++i;
	return i;
}

int best, m;
void dfs(int u, int p) {
	d[u] = l[u] = 0;
	s[u].clear(); s[u].insert(pii(0, 0));
	for(int i = 0; i < adj[u].size(); i++) {
		edge e = adj[u][i];
		int v = e.v;
		if(v == p) continue;
		dfs(v, u);
		d[v] += e.d;
		l[v] += e.l;
		if(s[v].size() > s[u].size()) {
			s[u].swap(s[v]);
			swap(l[u], l[v]);
			swap(d[u], d[v]);
		}
		for(sit I = s[v].begin(); I != s[v].end(); ++I) {
			pii p = *I;
			p.dmg += d[v];
			p.len -= l[v];
			if(p.dmg > m) continue;
			int M = m - p.dmg - d[u];
			if(M >= 0) {
				sit it = s[u].lower_bound(pii(M + 1, INT_MIN));
				if(it != s[u].begin()) best = max(best, -prev(it)->len + l[u] - p.len);
			}
			p.dmg -= d[u];
			p.len += l[u];
			if(s[u].count(p)) continue;
			sit it = s[u].lower_bound(p);
			if(it != s[u].begin() && -prev(it)->len >= -p.len) continue;
			it = s[u].insert(it, p);
			while(next(it) != s[u].end() && -p.len >= -next(it)->len)
				s[u].erase(next(it));
		}
	}
}


int main() {
	int i, n, a, b, d, l;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		for(i = 1; i <= n; i++) adj[i].clear();
		for(i = 0; i < n - 1; i++) {
			scanf("%d %d %d %d", &a, &b, &d, &l);
			adj[a].pb(edge(b, d, l));
			adj[b].pb(edge(a, d, l));
		}
		best = 0;
		dfs(1, 1);
		printf("Case %d: %d\n", tt, best);
	}
}

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
const int N = 50009;
int seen[N], tempo, t, is_c[N], has_c[N];
int d[N], low[N], v_sz[N];
vector<int> adj[N];
ll tot; int n_c, res;
int dfs2(int);
void dfs(int u, int p) {
	if(seen[u] == t) return;
	seen[u] = t;
	d[u] = low[u] = tempo++;
	int n_sons = 0;
	for(int v : adj[u]) {
		if(v == p) continue;
		bool now = (seen[v] != t);
		dfs(v, u);
		if(now) {
			n_sons++;
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], d[v]);
		if(low[v] >= d[u] && (u != 0 || n_sons > 1))
			is_c[u] = t;
	}
	n_c += (is_c[u] == t);
}

int seen2[N], t2;
int cuts = 0;
int dfs2(int u) {
	if(seen2[u] == t2) return 0;
	seen2[u] = t2;
	int r = 1;
	for(int v : adj[u])
		if(is_c[v] != t)
			r += dfs2(v);
		else if(seen2[v] != t2)
			cuts++, seen2[v] = t2;
	return r;
}

int ss[N];
int main() {
	int i, n, a, b;
	while(scanf("%d", &n) != EOF && n) {
		map<int, int> mp;
		t++;
		for(i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			if(!mp.count(a)) { mp[a] = mp.size() - 1; adj[mp[a]].clear(); }
			if(!mp.count(b)) { mp[b] = mp.size() - 1; adj[mp[b]].clear(); }
			a = mp[a]; b = mp[b];
			adj[a].pb(b);
			adj[b].pb(a);
		}
		tot = 1;
		n_c = tempo = res = 0;
		dfs(0, -1);
		printf("Case %d:", t);
		if(n_c == 0) {
			printf(" 2 %lld\n", (ll(mp.size()) * ll(mp.size() - 1)) / 2ll);
			continue;
		}
		int b = t2;
		for(i = 0; i < mp.size(); i++) {
			if(is_c[i] == t || seen2[i] > b) continue;
			t2++; cuts = 0;
			int g = dfs2(i);
			if(cuts == 1) tot *= ll(g), res++;
		}
		printf(" %d %lld\n", res, tot);
	}
}

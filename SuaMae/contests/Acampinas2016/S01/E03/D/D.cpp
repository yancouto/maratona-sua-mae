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

struct ed {
	int to, ti, tf, i;
	bool operator < (ed o) const { return ti < o.ti; }
};

int pf, tf;
int st[100009], sn, pl[100009];
vector<ed> adj[100009];
void dfs(int u) {
	if(u == pf && pl[u] <= tf) {
		printf("%d\n", sn);
		for(int i = 0; i < sn; i++) printf("%d ", st[i] + 1);
		putchar('\n');
		exit(0);
	}
	vector<ed> my;
	while(!adj[u].empty() && adj[u].back().ti >= pl[u]) {
		my.pb(adj[u].back());
		adj[u].pop_back();
	}
	for(ed e : my) {
		if(pl[e.to] <= e.tf) continue;
		pl[e.to] = e.tf;
		st[sn++] = e.i;
		dfs(e.to);
		sn--;
	}
}

int main() {
	int i, n, m, u, v, ti, pi;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d %d", &u, &v, &ti, &tf); u--; v--;
		adj[u].pb(ed{v, ti, tf, i});
	}
	for(i = 0; i < n; i++) {
		pl[i] = INT_MAX;
		sort(adj[i].begin(), adj[i].end());
	}
	scanf("%d %d %d %d", &pi, &pf, &ti, &tf); pi--; pf--;
	pl[pi] = ti;
	dfs(pi);
	puts("Impossible");
}

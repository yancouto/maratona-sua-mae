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
const int MAX = 105;
const int oo = 10000000;

int n, m, dmin, ba, bb;
vector<pii> g[MAX];
int seen[MAX], dist[MAX], pai[MAX], ans[MAX];

void dik(int o) {
	for(int i = 0; i <= n; i++)
		dist[i] = oo, seen[i] = 0;
	dist[o] = 0; pai[o] = o;
	while(42) {
		int v = 0;
		for(int i = 1; i <= n; i++)
			if(!seen[i] && (dist[i] < dist[v])) v = i;
		if(!v) break;
		seen[v] = 1;
		//printf("Vindo de %d\n", v);
		for(int i = 0; i < g[v].size(); i++) {
			int u = g[v][i].fst, w = g[v][i].snd;
			if(!seen[u] && dist[u] > dist[v] + w) {
				dist[u] = dist[v] + w;
				pai[u] = v;
			}
		//	printf("Indo %d seen %d dist %d\n", u, seen[u], dist[u]);
			if(seen[u] && pai[v] != u && dmin > dist[v] + dist[u] + w) {
				dmin = dist[v] + dist[u] + w;
				ba = u; bb = v;			
				for(int i = 1; i <= n; i++)
					ans[i] = pai[i];
			}
		}
	}
	
}

int main() {
	int u, v, w;
	while(42) {
		scanf("%d", &n);
		if(n == -1) break;
		scanf("%d", &m);
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			g[u].pb(pii(v, w));
			g[v].pb(pii(u, w));
		}
		dmin = oo;
		for(int i = 1; i <= n; i++)	dik(i);
		if(dmin >= oo) puts("No solution.");
		else {
			vector<int> path;
			v = ba;
			while(v != ans[v]) { path.pb(v); v = ans[v]; }
			path.pb(v);
			reverse(path.begin(), path.end());
			v = bb;
			while(v != ans[v]) { path.pb(v); v = ans[v]; }
			for(int i = 0; i < path.size(); i++)
				printf("%d ", path[i]);
			putchar('\n');
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n, m, degin[20009], degout[20009];
int d[20009], low[20009], seen[20009], tempo;
int st[20009], sn;
int comp;
int cs[20009];
vector<int> adj[20009];
vector<int> cmps[20009];

void dfs(int u, int p) {
	if(seen[u]) return;
	seen[u] = 1;
	d[u] = tempo++;
	low[u] = d[u];
	st[sn++] = u;
	//printf("in %d\n", u);
	for(int v : adj[u]) {
		dfs(v, u);
		low[u] = min(low[u], low[v]);
		//printf("low[%d] = %d\n", v, low[v]);
	}
	//printf("low[%d] = %d (d = %d)\n", u, low[u], d[u]);
	if(low[u] == d[u]) {
		int v = -1;
		while(v != u) {
			v = st[--sn];
			cs[v] = comp;
			cmps[comp].pb(v);
			low[v] = 1000000;
		}
		comp++; 
	}
}

int main() {
	int i, x, y;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		comp = tempo = 0; sn = 0;
		for(i = 0; i < n; i++) {
			degin[i] = degout[i] = 0;			 
			seen[i] = 0;
			cmps[i].clear();
			adj[i].clear();
		}
		int din = 0, dout = 0;
		for(i = 0; i < m; i++) {
			scanf("%d %d", &x, &y); x--; y--;
			adj[x].pb(y);
		}
		for(i = 0; i < n; i++)
			dfs(i, i);
		if(comp == 1) { puts("0"); continue; }  
		for(i = 0; i < comp; i++) 
			for(int u : cmps[i]) {
				//printf("%d in %d\n", u, i);
				for(int v : adj[u]) {
					if(cs[v] == i) continue;
					degout[i]++;
					degin[cs[v]]++;
				}

			}
		for(i = 0; i < comp; i++) {
			if(!degout[i]) dout++;
			if(!degin[i]) din++;
		}
		printf("%d\n", max(din, dout));
	}
	return 0;
}

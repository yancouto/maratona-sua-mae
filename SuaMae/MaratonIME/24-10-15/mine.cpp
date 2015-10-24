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
const int N = 2009;

vector<int> adj[N];
int seen[N], d[N], low[N];
int comp[N], tempo;
int deg[N], st[N], sn;
void dfs(int u) {
	if(seen[u]) return;
	seen[u] = true;
	d[u] = low[u] = tempo++;
	st[sn++] = u;
	for(int v : adj[u]) {
		dfs(v);
		low[u] = min(low[u], low[v]);
	}
	if(low[u] == d[u]) {
		int x;
		do {
			x = st[--sn];
			low[x] = INT_MAX;
			comp[x] = u;
		} while(x != u);
	}
}

ll x[N], y[N], di[N];
bool collide(int i, int j) {
	return 2 * max(abs(x[i] - x[j]), abs(y[i] - y[j])) <= di[i];
}

int main() {
	int i, j, n;
	for_tests(t, tt) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%lld %lld %lld", &x[i], &y[i], &di[i]);
			adj[i].clear();
			seen[i] = 0;
			comp[i] = -1;
			deg[i] = 0;
		}
		tempo = 0; sn = 0;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(collide(i, j)) {
					adj[i].pb(j);
				}
		for(i = 0; i < n; i++)
			dfs(i);
		
		for(i = 0; i < n; i++)
			for(int v : adj[i])
				if(comp[i] != comp[v])
					deg[comp[v]]++;
		int tot = 0;
		for(i = 0; i < n; i++)
			if(i == comp[i])
				tot += !deg[i];
		printf("%d\n", tot);
	}
}

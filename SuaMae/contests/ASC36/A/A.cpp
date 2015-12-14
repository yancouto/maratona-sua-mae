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
const int N = 100009;
int d[N], seen[N], low[N], tempo;
int st[N], sn, cmp[N], cn;
int isset[N];
bool bad;
vector<int> adj[N];
void dfs(int u) {
	if(seen[u]) return;
	seen[u] = true;
	d[u] = low[u] = tempo++;
	st[sn++] = u;
	for(int v : adj[u]) {
		dfs(v);
		low[u] = min(low[u], low[v]);
	}
	if(low[u] != d[u]) return;
	int a = -1, sz = 0; cn++;
	bool is = false;
	while(a != u) {
		a = st[--sn];
		low[a] = INT_MAX;
		cmp[a] = cn;
		if(cmp[a ^ 1] == cn) bad = true;
		sz++;
		is |= isset[a / 2];
	}
	if(!is)
		for(int i = 0; i < sz; i++) {
			isset[st[sn + i] / 2] = (st[sn + i] & 1) + 1;
		}
}

int b[N], c[N], p[N][2], w[N], us[N];
int main() {
	freopen("chip.in", "r", stdin);
	freopen("chip.out", "w", stdout);
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	for(i = 0; i < 2 * n; i++) {
		scanf("%d", &w[i]);
		w[i]--;
		if(us[w[i]]) p[w[i]][1] = i;
		else p[w[i]][0] = i;
		us[w[i]] = 1;
	}
	for(i = 0; i < n; i++)
		for(j = 0; j < 2; j++) {
			int v = 2 * i + j;
			int pos = p[i][j];
			int nx = (pos + 1) % (2 * n);
			int pr = (pos + 2*n - 1) % (2 * n);
			if(w[nx] != i && c[w[nx]] == c[i]) adj[v].pb(2 * w[nx] + (p[w[nx]][0] == nx));
			if(w[pr] != i && c[w[pr]] == c[i]) adj[v].pb(2 * w[pr] + (p[w[pr]][0] == pr));
		}
	bad = false;
	for(i = 0; i < 2 * n; i++)
		dfs(i);
	if(bad) { puts("NO"); return 0; }
	puts("YES");
	for(i = 0; i < n; i++)
		printf("%d ", p[i][isset[i] != 1] + 1);
	putchar('\n');
}

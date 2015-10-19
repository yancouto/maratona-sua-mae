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

int n, m, black, white;
vector<int> g[MAX];
vector<int> who[MAX][2];
vector<pii> comp;
int seen[MAX], cor[MAX];

bool dfs(int v, int c, int cc) {
	seen[v] = 1;
	if(c) black++;
	else white++;
	who[cc][c].pb(v);
	cor[v] = c;
	for(int i = 0; i < g[v].size(); i++) {
		if(seen[g[v][i]] && cor[g[v][i]] != !c) return false;
		if(seen[g[v][i]]) continue;
		if(!dfs(g[v][i], !c, cc)) return false;
	}
	return true;
}

int memo[MAX][55][55];
int solve(int i, int b, int w) {
	if(i == comp.size()) return (b == w) && (w == n);
	if(b > n || w > n) return false;
	int &m = memo[i][b][w];
	if(m != -1) return m;
	if(solve(i + 1, b + comp[i].fst, w + comp[i].snd)) return m = true;
	if(solve(i + 1, b + comp[i].snd, w + comp[i].fst)) return m = true;
	return m = false;
}

bool mark[MAX];
void build(int i, int b, int w) {
	if(i == comp.size()) return ;
	if(b > n || w > n) return ;
	int ans = solve(i, b, w);
	if(ans == solve(i + 1, b + comp[i].fst, w + comp[i].snd)) {
		mark[i] = 1;
		build(i + 1, b + comp[i].fst, w + comp[i].snd);
	}
	else 
		build(i + 1, b + comp[i].snd, w + comp[i].fst);
}

int main() {
	int u, v;
	scanf("%d %d\n", &n, &m);
	memset(memo, -1, sizeof memo);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		g[u].pb(v); g[v].pb(u);
	}
	for(int i = 1; i <= 2 * n; i++) {
		if(seen[i]) continue;
		black = white = 0; 
		if(!dfs(i, 1, comp.size())) {
			puts("IMPOSSIBLE");
			return 0;
		}
		comp.pb(pii(white, black));
	}
	if(!solve(0, 0, 0))	{ puts("IMPOSSIBLE"); return 0; }
	build(0, 0, 0);
	for(int i = 0; i < comp.size(); i++) {
		int b = 1;
		if(mark[i]) b = 0;
		for(int j = 0; j < who[i][!b].size(); j++)
			printf("%d ", who[i][!b][j]);
	}
	putchar('\n');
	for(int i = 0; i < comp.size(); i++) {
		int b = 1;
		if(mark[i]) b = 0;
		for(int j = 0; j < who[i][b].size(); j++)
			printf("%d ", who[i][b][j]);
	}
	putchar('\n');


	return 0;
}

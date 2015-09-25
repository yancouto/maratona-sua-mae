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
const int MAX = 500 * 500 * 5;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int g[502][502];
vector<int> v[502][502];
vector<int> adj[MAX];
bool ok;
int seen[MAX];
int st[MAX], sn, tempo;
int d[MAX], low[MAX];
int com[MAX], cn;
void dfs(int u) {
	if(seen[u]) return;
	seen[u] = true;
	st[sn++] = u;
	low[u] = d[u] = tempo++;
	for(int v : adj[u]) {
		dfs(v);
		low[u] = min(low[u], low[v]);
	}
	if(low[u] == d[u]) {
		int a; cn++;
		while((a = st[--sn]) != u) {
			com[a] = cn;
			if(com[a ^ 1] == cn) ok = false;
			low[a] = INT_MAX;
		}
		com[u] = cn;
		if(com[u ^ 1] == cn) ok = false;
		low[u] = INT_MAX;
	}
}
int n, m;
inline bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m && g[i][j] == 0;
}

int main() {
	int i, j, k, l, d; char c;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		int nb = 0;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++) {
				scanf(" %c", &c);
				if(c == 'B')
					g[i][j] = ++nb;
				else if(c == 'W')
					g[i][j] = 0;
				else g[i][j] = -1;
				v[i][j].clear();
			}
		for(i = 0; i < n * m * 4; i++)
			adj[i].clear();
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++) {
				if(g[i][j] <= 0) continue;
				for(d = 0; d < 4; d++) {
					int ni = i + dx[d], nj = j + dy[d];
					if(!valid(ni, nj)) { adj[g[i][j]*4 + d].pb((g[i][j]*4 + d) ^ 1); continue; }
					v[ni][nj].pb(g[i][j]*4 + d);
				}
			}
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				for(k = 0; k < v[i][j].size(); k++)
					for(l = k + 1; l < v[i][j].size(); l++) {
						adj[v[i][j][k]].pb(v[i][j][l] ^ 1);
						adj[v[i][j][l]].pb(v[i][j][k] ^ 1);
					}
		memset(seen, 0, sizeof seen);
		memset(com, 0, sizeof com);
		ok = true;
		sn = 0; tempo = 0; cn = 0;
		for(i = 0; i < (nb + 1) * 4; i++)
			dfs(i);
		if(ok) puts("YES");
		else puts("NO");
	}
}

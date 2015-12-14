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
const int N = 109;
int S[2][N], sz[2][N];
int find(int ind, int i) {
	if(S[ind][S[ind][i]] != S[ind][i]) S[ind][i] = find(ind, S[ind][i]);
	return S[ind][i];
}
void join(int i, int a, int b) {
	if((a = find(i, a)) == (b = find(i, b))) return;
	if(sz[i][a] < sz[i][b]) swap(a, b);
	sz[i][a] += sz[i][b];
	S[i][b] = a;
}


int seen[N], d[N], low[N], bad[N][N], tempo;
vector<int> adj[N];
int dfs(int u, int p) {
	if(seen[u]) return false;
	seen[u] = true;
	d[u] = low[u] = tempo++;
	for(int v : adj[u])
		if(v != p) {
			if(dfs(v, u)) return true;
			low[u] = min(low[u], low[v]);
			if(low[v] > d[u])
				return bad[u][v] = bad[v][u] = true;
		}
	return false;
}

bool dfs2(int u, int p, int U) {
	int child = 0;
	for(int v : adj[u]) {
		if(find(0, v) != find(0, U)) continue;
		child++;
		if(v != p && !dfs2(v, u, U)) return false;
	}
	if(child == 3) return false;
	return true;
}

bool do4(int u, int ar) {
	if(ar != 3) return false;
	return dfs2(u, -1, u);
}

int n;
bool is_dum(int u) {
	//printf("test_dum %d\n", u + 1);
	int s0 = sz[0][find(0, u)];
	if(s0 != 4 && !dfs(u, -1)) return false;
	int ar = 0;
	for(int i = 0; i < n; i++) {
		if(find(0, i) != find(0, u)) continue;
		//printf("has %d\n", i + 1);
		for(int v : adj[i])
			if(find(0, v) == find(0, u) && !bad[i][v]) {
				join(1, v, i);
				ar++;
			}
	}
	if(s0 == 4) return do4(u, ar / 2);
	int s = sz[1][find(1, u)];
	if(s0 == 4 && s == s0 && ar == 6) return true;
	else if(s0 == 4) return false;
	//printf("size1 %d ar %d\n", s, ar);
	if(s0 != 2 * s) return false;
	return (ar / 2) == (s * (s - 1));
}

int main() {
	int i, m, a, b;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) {
			S[0][i] = S[1][i] = i;
			sz[0][i] = sz[1][i] = 1;
			adj[i].clear();
		}
		memset(bad, 0, sizeof bad);
		memset(seen, 0, sizeof seen);
		tempo = 0;
		for(i = 0; i < m; i++) {
			scanf("%d %d", &a, &b); a--; b--;
			adj[a].pb(b);
			adj[b].pb(a);
			join(0, a, b);
		}
		int tot = 0;
		for(i = 0; i < n; i++)
			if(S[0][i] == i)
				tot += is_dum(i);
		printf("Case #%d: %d\n", tt, tot);
	}
}

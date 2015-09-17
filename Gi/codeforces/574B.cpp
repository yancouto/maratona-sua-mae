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


vector<int> adj[4010];

ll min(ll a, ll b) { if(a < b) return a; return b; }

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for(int i = 0; i < n; i++) {
		if(adj[i].size() < 2) continue;
		sort(adj[i].begin(), adj[i].end());
	}
	int ans = 1000000000;
	for(int i = 0; i < n; i++) {
		if(adj[i].size() <= 1) continue;
		for(int j = 0; j < adj[i].size(); j++) {
			for(int k = j + 1; k < adj[i].size(); k++) {
				int u = adj[i][j];
				int v = adj[i][k];
				vector<int> :: iterator it;
				if(binary_search(adj[u].begin(), adj[u].end(), v)) {
					ans = min(ans, adj[i].size() + adj[u].size() + adj[v].size());
				}
			}
		}
	}
	if(ans == 1000000000) puts("-1");
	else printf("%d\n", ans - 6);
}

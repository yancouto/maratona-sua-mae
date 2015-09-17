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

vector<int> adj[1000002], ordt;
int dg[1000005];
int n, m;

void ord_top() {
	queue<int> q;
	for(int i = 0; i < n; i++)
		if(!dg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		ordt.pb(u);
		for(int v = 0; v < adj[u].size(); v++) {
			dg[adj[u][v]]--;
			if(!dg[adj[u][v]]) q.push(adj[u][v]);
		}
	}
}

int main() {
	while(42) {
		scanf("%d %d", &n, &m);
		if(!n && !m) return 0;
		ordt.clear();
		for(int i = 0; i < n; i++)
			adj[i].clear();
		memset(dg, 0, sizeof dg);
		for(int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			a--; b--;
			adj[a].pb(b);
			dg[b]++;
		}
		ord_top();
		bool imp = false;
		for(int i = 0; i < n && !imp; i++)
			if(dg[i]) imp = true;
		if(imp) puts("IMPOSSIBLE");
		else for(int i = 0; i < ordt.size(); i++) printf("%d\n", ordt[i] + 1);
	}
	return 0;
}

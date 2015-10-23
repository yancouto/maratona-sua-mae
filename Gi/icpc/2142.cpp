#include <bits/stdc++.h>
using namespace std;
#define x first
#define w second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 70;
const int oo = 100000000;

int n, K;
int seen[N], v[N], h[N];
vector<pii> g[N];

int solve(int no, int k, int pai) {
	int &m = memo[no][k][can];
	if(m.x != -1) return m;
	bool end = true;
	seen[no] = 1;
	for(int i = 0; i < g[no].size(); i++) {
		if(seen[g[no][i].x]) continue;
		end = false;

		v[i] = solve(g[no][i].x, 0);
		h[i] = solve(g[no][i].x, 1);
	}
	if(end) return 0;
}

int main() {
	for_tests(t, tt) {
		int u, v, w;
		scanf("%d %d", &n, &K);
		for(int i = 0; i < n-1; i++) {
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			g[u].pb(pii(v, w));
			g[v].pb(pii(u, w));
		}
		memset(memo, -1, sizeof memo);
		memset(seen, 0, sizeof seen);
		printf("%d\n", solve(0, 0));
	}
	return 0;
}

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

struct ed {
	ed() {}
	ed(int a, int b, int c) : to(a), v(b), d(c) {}
	int to, v, d;
};

vector<ed> adj[209];

bool seen[205][1005];
double memo[205][1005];
double solve(int u, int p) {
	double &r = memo[u][p];
	if(seen[u][p]) return r;
	seen[u][p] = 1;
	for(ed e : adj[u]) {
		r = max(r, (p * double(e.v)) / e.d);
		if(e.d * 2 <= p) r = max(r, e.v * 2 + solve(e.to, p - 2 * e.d));
	}
	return r;
}

int main() {
	int i, n, m, p, s, t, d, v;
	scanf("%d %d %d", &n, &m, &p);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d %d", &s, &t, &d, &v); s--; t--;
		adj[s].pb(ed(t, v, d));
		adj[t].pb(ed(s, v, d));
	}
	printf("%.10f\n", solve(0, p));
}

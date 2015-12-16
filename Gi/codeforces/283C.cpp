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
const int N = 310;

ll n, q, t;
ll a[N], dg[N], dgs[N], seen[N];
ll ax[N], cur[N];
ll memo[N][100100];
vector<int> g[N];

void ord(int u) {
	deque<int> dq;
	dq.pb(u);
	while(!dq.empty()) {
		u = dq.front();
		dq.pop_front();
		ax[u] = cur[u] + a[u];
		seen[u] = 1;
		for(int i = 0; i < g[u].size(); i++) {
			dg[g[u][i]]--;
			cur[g[u][i]] += ax[u];
			if(!dg[g[u][i]]) dq.pb(g[u][i]);
		}
	}
}

ll solve(int i, int d) {
	if(i == n) return !d;
	if(d < 0) return 0;
	ll &me = memo[i][d];
	if(me != -1) return me;
	me = solve(i + 1, d);
	if(d - ax[i] >= 0) me = mod(me +  solve(i, d - ax[i]));
	return me;
}

int main() {
	int i, u, v;
	cin >> n >> q >> t;
	for(i = 0; i < n; i++) cin >> a[i];
	for(i = 0; i < q; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		g[u].pb(v);	
		dg[v]++; dgs[u]++;
	}
	for(i = 0; i < n; i++) 
		if(!dg[i]) ord(i);
	for(i = 0; i < n; i++)
		if(!seen[i]) { puts("0"); return 0; }
	for(i = 0; i < n; i++)
		if(dgs[i]) t -= ax[i];
	if(t < 0) { puts("0"); return 0; }
	memset(memo, -1, sizeof memo);
	cout << solve(0, t) << '\n';
	return 0;
}

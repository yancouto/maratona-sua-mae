#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100005;

int n;
int x[N];
pii memo[N];
vector<int> g[N];

pii solve(int v, int pai) {
	pii &m = memo[v];
	if(m.fst != -1) return m;
	m.fst = 1; m.snd = 0;
	for(int i = 0; i < g[v].size(); i++) {
		if(g[v][i] == pai) continue;
		pii r = solve(g[v][i], v);
		m.snd = mod(m.snd * r.fst);
		m.snd = mod(m.snd + mod(m.fst * r.snd));
		m.fst = mod(m.fst * r.fst);
	}
	if(x[v]) m.snd = m.fst;
	else m.fst = mod(m.fst + m.snd);
	//printf("Vertice %d = (%d %d)\n", v, m.fst, m.snd);
	return m;
}

int main() {
	int u, i;
	scanf("%d", &n);
	memset(memo, -1, sizeof memo);
	for(i = 0; i < n-1; i++) {
		scanf("%d", &u);
		g[u].pb(i+1);
		g[i+1].pb(u);
	}
	for(i = 0; i < n; i++) 
		scanf("%d", &x[i]);
	printf("%lld\n", solve(0, 0).snd);
	return 0;
}

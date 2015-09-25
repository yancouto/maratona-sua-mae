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

map<string, int> mp;
int get(string s) {
	if(!mp.count(s)) mp[s] = mp.size() - 1;
	return mp[s];
}
char s1[100], s2[100];
int m[1003], to[1003], t[1003], d[1003]; double p[1003];
vector<int> adj[2003];
double memo[60][2003];
int seen[60][2003], i2;
double solve(int ti, int v) {
	if(v == i2) return 0;
	if(seen[ti][v] == 1) return memo[ti][v];
	if(seen[ti][v] == 2) return 10000000.;
	seen[ti][v] = 2;
	double &r = memo[ti][v];
	r = 1/0.;
	for(int e : adj[v]) {
		int dt = (m[e] - ti + 60) % 60;
		double g = (1. - p[e]) * (dt + t[e] + solve((m[e] + t[e]) % 60, to[e]));
		for(int i = 1; i <= d[e]; i++)
			g += p[e] / d[e] * (dt + t[e] + i + solve((m[e] + t[e] + i) % 60, to[e]));
		r = min(r, g);
	}
	seen[ti][v] = 1;
	return r;
}

int main() {
	int i, n;
	for_tests(tn, tt) {
		mp.clear();
		scanf("%s %s", s1, s2);
		int i1 = get(s1); i2 = get(s2);
		scanf("%d", &n);
		for(i = 0; i < 2003; i++) adj[i].clear();
		for(i = 0; i < n; i++) {
			scanf("%s %s %d %d %lf %d", s1, s2, &m[i], &t[i], &p[i], &d[i]);
			p[i] /= 100.;
			to[i] = get(s2);
			adj[get(s1)].pb(i);
		}
		memset(seen, 0, sizeof seen);
		double mn = 1/0.;
		for(i = 0; i < 60; i++)
			mn = min(mn, solve(i, i1));
		if(mn > 1000000000.) puts("IMPOSSIBLE");
		else printf("%.10f\n", mn);
	}
}

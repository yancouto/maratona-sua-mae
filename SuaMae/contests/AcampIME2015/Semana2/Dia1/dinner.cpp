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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif

int N, M, B, K, R, T;
int p[6][103];
struct ed {
	int to, t, m;
	ed() {}
	ed(int a, int b, int c) : to(a), t(b), m(c) {}
};

vector<ed> adj[103];

int seen[102][5][6][202][2];
int memo[102][5][6][202][2];
int memo2[102][5][6][202][2];
int solve(int i, int b, int k, int t, bool salt) {
	// printf("Calc%d(%d, %d, %d, %d)\n", salt, i, b, k, t);
	int aa, bb;
	if(t < 0) return INT_MAX;
	int &m = memo[i][b][k][t][salt];
	int &m2 = memo2[i][b][k][t][salt];
	if(i == N - 1 && k == 0) { m2 = 0; return 0; }
	if((i == 0 || i == N - 1) && k) return INT_MAX;
	if(t <= 0) return INT_MAX;
	if(seen[i][b][k][t][salt]) return m;
	seen[i][b][k][t][salt] = 1;
	if(!salt) {
		m = solve(i, b, k, t, true);
		if(m == INT_MAX) m2 = INT_MAX;
		else m2 = memo2[i][b][k][t][true];
		if(b < B && p[k][i] >= 0 && (aa = solve(i, b + 1, k, t, true)) != INT_MAX) {
			bb = memo2[i][b + 1][k][t][true];
			if((aa + p[k][i] < m || (aa + p[k][i] == m && bb + p[k][i] < m2)) && bb + p[k][i] <= R) {
				m = aa + p[k][i];
				m2 = bb + p[k][i];
			} 
		}
		if(b && p[k][i] >= 0 && (aa = solve(i, b - 1, k, t, true)) != INT_MAX) {
			bb = memo2[i][b-1][k][t][true];
			if(aa - p[k][i] < m || (aa - p[k][i] == m && max(0, bb - p[k][i]) < m2)) {
				m = aa - p[k][i];
				m2 = max(0, bb - p[k][i]);
			}
		}
		// printf("m%d(%d, %d, %d, %d) = %d\n", salt, i, b, k, t, m);
		return m;
	}
	// printf("call1\n");
	m = solve(i, b, (k + 1) % K, t - 1, false);
	if(m == INT_MAX) m2 = INT_MAX;
	else m2 = memo[i][b][(k + 1) % K][t - 1][false];

	for(ed e : adj[i]) {
		// printf("%d->%d (%d, %d)\n", i, e.to, e.t, e.m);
		// printf("calle\n");
		if((aa = solve(e.to, b, k, t - e.t, false)) != INT_MAX) {
			bb = memo2[e.to][b][k][t - e.t][false];
			if((aa + e.m < m || (aa + e.m == m && bb + e.m < m2)) && bb + e.m <= R) {
				m = aa + e.m;
				m2 = bb + e.m;
			}
		}
		// printf("calle--\n");
	}
	// printf("m%d(%d, %d, %d, %d) = %d\n", salt, i, b, k, t, m);
	return m;
}

int main() {
	int i, j, a, b, t, m;
	for_tests(tt, ttt) {
		scanf("%d %d %d %d %d %d", &N, &M, &B, &K, &R, &T);
		for(i = 0; i < N; i++) adj[i].clear();
		for(i = 0; i < K; i++)
			for(j = 0; j < N; j++)
				scanf("%d", &p[i][j]);
		for(i = 0; i < M; i++) {
			scanf("%d %d %d %d", &a, &b, &t, &m); a--; b--;
			// printf("adding %d->%d (%d, %d)\n", a, b, t, m);
			adj[a].pb(ed(b, t, m));
			adj[b].pb(ed(a, t, m));
		}
		memset(seen, 0, sizeof seen);
		if(solve(0, 0, 0, T, true) <= R)
			printf("Case #%d: %d\n", ttt, R - solve(0, 0, 0, T, true));
		else
			printf("Case #%d: Forever Alone\n", ttt);
	}
	return 0;
}
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
int n, f, t;
int grid[27][27];
int ff[6][2];
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < n; }
int ox, oy;
int memo[26][26][26];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int solve(int i, int j, int tt) {
	if(i == ox && j == oy) return 0;
	if(tt == t) return INT_MAX;
	int &m = memo[i][j][tt];
	if(m != -1) return m;
	m = INT_MAX;
	for(int dd = 0; dd < 4; dd++)
		if(valid(i + d[dd][0], j + d[dd][1]))
			m = min(m, solve(i + d[dd][0], j + d[dd][1], tt + 1));
	if(m < INT_MAX) m += grid[i][j];
	return m;
}

int totcost(int x, int y) {
	memset(memo, -1, sizeof memo);
	ox = x; oy = y;
	int cost = 0;
	// debug("x%d y%d", x, y);
	for(int i = 0; i < f; i++) {
		int s = solve(ff[i][0], ff[i][1], 0);
		if(s == INT_MAX)  {
			cost = INT_MAX;
			break;
		}
		else cost += s;
		// debug("f%d -> %d (c %d)", i, solve(ff[i][0], ff[i][1], 0), cost);
	}
	return cost;
}

int main() {
	int i, j, x, y, tt = 0;
	while(true) {
		scanf("%d %d %d", &n, &f, &t);
		if(!n) return 0;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &grid[i][j]);
		for(i = 0; i < f; i++)
			scanf("%d %d", &ff[i][0], &ff[i][1]);
		pii p; int mcost = INT_MAX;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++) {
				int t = totcost(i, j);
				if(t < mcost) {
					mcost = t;
					p = pii(i, j);
				}
			}
		printf("Case #%d: ", ++tt);
		if(mcost == INT_MAX) printf("Impossible.\n");
		else printf("Selected city (%d,%d) with minimum cost %d.\n", p.fst, p.snd, mcost);
	}
}
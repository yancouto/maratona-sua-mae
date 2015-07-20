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
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
ll adj[2004][2004];
int n, m, k;
int es[1000003][2];
ll get(int i1, int j1, int i2, int j2) {
	i1 += 2; j1 += 2; i2 += 2; j2 += 2;
	ll ret =  adj[i2][j2] - adj[i1-1][j2] - adj[i2][j1-1] + adj[i1-1][j1-1];
	return ret;
}

int main() {
	int i, j, a, b;
	for_tests(t, tt) {
		scanf("%d %d %d", &n, &m, &k);
		for(i = 0; i < n + m; i++)
			for(j = 0; j < n + m; j++)
				adj[i+2][j+2] = 0;
		for(i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);
			es[i][0] = --a; es[i][1] = --b;
			adj[a + 2][b + n + 2] = adj[b + n + 2][a + 2] = 1;
		}
		for(i = 0; i < n+m; i++)
			for(j = 1; j < n+m; j++)
				adj[i+2][j+2] += adj[i+2][j + 1];
		for(j = 0; j < n+m; j++)
			for(i = 1; i < n+m; i++)
				adj[i+2][j+2] += adj[i+1][j+2];
		ll tot = 0;
		for(i = 0; i < k; i++) {
			if(es[i][0] > 0 && es[i][1] < m)
				tot += get(0, es[i][1] + 1 + n, es[i][0] - 1, n + m - 1);
			if(es[i][0] < n && es[i][1] > 0)
				tot += get(es[i][0] + 1, 0 + n, n - 1, es[i][1] - 1 + n);
		}
		printf("Test case %d: %lld\n", tt, tot / 2);
	}
	return 0;
}

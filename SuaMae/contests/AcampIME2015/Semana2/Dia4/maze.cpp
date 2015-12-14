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
int n, m;
double L;
char g[103][103];
int is, js, ie, je;
ll ds[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
ll up;
struct st {
	int i, j;
	ll d[2];
	st() {}
	st(st &o, int dd) : i(o.i + ds[dd][0]), j(o.j + ds[dd][1]) { d[0] = o.d[0] + abs(up* (ll)ds[dd][0]); d[1] = o.d[1] + abs(100000000ll * (ll)ds[dd][1]); }
	st(int a, int b, int c, int dd) : i(a), j(b) { d[0] = c; d[1] = dd; }
	bool operator < (const st &s) const { return (d[0] + d[1]) > (s.d[0] + s.d[1]); }
};
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
inline bool valid(st &s) { return valid(s.i, s.j); }


inline char at(st &p) { return g[p.i][p.j]; }

int seen[103][103];
st bfs() {
	memset(seen, 0, sizeof seen);
	priority_queue<st> q;
	q.push(st(is, js, 0, 0));
	// printf("start (%d, %d)\n", is, js);
	while(!q.empty()) {
		st p = q.top();
		q.pop();
		if(seen[p.i][p.j]) continue;
		seen[p.i][p.j] = 1;
		if(at(p) == 'E') return p;
		for(int i = 0; i < 4; i++) {
			st b(p, i);
			if(valid(b) && at(b) != '#' && !seen[b.i][b.j]) {
				// printf("(%d, %d) with (%d, %d)\n", b.i, b.j, b.d[0], b.d[1]);
				q.push(b);
			}
		}
	}
	st lixo;
	return lixo;
}

int main() {
	int i, j;
	for_tests(t, tt) {
		scanf("%lf %d ", &L, &n);
		for(i = 0; i < n; i++) {
			for(j = 0; ; j++) {
				scanf("%c", &g[i][j]);
				char c = g[i][j];
				// printf("(%d, %d) -> %c\n", i, j, c);
				if(c != ' ' && c != '#' && c != 'S' && c != 'E') break;
				if(c == 'S') {
					is = i;
					js = j;
				} else if(c == 'E') {
					ie = i;
					je = j;
				}
			}
			m = j;
			scanf(" ");
		}
		ll l = 0, r = 2000000000ll;
		ll LLL = L * 100000000ll;
		while(l < r) {
			ll m = (l + r) / 2;
			up = m;
			st s = bfs();
			// printf("found (%d, %d)=%d  %.0f with m=%d\n", s.d[0], s.d[1], s.d[0] + s.d[1], L*1000, m);
			if(s.d[0] + s.d[1] < LLL) l = m + 1;
			else r = m;
		}
		printf("Case #%d: ", tt);
		printf("%.3f%%\n", l / 1000000.);
	}
	return 0;
}
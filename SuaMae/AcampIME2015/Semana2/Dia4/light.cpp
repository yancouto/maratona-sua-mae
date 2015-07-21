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
const int none = 10;
int mila;
int g[8][8];
int li[8][8];
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct pos {
	int i, j;
	pos() {}
	pos(int a, int b) : i(a), j(b) {}
	pos walk(int d) const {
		return pos(i + dirs[d][0], j + dirs[d][1]);
	}
};

inline bool valid(const pos &p) {
	return p.i >= 0 && p.j >= 0 && p.i < n && p.j < m;
}

bool ok() {
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			if(g[i][j] == none && !li[i][j])
				return false;
			if(g[i][j] >= 1 && g[i][j] <= 4)
				return false;
		}
	return true;
}

inline int& at(const pos &p) { return g[p.i][p.j]; }
inline int& l(const pos &p) { return li[p.i][p.j]; }

bool zero_squares(const pos &p) {
	for(int i = 0; i < 4; i++) {
		pos p2 = p.walk(i);
		if(valid(p2) && at(p2) == 0)
			return true;
	}
	return false;
}

bool check_0(pos p) {
	p.i--; p.j--;
	if(valid(p) && at(p) >= 1 && at(p) <= 4) return true;
	return false;
}

inline void next(pos, int);

void deb() {
	return;
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++)
			printf("%3d ", g[i][j]);
		putchar('\n');
	}
	puts("------------");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++)
			printf("%3d ", li[i][j]);
		putchar('\n');
	}
	if(ok()) puts("OK");
	else puts("NOK");

}

void solve(pos p, int num) {
	// printf("(%d, %d) -- %d\n", p.i, p.j, num);
	deb();
	if(num >= mila) return;
	if(p.i == n && ok()) mila = num;
	if(p.i == n) return;
	if(check_0(p)) return;
	if(at(p) != none || l(p) || zero_squares(p)) {
		next(p, num);
		return;
	}
	next(p, num);
	l(p)++;
	for(int i = 0; i < 4; i++) {
		pos p2 = p.walk(i);
		if(valid(p2) && at(p2) >= 1 && at(p2) <= 4) at(p2)--;
		while(valid(p2) && at(p2) == none) {
			l(p2)++;
			p2 = p2.walk(i);
		}
	}
	next(p, num + 1);
	l(p)--;
	for(int i = 0; i < 4; i++) {
		pos p2 = p.walk(i);
		if(valid(p2) && at(p2) >= 0 && at(p2) <= 4) at(p2)++;
		while(valid(p2) && at(p2) == none) {
			l(p2)--;
			p2 = p2.walk(i);
		}
	}
}

inline void next(pos p, int num) {
	p.j++;
	if(p.j == m) { p.j = 0; p.i++; }
	solve(p, num);
}

int main() {
	int i, j;
	while(true) {
		int b;
		scanf("%d %d", &n, &m);
		if(!n) return 0;
		mila = 50;
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++) {
				g[i][j] = none;
				li[i][j] = 0;
			}
		scanf("%d", &b);
		for(i = 0; i < b; i++) {
			int r, c, k;
			scanf("%d %d %d", &r, &c, &k);
			g[r-1][c-1] = k;
		}
		deb();
		solve(pos(0, 0), 0);
		if(mila == 50) puts("No solution");
		else printf("%d\n", mila);
	}
}
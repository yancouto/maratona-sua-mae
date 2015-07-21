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
int n;
int mday;
struct con {
	int yen;
	int i, j;
	void read() { scanf("%d %d %d", &i, &j, &yen); mday = max(mday, j); }
	bool operator < (const con& o) const { return i < o.i; }
} ps[1003];

//int memo[1003][367];
//int solve(int i, int last2, int last2) {
//	if(i == n) return 0;
//	int &m = memo[i][last];
//	if(m != -1) return m;
//	m = solve(i + 1, last);
//	if(ps[i].i > last)
//		m = max(m, solve(i + 1, ps[i].j) + ps[i].yen);
//	return m;
//}


int memo[2][367][367];
int& m(int i, int d1, int d2) { return memo[i%2][min(d1, d2)][max(d1, d2)]; }
int main() {
	int i, j, k;
	while(true) {
		scanf("%d", &n);
		if(!n) return 0;
		mday = 1;
		for(i = 0; i < n; i++)
			ps[i].read();
		sort(ps, ps + n);
		for(i = 0; i <= mday; i++)
			for(j = i; j <= mday; j++)
				m(n, i, j) = 0;
		for(i = n - 1; i >= 0; i--)
			for(j = 0; j <= mday; j++)
				for(k = j; k <= mday; k++) {
					m(i, j, k) = m(i + 1, j, k);
					if(ps[i].i > j) m(i, j, k) = max(m(i, j, k), m(i + 1, ps[i].j, k) + ps[i].yen);
					if(ps[i].i > k) m(i, j, k) = max(m(i, j, k), m(i + 1, j, ps[i].j) + ps[i].yen);
				}

		printf("%d\n", m(0, 0, 0));
	}
}

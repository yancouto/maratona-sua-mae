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

int ex[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int nd, n;
int get_d(int d) {
	return (n / ex[nd - d - 1]) % 10;
}

int memo[10][2][2];
int solve(int d, bool has4, bool pre) {
	if(d == nd) return has4;
	int dd = get_d(d);
	int &ret = memo[d][has4][pre];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i <= 9; i++) {
		if(pre && i > dd) break;
		ret += solve(d + 1, has4 || (i == 4), pre && i == dd);
	}
	return ret;
}

int main() {
	while(true) {
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		if(!n) return 0;
		nd = 0;
		for(int aux = n; aux; aux /= 10) nd++;
		printf("%d: %d\n", n, n - solve(0, false, true));
	}
}
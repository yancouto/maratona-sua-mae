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
int p, k, n;

int main() {
	int i, j, t, a, b;
	for(t = 0; t < 10; t++) {
		map<int, int> mp;
		if(scanf("%d %d %d", &p, &k, &n) == EOF) return 0;
		mp[k + 1] = 0;
		for(i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			if(mp.count(a)) mp[a] = mp[a] + 1;
			else mp[a] = 1;
			if(mp.count(b + 1)) mp[b + 1] = mp[b + 1] - 1;
			else mp[b + 1] = -1;
		}
		int last = -1, ppl = 0;
		int mxppl = 0, mnppl = INT_MAX;
		for(pii pp : mp) {
			if((last >= p && last <= k) || ((pp.fst - 1) >= p && (pp.fst - 1) <= k) || (p >= last && k <= (pp.fst - 1))) {
				mxppl = max(ppl, mxppl);
				mnppl = min(ppl, mnppl);
			}
			ppl += pp.snd;
			last = pp.fst;
		}
		if(mnppl == INT_MAX) mnppl = 0;
		printf("%d %d\n", mnppl, mxppl);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ll x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int main() {
	for_tests(t, tt) {
		ll n;
		scanf("%lld", &n);
		n = (n + 4ll) / 5ll;
		ll minh = 0, minv = 0;
		for(ll i = 1ll; i * i <= n; i++) {
			ll h = i;
			ll v = (n + i - 1ll) / i;
			h = h * 44ll + 4ll;
			v = v * 10ll + 2ll;
			ll aux = max(h, v); v = min(h, v); h = aux;
			if(minh == 0ll || (h*v) < (minh*minv) || ((h*v) == (minh*minv)) && ((h - v) < (minh - minv))) {
				minh = h;
				minv = v;
			}
		}
		printf("%llu X %llu = %llu\n", minh, minv, minh*minv);
	}
	return 0;
}

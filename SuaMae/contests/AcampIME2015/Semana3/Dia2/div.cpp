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
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) {fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");}
#else
#	define debug(args...) {}
#endif
ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ll s[1000009];
int main() {
	int i, x, d, n;
	for_tests(t, tt) {
		scanf("%d %d", &d, &n);
		modn = d;
		for(i = 0; i < d; i++)
			s[i] = 0ll;
		s[0] = 1ll;
		ll sum = 0ll;
		for(i = 0; i < n; i++) {
			scanf("%d", &x);
			sum = mod(sum + x);
			s[sum]++;			
		}
		ll tot = 0ll;
		for(i = 0; i < d; i++)
			tot += (s[i] * (s[i] - 1ll)) / 2ll;
		printf("%lld\n", tot);

	}
}

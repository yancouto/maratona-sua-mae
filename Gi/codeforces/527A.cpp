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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }


int main() {
	ll a, b; scanf("%lld %lld", &a, &b);
	ll ans = 0;
	while(42) {
		ans += a/b;
		if(a % b == 0) break;
		ll aa = b;
		ll bb = a % b;
		a = aa;
		b = bb;
	}
	printf("%lld\n", ans);
	return 0;
}

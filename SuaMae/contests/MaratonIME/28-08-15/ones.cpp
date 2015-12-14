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

ll n;
ll memo[34][2][35];
ll solve(int i, bool pre, int num) {
	if(i < 0) return num;
	ll &r = memo[i][pre][num];
	if(r != -1) return r;
	r = 0;
	for(int d = 0; d <= 1; d++) {
		if(pre && d > !!(n & (1ll << i))) break;
		r += solve(i - 1, pre && d == !!(n & (1ll << i)), num + d);
	}
	return r;
}

int main() {
	int t = 0, a, b;
	while(true) {
		scanf("%d %d", &a, &b);
		if(!a && !b) return 0;
		memset(memo, -1, sizeof memo);
		n = b;
		ll x = solve(32, true, 0);
		ll y = 0;
		if(a) {
			memset(memo, -1, sizeof memo);
			n = a - 1;
			y = solve(32, true, 0);
		}
		printf("Case %d: %lld\n", ++t, x - y);
	}
}

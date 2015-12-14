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
int n, k;
ll a[10009];

bool poss(ll m) {
	ll tot = 0;
	for(int i = 0; i < n; i++)
		tot += a[i] / m;
	return tot >= k;
}

int main() {
	int i; double ax;
	for_tests(t, tt) {
		scanf("%d %d", &n, &k);
		for(i = 0; i < n; i++) {
			 scanf("%lf", &ax);
			 a[i] = ax * 10000ll;
		}
		ll l = 1, r = 10000000000;
		while(l < r) {
			 ll mid = (l + r + 1) / 2;
			 if(poss(mid)) l = mid;
			 else r = mid - 1;
		}
		if(tt > 1) putchar('\n');
		if(l < 100) puts("0.00");
		else printf("%lld.%02lld\n", l / 10000ll, (l / 100ll) % 100ll);
	}
}

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ll p[1000009];
int n, k;
bool ok(ll d) {
	ll lim = 0;
	for(int i = 0; i < 2 * n * k; i++) {
		if(p[i + 1] && p[i + 1] - p[i] <= d)
			lim += 2 * k, i++;
		if(i >= lim) return false;
	}
	return true;
}

int main() {
	int i;
	while(scanf("%d %d", &n, &k) != EOF) {
		for(i = 0; i < 2*n*k; i++)
			scanf("%lld", &p[i]);
		sort(p, p + 2*n*k);
		ll l = 0, r = 2000000009;
		while(l < r) {
			ll m = (l + r) / 2;
			if(ok(m)) r = m;
			else l = m + 1;
		}
		printf("%lld\n", l);
	}
}

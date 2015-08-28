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
ll p[12], k, t;
ll memo[12][2][2];
ll solve(int i, bool any, bool need) {
	if(i == k) return !(need && !any);
	ll &r = memo[i][any][need];
	if(r != -1) return r;
	ll e = p[i] / t; ll j;
	for(j = e - 2; j <= e + 2; j++) {
		if(j <= 0) continue;
		if((p[i] / j) == t) break;
	}
	r = solve(i + 1, any, need);
	if(j <= e + 2) {
		r = mod(r + solve(i + 1, true, true));
		r = mod(r + (p[i] - 1) * solve(i + 1, any, true));
	} else r = mod(r + p[i] * solve(i + 1, any, true));
	return r;
}

int main() {
	int i, j, tt = 0, n, m;
	while(true) {
		scanf("%d %d %lld", &n, &m, &t);
		if(!n) return 0;
		k = 0;
		for(i = 2; i * i <= n; i++) {
			if(n % i) continue;
			int ct = 0;
			while(!(n % i)) n /= i, ct++;
			p[k++] = ll(ct) * ll(m);
		}
		if(n > 1) p[k++] = m;
		memset(memo, -1, sizeof memo);
		printf("Case %d: %lld\n", ++tt, solve(0, false, false) - 1);
	}
}

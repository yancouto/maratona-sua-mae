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

ll n[2];
int x;
ll memo[2][70][2][70];

int pprec[70];
int prec(int nn) {
	if(nn == 1) return 0;
	if(pprec[nn] == -1) pprec[nn] = 1 + prec(__builtin_popcount(nn));
	return pprec[nn];
}

ll solve(int who, int i, int pre, int sum) {
	if(i == 61) return (prec(sum) + 1) == x;
	ll &m = memo[who][i][pre][sum];
	if(m != -1) return m;
	ll ans = 0;
	int dig = n[who] & (1ull << (60 - i));
	for(int d = 0; d <= 1; d++) {
		if(pre && d && !dig) continue;
		if(i < 60 || sum)
			ans += solve(who, i + 1, pre && (dig == d), sum + d);
		else
			ans += (x == 0);
	}
	return m = ans;
}

int main() {
	memset(memo, -1, sizeof memo);
	pprec[0] = pprec[1] = 0;
	while(42) {
		scanf("%lld %lld %d", &n[0], &n[1], &x);
		if((n[0] + n[1] + x) == 0) return 0;
		n[0]--;
		memset(memo, -1, sizeof memo);	
		ll ans = solve(1, 0, 1, 0) - solve(0, 0, 1, 0); 
		printf("%lld %lld %lld\n", ans, solve(1, 0, 1, 0), solve(0, 0, 1, 0));
	}
	return 0;
}

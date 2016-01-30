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


ll p, R;
ll memo[1000009];
ll solve(int n) {
	if(n <= 1) return 0;
	if(memo[n] != -1) return memo[n];
	ll r = LLONG_MAX;
	for(int i = 2; i <= n; i++)
		r = min(r, solve((n + i - 1) / i) + p * ll(i - 1));
	return memo[n] = r + R;
}


int main() {
	memset(memo, -1, sizeof memo);
	int n;
	scanf("%d %lld %lld", &n, &R, &p);
	printf("%lld\n", solve(n));
}

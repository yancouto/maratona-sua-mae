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
const int N = 509;
ll memo[N][N];
ll comb(int p, int n) {
	if(p < 0 || p > n) return 0;
	ll &r = memo[p][n];
	if(r != -1) return r;
	if(n == 0) return r = 1;
	return r = mod(comb(p - 1, n - 1) + comb(p, n - 1));
}
ll fat[N];

int main() {
	int i, j, n, k, p;
	memset(memo, -1, sizeof memo);
	fat[0] = 1;
	for(i = 1; i < N; i++)
		fat[i] = mod(fat[i - 1] * ll(i));
	for_tests(t, tt) {
		scanf("%d %d %d", &n, &k, &p);
		ll ans = 0;
		for(i = k; i < n - 1; i++)
			for(j = p + 1; j <= n; j++) {
				//printf("pos %d j = %d\nans += C(%d, %d) * (%d)! = %lld\n", i, j, i - k, j - 2, n - 2 - (i - k), comb(i - k, j - 2) * fat[n - 2 - (i - k)]);
				ans = mod(ans + comb(i - k, j - 2) * fat[n - 2 - (i - k)]);
			}
		ans = mod(ans + comb(n - k, n - 1) * fat[k - 1]);
		printf("Case #%d: %d\n", tt, int(ans));
	}
}

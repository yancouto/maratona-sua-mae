#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 1000000007
typedef unsigned long long ull;

using namespace std;

int N, K;

ull solve2 (int n, int k);

ull ret (ull n) {
	return ((n * (n-1)) / 2) % mod;
} 

ull memo[100005][55];
ull solve (int n, int k) {
	if (n == 1) return k == 0;
	if (n <= 0) return 0;
	if (n == 2) return k == 1;
	if (k == 0) return 0;
	ull &m = memo[n][k];
	if (m != -1) return m;
	ull ans = (((ret(n) * (n-1)) % mod) * (solve(n-2, k-1) % mod));
	ans = (ans + ((((ret(n) * (n-1)) % mod) * (n-2)) % mod ) * ((solve2(n, k)) % mod)) % mod;
	return m = ans;
}

ull memo2[100005][55];
ull solve2 (int n, int k) {
	ull &m = memo2[n][k];
	if (m != -1) return m;
	ull ans = ((n-2) * solve(n-3, k-1)) % mod;
	if (n > 3)
		ans = (ans + ((((n-2) * (n-3))/2) % mod) * (solve2(n-1, k)) % mod) % mod;
	return m = ans;
}

int main () {
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d %d", &N, &K);
		memset(memo, -1, sizeof memo);
		memset(memo2, -1, sizeof memo2);
		printf("Case %d: %lld\n", tt, solve(N, K));
	}
	return 0;
}

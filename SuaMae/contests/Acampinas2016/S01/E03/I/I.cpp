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

//ll fexp(ll n, ll p) {
//	ll r = 1;
//	for(; p; p >>= 1) {
//		if(p & 1) r = mod(r * n);
//		n = mod(n * n);
//	}
//	return r;
//}
//
//inline ll inv(ll x) { return fexp(x, modn - 2); }
//
//ll fat[5009];
int c[5002], ct[5002], acc[5002];
//inline ll comb(int n, int p) {
//	if(p > n || p < 0 || n < 0) return 0;
//	return mod(fat[n] * inv(mod(fat[p] * fat[n - p])));
//}
int memo[5002][2502];
ll comb(int n, int p) {
	if(p > n || p < 0 || n < 0) return 0;
	if(n == 0) return 1;
	if(p > n / 2) return comb(n, n - p);
	if(memo[n][p] != -1) return memo[n][p];
	return memo[n][p] = (int) mod(comb(n - 1, p) + comb(n - 1, p - 1));
}

int main() {
	int i, n, t, k, T, left, right;
	//fat[0] = 1;
	//for(i = 1; i <= 5009; i++)
	//	fat[i] = mod(ll(i) * fat[i - 1]);
	memset(memo, -1, sizeof memo);
	scanf("%d %d", &n, &T);
	for(i = 0; i < n; i++) scanf("%d", &c[i]);
	for(i = 0; i < n; i++) ct[c[i]]++;
	scanf("%d %d", &k, &t); k = c[k - 1]; t--;
	int v = ct[k]--;
	for(i = 1; i <= 5000; i++) acc[i] = acc[i - 1] + ct[i];
	ll tot = 0;
	for(left = 0; left <= ct[k] && left <= t; left++)
		for(right = 0; right + left <= ct[k] && right <= T - t - 1; right++) {
			ll pos = comb(ct[k], left + right);
			pos = mod(mod(pos * comb(acc[k - 1], t - left)) * comb(acc[5000] - acc[k], T - t - 1 - right));
			tot = mod(tot + pos);
		}
	printf("%d\n", int(tot));
}

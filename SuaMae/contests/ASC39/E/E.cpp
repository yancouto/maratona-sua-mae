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

ll memo2[502][502];
ll f(int k, int q) {
	if(k == 0) return 1;
	ll &r = memo2[k][q];
	if(r != -1) return r;
	r = 0;
	for(int i = 1; i <= q && i <= k; i++)
		r += f(k - i, i);
	return r;
}

ll memo[4][510];
ll solve(int i, int k) {
	if(i == 3) return f(k, k);
	ll &r = memo[i][k];
	if(r != -1) return r;
	r = 0;
	for(int v = 0; v <= k; v++)
		r += mod(f(v, v) * solve(i + 1, k - v));
	return r = mod(r);
}

int main() {
	freopen("expedition.in", "r", stdin);
	freopen("expedition.out", "w", stdout);
	int x, i;
	scanf("%d", &x);
	int mx = INT_MAX; ll tot = 0;
	memset(memo, -1, sizeof memo);
	memset(memo2, -1, sizeof memo2);
	for(i = 1; i <= x; i++) {
		int s = (x + i - 1) / i;
		int out = 2 * s + 2 * i;
		if(out < mx) mx = out, tot = 0;
		if(out > mx) continue;
		int k = (i - (x % i)) % i;
		tot += solve(0, k);
	}
	printf("%d\n", (int) mod(tot));
}

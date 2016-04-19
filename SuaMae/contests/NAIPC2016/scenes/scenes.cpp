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

int n, h, w;

ll memo[112][10009];
ll solve(int w, int n) {
	if(w == 0) return 1;
	ll &r = memo[w][n];
	if(r != -1) return r;
	r = 0;
	for(int i = 0; i <= n && i <= h; i++)
		r += solve(w - 1, n - i);
	return r = mod(r);
}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d %d %d", &n, &w, &h);
	ll a = solve(w, n);
	ll eq = min(n / w, h);
	printf("%d\n", (int) mod(a - eq - 1 + modn));
}

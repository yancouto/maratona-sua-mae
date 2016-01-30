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

int main() {
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	ll k;
	scanf("%lld", &k); k += 2;
	if(k & 1) { puts("0"); return 0; }
	ll g = k;
	for(ll i = 2; i * i <= k; i++) {
		if(k % i) continue;
		do k /= i; while((k % i) == 0);
		g = (g / i) * (i - 1);
	}
	if(k > 1) g = (g / k) * (k - 1);
	printf("%lld\n", g);
}

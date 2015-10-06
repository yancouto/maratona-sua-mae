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
	ll n; scanf("%lld", &n);
	ll ans = 1, pot = 1;
	for(int i = 0; i < n; i++)
		pot = mod(pot * 27), ans = mod(ans * 7);
	printf("%lld\n", mod(pot - ans + modn));
	return 0;
}

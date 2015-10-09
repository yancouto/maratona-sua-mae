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

ll bs(ll l, ll r, ll v) {
	if(l >= r) return l;
	ll mid = (l + r + 1) / 2;
	if((mid*(mid+1))/2 > v) return bs(l, mid - 1, v);
	return bs(mid, r, v);
}

int main() {
	for_tests(t, tt) {
		ll n; scanf("%lld", &n);
		ll a = (-1 + sqrt(8 * n + 1)) / 2;
		printf("%lld\n", a);
		//printf("%lld\n", bs(0ll, sqrt(2 * n+1), n));	
	}
	return 0;
}

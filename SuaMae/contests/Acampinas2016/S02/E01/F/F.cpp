#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ll n; int k;

pii sim(ll x) {
	ll H = 1, W = n, h = 1;
	for(int i = 0; i < k; i++) {
		if(x < W / 4ll) x = W / 2ll - x - 1, h = 2ll * H - h + 1ll;
		else if(x >= 3ll * W / 4ll) x = 3ll * W / 2ll - x - 1ll, h = 2ll * H - h + 1ll;
		x -= W / 4ll;
		H = 2ll * H; W = W / 2ll;
	}
	return pii(h, x);
}

int main() {
	freopen("scarf.in", "r", stdin);
	freopen("scarf.out", "w", stdout);
	int i, q; ll x;
	scanf("%lld %d %d", &n, &k, &q);
	for(i = 0; i < q; i++) {
		scanf("%lld", &x); x--;
		pii p = sim(x);
		printf("%lld %lld\n", p.fst, p.snd + 1);
	}
}

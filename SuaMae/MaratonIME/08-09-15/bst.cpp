#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000003;
inline ll mod(ull x) { return x % modn; }

struct bst {
	int fl, fr;
	int nl, nr;
	int v;
	void reset() { fl = fr = -1; nl = nr = 0; }
} bs[1009];
int bn;

void ins(int v, int x) {
	if(x < bs[v].v) {
		if(bs[v].fl == -1) {
			bs[bn].v = x;
			bs[bn].reset();
			bs[v].fl = bn++;
		} else ins(bs[v].fl, x);
		bs[v].nl++;
	} else {
		if(bs[v].fr == -1) {
			bs[bn].v = x;
			bs[bn].reset();
			bs[v].fr = bn++;
		} else ins(bs[v].fr, x);
		bs[v].nr++;
	}
}

ll fat[1003];
void pre() {
	fat[0] = 1;
	for(int i = 1; i < 1003; i++)
		fat[i] = mod(fat[i-1] * ll(i));
}

ll fexp(ll x, ll p) {
	ll resp = 1;
	for(ll i = 1; i <= p; i <<= 1) {
		if(i & p) resp = mod(resp * x);
		x = mod(x * x);
	}
	return resp;
}

ll memo[1009];
ll solve(int u) {
	if(u == -1) return 1ll;
	ll &r = memo[u];
	if(r != -1) return r;
	r = mod(mod(fat[bs[u].nl + bs[u].nr] * fexp(fat[bs[u].nl], modn - 2)) * fexp(fat[bs[u].nr], modn - 2));
	r = mod(mod(r * solve(bs[u].fl)) * solve(bs[u].fr));
	//printf("%lld * %lld * %lld\n", fat[bs[u].nl + bs[u].nr], fexp(fat[bs[u].nl], modn - 2), fexp(fat[bs[u].nr], modn - 2));
	//printf("%d->%d, %d = %lld\n", u, bs[u].nl, bs[u].nr, r);
	return r;
}

ll comb(ll n, ll p) {
	return mod(fat[n] * fexp(mod(fat[p] * fat[n - p]), modn - 2));
}

int main() {
	pre();
	int i, n, m, x;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		scanf("%d", &bs[0].v); bn = 1;
		bs[0].reset();
		for(i = 1; i < n; i++) {
			scanf("%d", &x);
			ins(0, x);
		}
		memset(memo, -1, sizeof memo);
		printf("%lld\n", mod(solve(0) * comb(m, n)));
	}
}

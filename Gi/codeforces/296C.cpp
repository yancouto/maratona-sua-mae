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
const int N = 100010;

ll n, m, k, a, b;
ll l[N], r[N], d[N];
ll bitop[N], bitv[N];
ll v[N];

void update(ll bit[N], ll p, ll x, ll nn) {
	for(ll i = p; i <= nn; i += i&(-i))
		bit[i] += x;
}

ll get(ll bit[N], ll p) {
	ll ret = 0;
	for(ll i = p; i > 0; i -= i&(-i))
		ret += bit[i];
	return ret;
}

int main() {
	ll i;
	scanf("%lld %lld %lld", &n, &m, &k);
	for(i = 0; i < n; i++) scanf("%lld", &v[i]);
	for(i = 0; i < m; i++) scanf("%lld %lld %lld", &l[i], &r[i], &d[i]);
	for(i = 0; i < k; i++) {
		scanf("%lld %lld", &a, &b);
		update(bitop, a, 1, m);
		update(bitop, b + 1, -1, m);
	}
	for(i = 0; i < m; i++) {
		ll val = d[i] * get(bitop, i + 1);
		update(bitv, l[i], val, n);
		update(bitv, r[i] + 1, -val, n); 
	}
	for(i = 0; i < n; i++) 
		printf("%lld ", v[i] + get(bitv, i + 1));
	putchar('\n');
	return 0;
}

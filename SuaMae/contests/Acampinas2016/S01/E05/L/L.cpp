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
const int N = 1000007;

int n;
ll bit[N], mp[N], a[N];

ll get(int p) {
	ll ret = 0;
	for(int i = p + 2; i; i -= i&(-i))
		ret += bit[i];
	return ret;
}

void update(int p, int val) {
	for(int i = p + 2; i < N; i += i&(-i))
		bit[i] += (ll)val;
}

int main() {
	int i, x;
	scanf("%d", &n);
	ll ans = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mp[i] = a[i];
	}
	sort(mp, mp + n);
	for(i = 0; i < n; i++) 
		a[i] = lower_bound(mp, mp + n, a[i]) - mp;
	for(i = 0; i < n; i++) {
		x = a[i];
		ans += get(n) - get(x);
		update(x, 1);
	}
	printf("%lld\n", ans);
	return 0;
}

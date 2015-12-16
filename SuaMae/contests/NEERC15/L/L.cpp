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
const int N = 100009;
ll h[N], acc[N], al[N], ar[N];
int n;
ll bl(ll i, ll x) {
	if(x - (i - 1) > h[1]) return LLONG_MAX;
	if(x - (n - i) > h[n]) return LLONG_MAX;
	//printf("[%d] to %I64d\n", (int)i, x);
	ll tot = x - h[i];
	//printf("initial cost %I64d\n", tot);
	ll l = 1, r = i - 1;
	while(l < r) {
		ll m = (l + r + 1) / 2;
		if(al[m] >= (x - (i - m))) l = m;
		else r = m - 1;
	}
	ll col = (x - (i - l)) + 1;
	if(l != i - 1) tot += ((col + x - 1ll) * (x - col)) / 2 - (acc[i - 1] - acc[l]);
	//printf("after left %I64d [collided %I64d]\n", tot, l);
	l = i + 1; r = n;
	while(l < r) {
		ll m = (l + r) / 2;
		if(ar[m] >= (x - (m - i))) r = m;
		else l = m + 1;
	}
	col = (x - (l - i)) + 1;
	if(l != i + 1) tot += ((col + x - 1ll) * (x - col)) / 2 - (acc[l - 1] - acc[i]);
	//printf("after right %I64d [collided %I64d]\n", tot, l);
	//printf("[%d] to %I64d cost = %I64d\n", (int)i, x, tot);
	//puts("-------------------------");
	return tot;
}

int main() {
	freopen("landscape.in", "r", stdin);
	freopen("landscape.out", "w", stdout);
	ll b; int i;
	scanf("%d %I64d", &n, &b);
	for(i = 1; i <= n; i++) {
		scanf("%I64d", &h[i]);
		acc[i] = acc[i - 1] + ll(h[i]);
	}
	for(i = n; i >= 1; i--)
		al[i] = max(h[i], al[i + 1] - 1);
	for(i = 1; i <= n; i++)
		ar[i] = max(h[i], ar[i - 1] - 1);
	ll best = 0;
	for(i = 1; i <= n; i++) {
		ll l = 0, r = 2200000000;
		while(l < r) {
			ll m = (l + r + 1) / 2;
			if(bl(i, m + ll(h[i])) <= b) l = m;
			else r = m - 1;
		}
		best = max(best, l + ll(h[i]));
	}
	printf("%I64d\n", best);
}

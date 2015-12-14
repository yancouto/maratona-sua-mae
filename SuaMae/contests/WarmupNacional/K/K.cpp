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
int a[N], b[N], sz, mn[N], mx[N];
ll memo[N][2];
ll solve(int nu, bool ri) {
	if(nu == sz - 1) return 0;
	ll &r = memo[nu][ri];
	int i = ri? mx[nu] : mn[nu];
	if(r != -1) return r;
	if(mn[nu + 1] >= i) return r = solve(nu + 1, true) + mx[nu + 1] - i;
	if(mx[nu + 1] <= i) return r = solve(nu + 1, false) + i - mn[nu + 1];
	return r = min(solve(nu + 1, true) + i - mn[nu + 1],
	               solve(nu + 1, false) + mx[nu + 1] - i) + mx[nu + 1] - mn[nu + 1];
}

int main() {
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	sz = unique(b, b + n) - b;
	for(i = 0; i < sz; i++)
		mn[i] = INT_MAX, mx[i] = -1;
	for(i = 0; i < n; i++) {
		a[i] = lower_bound(b, b + sz, a[i]) - b;
		mn[a[i]] = min(mn[a[i]], i);
		mx[a[i]] = max(mx[a[i]], i);
	}
	memset(memo, -1, sizeof memo);
	printf("%lld\n", solve(0, true) + n + mx[0]);
}

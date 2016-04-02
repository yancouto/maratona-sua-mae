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
const int N = 2123;

ll p[N];
int n;
ll solve(int l, int r, int x, int q) {
	if(l >= r - 1) return p[n - 1 - q];
	if(r - l == 2) return p[n - 1 - q] + (n - x) * p[n - 2 - q];
	int m = (l + r) / 2;
	ll a = solve(m, r, x, q + 1);
	ll b = solve(l, m, x, q + 1);
	return ll(x) * a + ll(n - x) * b;
}


int main() {
	scanf("%d", &n);
	p[0] = 1;
	for(int i = 1; i <= n; i++)
		p[i] = p[i - 1] * ll(n);
	ll val = 0;
	for(int i = 1; i <= n; i++)
		val += solve(0, n, i, 0);
	printf("%lld\n", val);
}

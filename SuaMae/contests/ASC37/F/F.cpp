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
const int N = 500;
int a[N], n[N], k;

ll c[N][N], m[N][N];
ll comb(int n, int p) {
	if(n < 0 || p < 0 || p > n) return 0;
	if(n == 0) return 1;
	ll &r = c[n][p];
	if(r == -1) r = mod(comb(n - 1, p - 1) + comb(n - 1, p));
	return r;
}

int main() {
	freopen("monotonic.in", "r", stdin);
	freopen("monotonic.out", "w", stdout);
	memset(c, -1, sizeof c);
	int i, j, mn;
	scanf("%*d %d", &k);
	for(i = 0; i < k; i++)
		scanf("%d", &a[i]);
	for(i = k - 1; i >= 0; i--)
		n[i] = n[i + 1] + a[i];
	for(i = 0; i <= n[0]; i++) m[k][i] = 1;
	for(i = k - 1; i >= 0; i--)
		for(mn = 0; mn < n[i]; mn++)
			for(j = 0; j <= n[i + 1]; j++)
				m[i][mn] = mod(m[i][mn] + mod(comb(n[i] - j - 1, a[i] - 1) - comb(mn - j - 1, a[i] - 1) + modn) * m[i + 1][j]);
	printf("%d\n", (int) m[0][0]);
}

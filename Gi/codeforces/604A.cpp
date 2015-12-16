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
	int m[5], w[5], hu, hs;
	int x[5] = {500, 1000, 1500, 2000, 2500};
	int n, i, j;
	double ans = 0;
	n = 5;
	for(i = 0; i < n; i++) scanf("%d", &m[i]);
	for(i = 0; i < n; i++) scanf("%d", &w[i]);
	scanf("%d %d", &hs, &hu);
	for(i = 0; i < n; i++) ans += max(0.3 * x[i], (1.0 - m[i]/250.0) * 1.0 * x[i] - 50.0 * w[i]);
	printf("%.0f\n", max(ans + 100.0 * hs  - 50.0 * hu, 0.0));
	return 0;
}

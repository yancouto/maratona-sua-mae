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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int v[100005], f[100005];

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);
	f[0] = 1;
	for(int i = 1; i < n; i++) f[i] = min(f[i-1] + 1, v[i]);
	f[n-1] = 1;
	for(int i = n - 2; i >= 0; i--) f[i] = min(f[i+1] + 1, f[i]);
	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}

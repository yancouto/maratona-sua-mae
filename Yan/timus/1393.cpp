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
	scanf("%d %s", &n, s + 1);
	memmove(s + 1 + n, s + 1, n);
	h[0] = 0; pot[0] = 1;
	for(i = 1; i <= 2 * n; i++) {
		h[i] = mod(h[i - 1] * 263ll + s[i]);
		pot[i] = mod(pot[i - 1] * 263ll);
	}
	for(i = 1; i <= n; i++)
		p[i] = i;
	sort(p + 1, p + 1 + n, [](int i, int j) {
		int a = lcp(i, j);
		return s[i + a] < s[j + a];
	});
}

// TLE
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

int x[1000009], y[1000009], p[1000009];
const ll mx = 2500000000ll;
int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		p[i] = i;
	}
	while(true) {
		random_shuffle(p, p + n);
		ll d = 0;
		for(i = 0; d <= mx && i < n - 1; i++)
			d += abs(x[p[i]] - x[p[i+1]]) + abs(y[p[i]] - y[p[i+1]]);
		if(d <= mx) {
			for(i = 0; i < n; i++)
				printf("%d ", p[i] + 1);
			putchar('\n');
			return 0;
		}
	}
}

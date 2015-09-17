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

bool myf(int a, int b) { return a > b; }

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int v[20005];
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++) 
			scanf("%d", &v[i]);
		sort(v, v + n, myf);
		ll ans = 0;
		for(int i = 2; i < n; i += 3)
			ans += v[i];
		printf("%lld\n", ans);
	}

	return 0;
}

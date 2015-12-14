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

ull v(ull x) {
	if(x == 1) return 0;
	if(x % 2) return v(x/2);
	else return x / 2;
}

int main() {
	int n, i; ull x;
	for_tests(t, tt) {
		scanf("%d", &n);
		ull m = 0;
		for(i = 0; i < n; i++) {
			scanf("%llu", &x);
			m ^= v(x);
		}
		if(m == 0) puts("NO");
		else puts("YES");
	}
}

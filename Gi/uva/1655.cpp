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

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int sz, n; scanf("%d %d", &sz, &n);
		int v[1000005];
		for(int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		sort(v, v + n);
		int e = -1, l, i;
		for(i = 0; i < n; i++) {
			if(v[i] >= sz / 2) break;
		}
		if(i < n) e = sz - v[i];
		if(i > 0) e = max(e, v[i-1]);
		l = max(sz - v[0], v[n-1]);
		printf("%d %d\n", e, l);
	}
	return 0;
}

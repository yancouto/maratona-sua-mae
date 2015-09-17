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
	while(42) {
		int k; scanf("%d", &k);
		if(!k) break;
		int n, m; scanf("%d %d", &n, &m);
		for(int i = 0; i < k; i++) {
			int x, y; scanf("%d %d", &x, &y);
			if(x == n || y == m) puts("divisa");
			else if(x > n && y > m) puts("NE");
			else if(x > n && y < m) puts("SE");
			else if(x < n && y > m) puts("NO");
			else puts("SO");
		}
	}
	return 0;
}

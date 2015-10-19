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
	int n, k, v, c;
	scanf("%d %d", &n, &k);
	v = c = 0;
	for(int i = 0; i < k; i++) {
		scanf("%d", &v);
		c += v;
		c = max(c - n, 0);
	}
	printf("%d\n", c);
	return 0;
}

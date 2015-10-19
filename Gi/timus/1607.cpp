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
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ans;
	if(c <= a) { printf("%d\n", a); return 0; }
	while(42) {
		a = a + b;
		if(c <= a) { ans = c; break; }
		c = max(c - d, 0);
		if(a >= c) { ans = a;  break; }
	}
	printf("%d\n", ans);
	return 0;
}

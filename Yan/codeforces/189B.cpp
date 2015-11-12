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
	int w, h, i, j;
	scanf("%d %d", &w, &h);
	ll tot = 0;
	for(i = 1; 2*i <= w; i++)
		for(j = 1; 2*j <= h; j++)
			tot += ll(w - 2*i + 1) * ll(h - 2*j + 1);
	printf("%I64d\n", tot);
}

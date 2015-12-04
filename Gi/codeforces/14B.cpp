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

int d[1005];

int main() {
	int n, x0, i, k, b, e;
	scanf("%d %d", &n, &x0);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &b, &e);
		if(b > e) swap(b, e);
		for(k = b; k <= e; k++)
			d[k]++;
	}
	int ans = 10000000;
	for(i = 1000; i >= 0; i--)
		if(d[i] == n) ans = min(ans, abs(x0 - i));
	if(ans == 10000000) ans = -1;
	printf("%d\n", ans);
	//xablau
	return 0;
}

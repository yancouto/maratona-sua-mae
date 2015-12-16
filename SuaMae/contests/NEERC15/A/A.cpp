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

int seen[2][1000009];
int us[2]; ll val[2];
int main() {
	freopen("adjustment.in", "r", stdin);
	freopen("adjustment.out", "w", stdout);
	int i, n, q, x; char c;
	scanf("%d %d", &n, &q);
	for(i = 0; i < q; i++) {
		scanf(" %c %d", &c, &x);
		int ind = (c == 'C');
		if(seen[ind][x]) { puts("0"); continue; }
		seen[ind][x] = 1;		
		us[ind]++;
		val[ind] += x;
		ll tot = ll(n) * ll(x) + (ll(n) * ll(n + 1)) / 2ll;
		tot -= ll(us[!ind]) * ll(x) + ll(val[!ind]);
		pstdoustdout("%I64d\n", tot);
	}
}

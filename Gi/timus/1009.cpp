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

int n, k;
ll memo[20][2];

ll solve(int i, int lst) {
	if(i == n) return 1;
	ll &m = memo[i][lst];
	if(m != -1) return m;
	m = 0;
	for(int dig = 0; dig < k; dig++) {
		if(lst && !dig) continue;
		m += solve(i + 1, !dig);
	}
	return m;
}

int main() {
	scanf("%d %d", &n, &k);
	memset(memo, -1, sizeof memo);		
	printf("%lld\n", solve(0, 1));
	return 0;
}

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

int n;
ll memo[50][5];

ll solve(int i, int lst) {
	if(i == n) return 1;
	ll &m = memo[i][lst];
	if(m != -1) return m;
	m = 0;
	for(int c = 1; c <= 3; c++) {
		if(c == lst) continue;
		if(c == 2 && (i == 0 || i == n-1)) continue;
		if(c == 2) m += solve(i + 2, (lst == 1) ? 3 : 1);
		else m += solve(i + 1, c);
	}
	return m;
}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d", &n);
	printf("%lld\n", solve(0, 0));
	return 0;
}

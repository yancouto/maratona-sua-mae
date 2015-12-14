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

ll memo[65][65];
ll solve(int left, int open) {
	if(left == 0) return 1;
	ll &r = memo[left][open];
	if(r != -1) return r;
	r = solve(left - 1, open + 1);
	if(open) r += solve(left, open - 1);
	return r;
}

int main() {
	int n;
	scanf("%d", &n);
	memset(memo, -1, sizeof memo);
	printf("%lld\n", solve(n, 0));
}

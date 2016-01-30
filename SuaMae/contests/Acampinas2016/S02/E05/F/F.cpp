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

ll memo[1009][10][2][2];
ll solve(int l, int s, bool lO, bool fO) {
	if(s > 5) return 0;
	if(l == 0) return s == 4;
	ll &r = memo[l][s + 1][lO][fO];
	if(r != -1) return r;
	r = solve(l - 1, s + 1, false, fO);
	if(!lO && (l != 1 || !fO)) r += solve(l - 1, s - 1, true, fO);
	return r;
}

int main() {
	int l, tt = 0;
	memset(memo, -1, sizeof memo);
	while(scanf("%d", &l) != EOF && l) {
		printf("Case %d: %lld\n", ++tt, solve(l - 1, 1, false, false) + solve(l - 1, -1, true, true));
	}
}

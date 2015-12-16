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
	ll n, k;
	cin >> n >> k;
	if(n == 1) { puts("0"); return 0; }
	if(k >= n) { puts("1"); return 0; }
	ll tot = k * (k + 1) / 2 - 1 - (k - 2);
	if(tot < n) { puts("-1"); return 0; }
	ll l = 1, r = k + 1;
	k--; n--;
	while(l + 1 < r) {
		ll m = (l + r) / 2;
		if((k + m) * (k - m + 1) / 2 >= n) l = m;
		else r = m;
	}
	cout << k + 1 - l << '\n';
	return 0;
}

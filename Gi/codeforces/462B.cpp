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

int n, k, i, j;
char c;
int v[100005];

int main() {
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) {
		scanf(" %c", &c);
		v[c-'A']++;
	}
	sort(v, v + 26);
	ll ans = 0;
	for(i = 25; i >= 0 && k; i--) {
		if(v[i] <= k) { ans += ll(v[i]) * ll(v[i]); k -= v[i]; }
		else { ans += (ll) k * (ll)k; k = 0; } 
	}
	printf("%lld\n", ans);
	return 0;
}

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
	for_tests(t, tt) {
		ll n1, n2, m;
		scanf("%lld %lld %lld", &n1, &n2, &m);
		if(n1 > n2) swap(n1, n2);
		ll sum = m * (m + 1) / 2;
		if(sum <= n1) printf("%lld\n", n1 - sum + n2 - sum);
		else printf("%lld\n", n2 - n1);
	}
	return 0;
}

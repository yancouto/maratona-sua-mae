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

int n;
int a[300005];

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n); ll ans = 0;
	for(i = 0; i < n-1; i++) 
		ans += (ll)a[i] * (ll)(i + 2);
	printf("%lld\n", ans + (ll)a[n-1] * (ll)(n));
	return 0;
}

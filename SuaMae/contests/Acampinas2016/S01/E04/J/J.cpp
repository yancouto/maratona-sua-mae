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

ll tot = 0;
ll N;
void proc(ll n) {
	ll k = N / (n + 1);
	for(ll i = 1; i * i <= n; i++) {
		if(n % i) continue;
		if(N % ((N - k) / i) == k) tot++;
		if(i * i != n && (N % ((N - k) / (n / i))) == k) tot++;
	}
}

int main() {
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);
	ll n, i;
	scanf("%lld", &n);
	N = n;
	for(i = 1; i * i <= n; i++) {
		if(n % i) continue;
		proc(i - 1);
		tot++;
		if(i * i != n) proc((n / i) - 1), tot++;
	}
	printf("%lld\n", tot);
}

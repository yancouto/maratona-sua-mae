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
	ll b;
	scanf("%lld", &b);
	deque<ll> v1, v2;
	for(ll i = 1; i * i <= b - 1; i++)
		if(!((b - 1) % i)) {
			v1.pb(i);
			if(i * i != b - 1) v2.push_front((b - 1) / i);
		}
	for(int x : v1) printf("%d ", x);
	for(int x : v2) printf("%d ", x);
	putchar('\n');
}

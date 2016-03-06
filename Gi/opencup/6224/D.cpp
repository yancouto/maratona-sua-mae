#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int MAX = 26;

int N;
ll v[MAX];
map<int, ll> mp;

inline int half(int n) { return n/2 + (n%2); }

void go(ll a, ll b) {
	if(mp.count(a-b)) mp[a-b] = max(mp[a-b], a); 
	else mp[a-b] = a;
}

void solve(int i, ll a, ll b) {
	if(i == half(N)) { go(a, b); return; }
	solve(i + 1, a + v[i], b);
	solve(i + 1, a, b + v[i]);
	solve(i + 1, a, b);
}

ll go2(ll a, ll b) {
	if(mp.count(a-b)) return b + mp[a-b];
	return 0;
}

ll solve2(int i, ll a, ll b) {
	if(i == N) return go2(a, b);
	ll ret = solve2(i + 1, a + v[i], b);
	ret = max(ret, solve2(i + 1, a, b + v[i]));
	ret = max(ret, solve2(i + 1, a, b));
	return ret;
}

int main() {
	int i, j;
	while(42) {
		scanf("%d", &N);
		if(!N) break;
		ll tot = 0;
		for(i = 0; i < N; i++) 
			scanf("%lld", &v[i]),	tot += v[i];
		mp.clear();
		solve(0, 0, 0);
		printf("%lld\n", tot - solve2(half(N), 0, 0)*2);
	}
	return 0;
}

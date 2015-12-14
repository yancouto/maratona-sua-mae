#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int S = 400;

int n;
pii v[45];
ll memo[45][900][900];

ll solve(int i, int x, int y) {
	if(i == n) return 0ll;
	ll &m = memo[i][x+S][y+S];
	if(m != -1) return m;
	m = solve(i+1, x, y);
	m += (!(x+v[i].x) && !(y+v[i].y)) + solve(i + 1, x + v[i].x, y + v[i].y);
	return m;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &v[i].x, &v[i].y);
	memset(memo, -1, sizeof memo);
	printf("%lld\n", solve(0, 0, 0));
	return 0;
}

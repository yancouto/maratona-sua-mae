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

ll v[20];
int mat[20][20];
int n, m, k;
ll memo[19][300000];

ll mmax(ll a, ll b) { if(a > b) return a; return b; }

ll solve(int lst, int mask) {
	if(__builtin_popcount(mask) == m) return 0;
	ll &mem = memo[lst][mask];
	if(mem != -1) return mem;
	mem = 0;
	for(int i = 0; i < n; i++) {
		if(mask & (1 << i)) continue;
		mem = mmax(mem, v[i] + mat[lst][i] + solve(i, mask | (1 << i)));
	}
	return mem;
}

int main() {
	int a, b, c; 
	memset(memo, -1, sizeof memo);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for(int i = 0; i < k; i++) {
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		mat[a][b] = c;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) 
		ans = mmax(ans, v[i] + solve(i, (1 << i)));
	printf("%lld\n", ans);
	return 0;
}

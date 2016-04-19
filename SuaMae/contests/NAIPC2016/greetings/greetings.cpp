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
#define c1 __builtin_popcount
string bit(int msk) { return bitset<5>(msk).to_string(); }

int n;
ll memo[16][1 << 15];
ll W[1 << 15];
ll rec(int i, int cur, int msk, int k) {
	if(i == n)
		return memo[k - 1][msk ^ cur] + W[cur];
	ll v = rec(i + 1, cur, msk, k);
	if(((msk >> i) & 1) && c1(msk ^ cur) >= k)
		v = min(v, rec(i + 1, cur | (1 << i), msk, k));
	return v;
}


int w[20], h[20], q[20];
int main() {
	int i, j, K, msk, k;
	scanf("%d %d", &n, &K);
	if(K >= n) { puts("0"); return 0; }
	for(i = 0; i < n; i++) {
		scanf("%d %d %d", &w[i], &h[i], &q[i]);
		//w[i] = (rand() % 10000);
		//h[i] = (rand() % 10000);
		//q[i] = (rand() % 10000);
	}
	for(i = 0; i < (1 << n); i++) {
		ll tw = 0;
		int W = 0, H = 0;
		for(j = 0; j < n; j++)
			if((i >> j) & 1)
				W = max(W, w[j]),
				H = max(H, h[j]);
		for(j = 0; j < n; j++)
			if((i >> j) & 1)
				tw += ll(q[j]) * ll((W * H) - w[j] * h[j]);
		::W[i] = tw;
	}
	for(msk = 1; msk < (1 << n); msk++)
		memo[0][msk] = 1e14;
	for(k = 1; k < K; k++)
		for(msk = 0; msk < (1 << n); msk++) {
			if(c1(msk) <= k) continue;
			memo[k][msk] = rec(0, 0, msk, k);
		}
	printf("%lld\n", rec(0, 0, (1 << n) - 1, K));
}

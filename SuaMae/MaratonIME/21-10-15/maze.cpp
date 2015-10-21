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

ll memo[10][1 << 8][64][10];
ll solve(int left, int bm, int k, int n) {
	if(left == 0) return bm & 1;
	ll &r = memo[left][bm][k][n];
	if(r != -1) return r;
	//printf("solve(%d, %d, %d)\n", left, bm, k);
	r = 0;
	for(int i = 0; i < (1 << n); i++) {
		if(__builtin_popcount(i) > k) continue;
		int bm2 = bm | i;
		for(int j = n - 2; j >= 0; j--)
			if(!(i & (1 << j)) && !(bm2 & (1 << (j + 1))) && (bm2 & (1 << j)))
				bm2 ^= (1 << j);
		//printf("i %s\nb %s\n", bitset<8>(i).to_string().c_str(), bitset<8>(bm2).to_string().c_str());
		r = mod(r + solve(left - 1, bm2, k - __builtin_popcount(i), n));
	}
	//printf("solve(%d, %d, %d) = %d\n", left, bm, k, r);
	return r;
}

int main() {
	int m, k, n;
	memset(memo, -1, sizeof memo);
	for_tests(t, tt) {
		scanf("%d %d %d", &n, &m, &k);
		printf("Case #%d: %d\n", tt, (int)solve(m, (1 << (n - 1)) - 1, k, n));
	}
}

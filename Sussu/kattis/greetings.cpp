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

int n, k;

ll w[16], h[16], q[16], W[(1<<15)], dp[(1<<15)][16];

ll go(int i, int atu, int bm, int k){
	if(i == n) return W[atu] + dp[bm^atu][k-1];
	ll ans = 1e14;
	ans = min(ans, go(i+1, atu, bm, k));
	if((bm>>i)&1 && __builtin_popcount(bm^atu) > k-1){
		ans = min(ans, go(i+1, atu|(1<<i), bm, k));
	}
	return ans;
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%lld%lld%lld", &w[a], &h[a], &q[a]);
	}
	for(int kk = 0; kk <= k; kk++){
		for(int bm=0;bm<(1<<n);bm++){
			dp[bm][kk] = 1e14;
		}
	}
	for(int a=0;a<(1<<n);a++){
		ll wm=0, hm=0;
		for(int i=0;i<n;i++){
			if((a>>i)&1){
				wm = max(wm, w[i]);
				hm = max(hm, h[i]);
			}
		}
		for(int i=0;i<n;i++){
			if((a>>i)&1){
				W[a] += q[i]*(wm*hm - w[i]*h[i]);
				dp[a][1] = W[a];
			}
		}

	}
	
	for(int kk = 2; kk <= k; kk++){
		for(int bm=0;bm<(1<<n);bm++){
			dp[bm][kk] = go(0, 0, bm, kk);
			//printf("dp[%d][%d] %lld\n", bm, kk, dp[bm][kk]);
		}
	}
	printf("%lld\n", dp[(1<<n)-1][k]);
}
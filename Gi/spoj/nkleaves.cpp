#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100009;
const ll oo = 1000000000000000;

ll dp[N][12];
ll sm[N], v[N], tot;
vector<pii> st;

ll xcont(int i, int j, int k) {
	ll v1 = i * sm[i] - j * sm[j];
	ll v2 = dp[i][k-1] - dp[j][k-1];
	ll v3 = sm[i] - sm[j];
	return (ll) ceil((double)(v1 + v2) / (double)v3);
}

int main() {
	int i, j, n, k, K;

	scanf("%d %d", &n, &K);
	for(i = 1; i <= n; i++)	scanf("%lld", &v[i]), tot += v[i] * (i - 1);
	for(i = n; i >= 1; i--)	sm[i] = sm[i+1] + v[i];	
	for(k = 2; k <= K; k++) {
		st.clear();
		st.pb(pii(oo, n));
		for(i = n - 1; i; i--) {
			int l = 0, r = st.size() - 1;
			while(l < r) {
				int m = (l + r + 1) / 2;
				if(st[m].fst > i) l = m;
				else r = m - 1;
			}
			int j = st[l].snd;
			dp[i][k] = (j - i) * sm[j] + dp[j][k-1];
			while(!st.empty() && xcont(st.back().snd, i, k) >= st.back().fst) 
				st.pop_back();
		 	st.pb(pii(xcont(st.back().snd, i, k), i));
		}
	}
	printf("%lld\n", tot - dp[1][K]);
	return 0;
}

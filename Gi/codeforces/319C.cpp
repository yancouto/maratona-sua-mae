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
const ll oo = 100000000000000000;

ll a[N], b[N], dp[N];
vector<pii> st;

ll xcont(int i, int j) {
	ll ret = (ll) ceil((double)(dp[i]-dp[j]) / (double)(b[j]-b[i]));
	return ret;
}

int main() {
	int n, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) cin >> a[i];
	for(i = 1; i <= n; i++) cin >> b[i];
	dp[0] = 0;
	st.pb(pii(-oo, 0));
	for(i = 1; i <= n; i++) {
		int l = 0, r = st.size() - 1;
		while(l < r) {
			int m = (l + r + 1) / 2;
			if(st[m].fst > a[i]) r = m - 1;
			else l = m;
		}
		dp[i] = dp[st[l].snd] + b[st[l].snd] * a[i];
		while(!st.empty() && xcont(i, st.back().snd) <= st.back().fst)
			st.pop_back();
		st.pb(pii(xcont(st.back().snd, i), i));
	}
	cout << dp[n] << endl;
	return 0;	
}

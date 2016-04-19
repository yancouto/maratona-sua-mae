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
const int N = 100005;
const ll oo = 1000000000000000;

int n, m, p;
ll a[N], d[N], sm[N];
ll dp[110][N];
vector<pii> st;


ll xcont(int l, int k, int i) {
	ll v1 = sm[l] - sm[k];
	ll v2 = dp[i-1][l] - dp[i-1][k];
	ll v3 = l - k;
	return (ll) ceil((double)(v1 + v2) / (double) v3);
}

int main() {
	int i, j, k, x, h, t;
	scanf("%d%d%d", &n, &m, &p);
	for(i = 1; i <= n-1; i++) {
		scanf("%d", &x);
		d[i+1] = d[i] + x;
	}
	for(i = 1; i <= m; i++) {
		scanf("%d%d", &h, &t);
		a[i] = t - d[h];
	}
	sort(a+1, a+m+1);
	for(i = 1; i <= m; i++)
		sm[i] = sm[i-1] + a[i];
	for(i = 1; i <= m; i++) 
		dp[1][i] = (i - 1) * a[i] - sm[i-1];
	for(i = 2; i <= p; i++) {
		st.clear();
		st.pb(pii(-oo, 0));
		for(j = 1; j <= m; j++) {
			int l = 0, r = st.size() - 1;
			while(l < r) {
				int m = (l + r + 1) / 2;
				if(st[m].fst <= a[j]) l = m;
				else r = m - 1;
			}
			k = st[l].snd;
			dp[i][j] = a[j] * (j - k) - sm[j] + sm[k] + dp[i-1][k]; 
			while(!st.empty() && xcont(st.back().snd, j, i) <= st.back().fst)
				st.pop_back();
			st.pb(pii(xcont(st.back().snd, j, i), j));
		}
	}
	cout << dp[p][m] << endl;
	return 0;
}

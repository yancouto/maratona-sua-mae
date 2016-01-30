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

struct li {
	ll a, b; // y = a * x + b
	double end;
};

double x_inter(li p, li q) {
	return double(p.b - q.b) / (q.a - p.a);
}
const int N = 4003;
vector<li> sts[N];

ll dp[N][N];
int t[N], p[N], f[N];
int t2[N], p2[N], f2[N], P[N];

void add(vector<li> &st, li l) {
	if(!st.empty() && l.a == st.back().a) {
		if(l.b > st.back().b) st.pop_back();
		else return;
	}
	while(!st.empty() && x_inter(l, st.back()) >= st.back().end) st.pop_back();
	l.end = (st.empty()? 1/0. : x_inter(l, st.back()));
	st.push_back(l);
}

ll find(vector<li> &st, ll x) {
	if(st.empty()) return 0;
	int l = 0, r = st.size() - 1;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(st[m].end >= x) l = m;
		else r = m - 1;
	}
	return st[l].a * x + st[l].b;
}

int main() {
	int i, n, t, j;
	scanf("%d %d", &n, &t);
	for(i = 0; i < n; i++)
		scanf("%d %d %d", &t2[i], &p2[i], &f2[i]), P[i] = i;
	sort(P, P + n, [](int i, int j) { return f2[i] < f2[j]; });
	for(i = 0; i < n; i++)
		::t[i] = t2[P[i]], p[i] = p2[P[i]], f[i] = f2[P[i]];
	for(j = n - 1; j >= 0; j--) {
		for(i = 0; i <= t; i++) {
			ll &r = dp[j][i];
			if(i < ::t[j]) r = -10000000000ll;
			else r = max(0ll, find(sts[i - ::t[j]], f[j]) - f[j] * f[j]);
		}
		for(i = 0; i <= t; i++)
			if(dp[j][i] >= 0)
				add(sts[i], li{ 2 * f[j], dp[j][i] + p[j] - f[j] * f[j] , 0.});
	}
	ll best = 0;
	for(i = 0; i < n; i++)
		best = max(best, dp[i][t] + p[i]);
	printf("%lld\n", best);

}

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
const int N = 300009;

int memo[N][2], n;
int a[N], p[N], c[N], nxt[N], inv[N], lst[N];
vector<int> v[N];

inline bool first_color(int i) { return i == 0 || a[p[i]] != a[p[i - 1]]; }

int solve(int i, bool fst) {
	if(i == n) return 0;
	if(nxt[i] == n) return lst[i] - i + 1;
	int &r = memo[i][fst];
	if(r != -1) return r;
	if(a[p[i]] != a[p[i + 1]] && !first_color(nxt[i])) return r = 1 + (lst[nxt[i]] - nxt[i] + 1);
	if(a[p[i]] != a[p[i + 1]]) return r = 1 + solve(nxt[i], false);
	r = 1 + solve(i + 1, fst);
	if(fst && !first_color(nxt[i])) return r = max(r, 1 + (lst[nxt[i]] - nxt[i] + 1));
	if(fst) r = max(r, 1 + solve(nxt[i], false));
	return r;
}


int main() {
	freopen("gem.in", "r", stdin);
	freopen("gem.out", "w", stdout);
	memset(memo, -1, sizeof memo);
	int i, cn;
	scanf("%d", &n); 
	for(i = 0; i < n; i++) 
		scanf("%d", &a[i]), c[i] = a[i], p[i] = i;
	sort(c, c + n);
	cn = unique(c, c + n) - c;
	for(i = 0; i < n; i++) {
		a[i] = lower_bound(c, c + cn, a[i]) - c;
		v[a[i]].pb(i);
	}
	sort(p, p + n, [](int i, int j) { if(a[i] == a[j]) return i < j; else return a[i] < a[j]; });
	for(i = 0; i < n; i++) inv[p[i]] = i;
	lst[n - 1] = n - 1;
	for(i = n - 2; i >= 0; i--)
		lst[i] = (a[p[i + 1]] == a[p[i]]? lst[i + 1] : i);
	for(i = 0; i < n; i++) {
		if(a[p[i]] == cn - 1 || v[a[p[i]] + 1].back() < p[i]) { nxt[i] = n; continue; }
		nxt[i] = inv[*upper_bound(v[a[p[i]] + 1].begin(), v[a[p[i]] + 1].end(), p[i])];
	}
	int mn = INT_MIN;
	for(i = 0; i < n; i++)
		mn = max(mn, solve(i, true));
	printf("%d\n", n - mn);
}

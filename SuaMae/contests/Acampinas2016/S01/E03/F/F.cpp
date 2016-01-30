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

#define ls first
#define so second
const int N = 100009;
ll tot = 0;
int leaf[N];
int tr[N][26];
pii ps[N];
pii dfs(int u) {
	pii &p = ps[u]; int so = 0;
	if(leaf[u]) return p = pii(1, 0);
	for(int i = 0; i < 26; i++)
		if(tr[u][i]) {
			pii g = dfs(tr[u][i]);
			p.ls += g.ls;
			p.so += g.so;
			so++;
		}
	if(so > 1) {
		p.so = 0;
		return p;
	} else return p = pii(p.ls, p.so + 1);
}

ll memo[N][2];
ll solve(int u, bool up) {
	if(leaf[u]) return 0;
	ll &r = memo[u][up];
	if(r != -1) return r;
	ll t = 0;
	for(int i = 0; i < 26; i++)
		if(tr[u][i]) {
			if(ps[u].so && u) return r = solve(tr[u][i], up);
			t += solve(tr[u][i], false) + ll(min(ps[tr[u][i]].so + 1, 2)) * ll(ps[tr[u][i]].ls);
		}
	r = LLONG_MAX;
	for(int i = 0; i < 26; i++)
		if(tr[u][i])
			r = min(r, solve(tr[u][i], true) + (!up) * ps[tr[u][i]].ls  + (t - (solve(tr[u][i], false) + ll(min(ps[tr[u][i]].so + 1, 2)) * ll(ps[tr[u][i]].ls))));
	return r;
}

int tn = 1;
char s[N];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", s);
		int v = 0;
		for(j = 0; s[j]; j++) {
			s[j] -= 'a';
			if(!tr[v][s[j]]) tr[v][s[j]] = tn++;
			v = tr[v][s[j]];
		}
		leaf[v] = 1;
	}
	dfs(0);
	memset(memo, -1, sizeof memo);
	printf("%lld\n", solve(0, false));
}

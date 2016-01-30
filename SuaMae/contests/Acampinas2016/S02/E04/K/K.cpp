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
ull inf = 1000000000000000009;

int ing[102][25], k[102], b[1009];
int no[102][102];
ll val;
int seen[1009], cur;

inline int lg(ull x) { return 63 - __builtin_clzll(x); }

void calc(int d) {
	int i;
	for(i = 0; i < k[d]; i++) {
		if(seen[ing[d][i]] == cur) continue;
		seen[ing[d][i]] = cur;
		if(lg(val) + lg(b[ing[d][i]]) >= 60) val = inf;
		else val *= b[ing[d][i]];
	}
}

int main() {
	int i, j, r, s, m, d, n, da, db, i2;
	scanf("%d %d %d %d %d", &r, &s, &m, &d, &n);
	for(i = 0; i < r; i++)
		scanf("%d", &b[i]);
	for(i = 0; i < s + m + d; i++) {
		scanf("%d", &k[i]);
		for(j = 0; j < k[i]; j++)
			scanf("%d", &ing[i][j]), ing[i][j]--;
	}
	for(i = 0; i < n; i++) {
		scanf("%d %d", &da, &db); da--; db--;
		no[da][db] = no[db][da] = 1;
	}
	ull tot = 0;
	for(i = 0; i < s; i++)
		for(j = s; j < s + m; j++)
			if(!no[i][j])
				for(i2 = s + m; i2 < s + m + d; i2++) {
					if(no[j][i2] || no[i][i2]) continue;
					cur++; val = 1;
					calc(i); calc(j); calc(i2);
					tot = min(inf, tot + val);
				}
	if(tot > 1000000000000000000) puts("too many");
	else printf("%llu\n", tot);
}

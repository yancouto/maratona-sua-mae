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

struct st {
	int v[3];
	inline bool operator >= (const st &o) const {
		return v[0] >= o.v[0] && v[1] >= o.v[1] && v[2] >= o.v[2];
	}
};

const int N = 4009;
vector<st> ss[N];

int o[256];
st calc(const char *c) {
	st x; x.v[0] = x.v[1] = x.v[2] = 0;
	for(int i = 0; c[i]; i++)
		x.v[o[c[i]]]++;
	return x;
}

char s[N], cur[N];

int main() {
	int i, j, n;
	o['A'] = 0; o['C'] = 1; o['M'] = 2;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i <= n; i++) ss[i].clear();
		int mn2 = INT_MAX, mx2 = INT_MIN;
		int mn = INT_MAX, mx = INT_MIN;
		bool bad = false;
		scanf("%s", cur);
		st b = calc(cur);
		for(i = 0; i < n; i++) {
			scanf("%s", s);
			int g = strlen(s);
			mn = min(mn, g); mx = max(mx, g);
			st x = calc(s);
			ss[g].pb(x);
			if(ss[g].size() == 2) mn2 = min(mn2, g), mx2 = max(mx2, g);
			bad |= ss[g].size() > 2;
			bad |= !(b >= x);
			bad |= g >=
		}
		for(i = mn; i <= mx; i++)
			bad |= ss[i].empty();
		for(i = mn2; i <= mx2; i++)
			bad |= ss[i].size() != 2;
		if(bad) { puts("impossible"); continue; }
	}
}

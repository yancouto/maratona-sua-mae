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
string t[100009];

typedef pii hs;
#define i first
#define st second
inline int sz(hs p) { return t[p.i].size() - p.st; }
int base;

vector<int> h[100009];

inline int get(hs a, int d) {
	ll hh = h[a.i][a.st + d - 1];
	if(a.st) hh = mod(hh - h[a.i][a.st - 1] + modn);
	return hh;
}

inline bool eqh(hs a, hs b, int s) {
	return get(a, s) == get(b, s);
}

int lcp(hs a, hs b) {
	if(t[a.i][a.st] != t[b.i][b.st]) return 0;
	int l = 1, r = min(sz(a), sz(b));
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(eqh(a, b, m)) l = m;
		else r = m - 1;
	}
	return l;
}

bool hless(hs a, hs b) {
	int s = lcp(a, b);
	if(s == sz(a) || s == sz(b)) return sz(a) < sz(b);
	return t[a.i][a.st + s] < t[b.i][b.st + s];
}

int c[100009];
char s[500009];
hs vs[500009];
int vn;
ll acc[500009];

typedef pii da;
#define pre second

int main() {
	int i, j, n;
	base = 263 + (rand() % 200);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", &s);
		t[i].append(s);
		h[i].resize(t[i].size());
		ll hh = 0;
		for(j = 0; j < t[i].size(); j++)
			h[i][j] = (hh = mod(hh * base + t[i][j])),
			vs[vn++] = hs(i, j);
	}
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);
	sort(vs, vs + vn, hless);
	for(i = 0; i < vn; i++) 
		acc[i] = c[vs[i].i] + (i? acc[i - 1] : 0ll);
	set<int> vals;
	da st[500009]; int sn = 0;
	for(i = vn - 1; i >= 0; i--) {
		da d(i, sz(vs[i]));

	}
	printf("%lld\n", b);
}

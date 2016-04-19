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
const int N = 112345;
int d[N], c[N], s[N], v[N], ans[N];
ll l[N];
vector<int> t[N];

struct ev {
	ll t;
	bool ship;
	int i;
	bool operator < (ev o) const {
		if(t != o.t) return t < o.t;
		if(ship != o.ship) return !ship;
		return i < o.i;
	}
};
set<ev> evs;

struct crane {
	bool operator()(int i, int j) {
		if(l[i] != l[j]) return l[i] < l[j];
		return i < j;
	}
};
set<int, crane> cr[12];

struct ship {
	bool operator()(int i, int j) {
		if(d[i] != d[j]) return d[i] < d[j];
		return i < j;
	}
};
set<int, ship> dock[12];

void process_ship(ll cur, int S) {
	if(cr[c[S]].empty()) { dock[c[S]].insert(S); return; }
	int C = *cr[c[S]].begin();
	for(int ty : t[C])
		cr[ty].erase(C);
	ll days = (s[S] + v[C] - 1) / v[C];	
	evs.insert(ev{cur + days, false, C});
	ans[S] = C;
}

void process_crane(ll cur, int C) {
	set<int, ship> ch;
	for(int ty : t[C])
		if(!dock[ty].empty())
			ch.insert(*dock[ty].begin());
	if(ch.empty()) {
		l[C] = cur;
		for(int ty : t[C])
			cr[ty].insert(C);
		return;
	}
	int S = *ch.begin();
	dock[c[S]].erase(S);
	ll days = ll(s[S] + v[C] - 1) / v[C];	
	evs.insert(ev{cur + days, false, C});
	ans[S] = C;
}

int main() {
	freopen("seaport.in", "r", stdin);
	freopen("seaport.out", "w", stdout);
	int i, j, n, m, tt, b;
	scanf("%d %d %*d", &n, &m);	
	for(i = 0; i < n; i++) {
		scanf("%d %d %d", &d[i], &c[i], &s[i]);
		evs.insert(ev{d[i], true, i});
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d", &v[i], &tt);
		for(j = 0; j < tt; j++) {
			scanf("%d", &b);
			t[i].pb(b);
			cr[b].insert(i);
		}
	}
	while(!evs.empty()) {
		ev e = *evs.begin(); evs.erase(evs.begin());
		if(e.ship) process_ship(e.t, e.i);
		else process_crane(e.t, e.i);
	}
	for(i = 0; i < n; i++)
		printf("%d\n", ans[i] + 1);
}

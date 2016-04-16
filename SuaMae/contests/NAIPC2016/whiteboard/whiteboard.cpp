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
const int N = 1123456;

char g[N];
ll v[N];
vector<ll> ua[N], ur[N], da[N], dr[N], la[N], lr[N], ra[N], rr[N];
int n, m;
int id(int i, int j) { return i * m + j; }
inline char& G(int i, int j) { return g[id(i, j)]; }
inline ll& V(int i, int j) { return v[id(i, j)]; }
inline vector<ll>& UA(int i, int j) { return ua[id(i, j)]; }
inline vector<ll>& UR(int i, int j) { return ur[id(i, j)]; }
inline vector<ll>& DA(int i, int j) { return da[id(i, j)]; }
inline vector<ll>& DR(int i, int j) { return dr[id(i, j)]; }
inline vector<ll>& LA(int i, int j) { return la[id(i, j)]; }
inline vector<ll>& LR(int i, int j) { return lr[id(i, j)]; }
inline vector<ll>& RA(int i, int j) { return ra[id(i, j)]; }
inline vector<ll>& RR(int i, int j) { return rr[id(i, j)]; }
// REMOVER NO FINAL DA ITERACAO

void sweep_r() {
	int i, j;
	for(i = 0; i < n; i++) {
		multiset<ll> l, r;
		for(j = 0; j < m; j++) {
			for(ll v : LA(i, j)) l.insert(v);
			for(ll v : RA(i, j)) r.insert(v);
			// stuff
			if(V(i, j) == LLONG_MAX && (l.size() || r.size())) V(i, j) = 0;
			if(!l.empty()) V(i, j) = max(V(i, j), (*l.rbegin()) - j);
			if(!r.empty()) V(i, j) = max(V(i, j), (*r.rbegin()) + j);
			for(ll v : LR(i, j)) assert(l.count(v)), l.erase(l.find(v));
			for(ll v : RR(i, j)) assert(r.count(v)), r.erase(r.find(v));
		}
	}
}

void sweep_c() {
	int i, j;
	for(j = 0; j < m; j++) {
		multiset<ll> u, d;
		for(i = 0; i < n; i++) {
			for(ll v : UA(i, j)) u.insert(v);
			for(ll v : DA(i, j)) d.insert(v);
			// stuff
			if(V(i, j) == LLONG_MAX && (u.size() || d.size())) V(i, j) = 0;
			if(!u.empty()) V(i, j) = max(V(i, j), (*u.rbegin()) - i);
			if(!d.empty()) V(i, j) = max(V(i, j), (*d.rbegin()) + i);
			for(ll v : UR(i, j)) assert(u.count(v)), u.erase(u.find(v));
			for(ll v : DR(i, j)) assert(d.count(v)), d.erase(d.find(v));
		}
	}
}

char mv[100];
main() {
	int i, j, d, k;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < n * m; i++)
		scanf(" %c", &g[i]), v[i] = LLONG_MAX;
	int ci = n - 1, cj = 0;
	ll t = 1;
	for(i = 0; i < k; i++) {
		scanf("%s %d", mv, &d);
		if(mv[0] == 'u') {
			UA(ci - d, cj).pb(t + ci);
			UR(ci, cj).pb(t + ci);
			ci -= d;
		} else if(mv[0] == 'd') {
			DA(ci, cj).pb(t - ci);
			DR(ci + d, cj).pb(t - ci);
			ci += d;
		} else if(mv[0] == 'l') {
			LA(ci, cj - d).pb(t + cj);
			LR(ci, cj).pb(t + cj);
			cj -= d;
		} else {
			RA(ci, cj).pb(t - cj);
			RR(ci, cj + d).pb(t - cj);
			cj += d;
		}
		t += d;
	}
	sweep_r();
	sweep_c();
	ll mn = 0, mx = t;
	for(i = 0; i < n * m; i++) {
		//printf("at (%d, %d) %c with %d\n", (i / m), (i % m), g[i], v[i]);
		if(g[i] == '#')
			mn = max(mn, v[i]);
		else
			mx = min(mx, v[i] - 1);
	}
	if(mx < mn) puts("-1 -1");
	else printf("%lld %lld\n", mn, mx);
}

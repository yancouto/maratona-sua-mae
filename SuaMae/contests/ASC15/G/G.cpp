#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define lld I64d

map<ll, int> mp;
vector<ll> p;

bool ok(int x, int d) { return (x % d) == 0; }
bool cmp(ll a, ll b) { return a > b; }

void gprimes(int x) {
	ll i;
	x = max(x, -x);
	if(ok(x, 2)) p.pb(2);
	while(ok(x, 2))	x /= 2, mp[2]++;
	for(i = 3; i <= x; i+=2) {
		if(ok(x, i)) p.pb(i);
		while(ok(x, i)) x /= i, mp[i]++;
	}
	if(x > 1) p.pb(x), mp[x]++;
	sort(p.begin(), p.end(), cmp);
	//printf("Primos %d\n", p.size());
}

pii gen[40];
vector<ll> v[900000];
int iv;

void show(int neg, int x) {
	if(neg%2 != x) return;
	for(int i = 0; i < p.size(); i++) {
		int sz = mp[p[i]], j = gen[i].snd;
//		printf("Gerei sz %d p[i] = %lld gen %d %lld\n", sz, p[i], gen[i].fst, gen[i].snd);
		for(int k = 0; k < j*2 + gen[i].fst; k++)
			v[iv].pb(-p[i]);
		for(int k = j*2 + gen[i].fst; k < sz; k++)
			v[iv].pb(p[i]);
	}
	sort(v[iv].begin(), v[iv].end());
	iv++;
}

void solve(int i, int neg, bool x) {
	if(i == p.size()) { show(neg, x); return ; }
	int sz = mp[p[i]];
	for(int pos = 1; pos >= 0; pos--)
		for(int j = (sz+1)/2 - 1 + (!pos && !(sz%2)); j >= 0; j--)
			gen[i] = pii(pos, j), solve(i+1, neg+pos, x);
}

bool comp(vector<ll> vi, vector<ll> vj) {
	int ii = 0, jj = 0;
	while(vi[ii] == vj[jj]) ii++, jj++;
	return vi[ii] < vj[jj];
}

int main() {
	//freopen("product.in", "r", stdin);
	//freopen("product.out", "w", stdout);
	ll n;
	scanf("%lld", &n);
	gprimes(n);
	solve(0, 0, n < 0);
	printf("%lld\n", iv);
	sort(v, v + iv, comp);
	for(int i = 0; i < iv; i++) {
		for(ll x : v[i]) printf("%lld ", x);
		putchar('\n');
	}
	return 0;
}

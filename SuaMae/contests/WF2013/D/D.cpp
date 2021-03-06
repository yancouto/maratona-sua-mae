#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ull, ull> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ull p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int d[70][70];
vector<int> v, ds[70];
int res[70];
vector<pii> s;
void solve(int i, ull n, int e, int mx) {
	if(n >= (1ull << 63)) return;
	if(i == 15) {
		if(n == 1) return;
		memset(res, 0, sizeof res);
		for(i = 2; i <= e; i++)
			for(int div : ds[i])
				res[div] += d[i][div];
		for(int x : v)
			for(i = 2; i <= x; i++)
				for(int div : ds[i])
					res[div] -= d[i][div];
		ull val = 1;
		for(i = 2; i < 70; i++)
			for(int j = 0; j < res[i]; j++) {
				if(log(val) + log(i) > 43.8) return;
				val *= i;
			}
		if(val >= (1ull << 63)) return;
		s.pb(pii(n, val));
		return;
	}
	for(int j = 0; j <= mx; j++) {
		v.pb(j);
		solve(i + 1, n, e, j);
		v.pop_back();
		if(log(n) + log(p[i]) > 43.8) return;
		n *= p[i];
		e++;
	}
}


int main() {
	int i, j;
	for(i = 2; i <= 62; i++) {
		int x = i;
		for(j = 2; j <= x; j++) {
			if(!(x % j)) ds[i].pb(j);
			while(!(x % j)) x /= j, d[i][j]++;
		}
	}
	solve(0, 1, 0, 100);
	sort(s.begin(), s.end());
	ull k;
	while(scanf("%llu", &k) != EOF) {
		for(pii p : s)
			if(p.snd == k) {
				printf("%llu %llu\n", k, p.fst);
				break;
			}
	}
}

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
const ll modn = 9999991;
inline ll mod(ll x) { return x % modn; }

struct no {
	int fe, fd, num;
	int le, ri;
} ns[50]; int nn;

int add(int v, int x) {
	if(v == -1) {
		v = nn++;
		ns[v].num = x;
		ns[v].le = ns[v].ri = -1;
		ns[v].fe = ns[v].fd = 0;
		return v;
	}
	if(ns[v].num > x) ns[v].le = add(ns[v].le, x), ns[v].fe++;
	else ns[v].ri = add(ns[v].ri, x), ns[v].fd++;
	return v;
}

ll memo2[50][50];
ll comb(int p, int n) {
	if(p < 0 || n < 0 || p > n) return 0;
	if(n == 0) return 1;
	ll &r = memo2[p][n];
	if(r != -1) return r;
	r = mod(comb(p - 1, n - 1) + comb(p, n - 1));
	return r;
}

ll fat[50];
ll memo[50];
ll solve(int i) {
	if(i == -1) return 1;
	ll &r = memo[i];
	if(r != -1) return r;
	return r = mod(mod(solve(ns[i].le) * solve(ns[i].ri)) * comb(ns[i].fe, ns[i].fe + ns[i].fd));
}

int main() {
	int n, x;
	int i;
	memset(memo2, -1, sizeof memo2);
	fat[0] = 1;
	for(i = 1; i < 50; i++)
		fat[i] = mod(fat[i - 1] * ll(i));
	for_tests(t, tt) {
		scanf("%d", &n);
		nn = 0;
		int root = -1;
		for(i = 0; i < n; i++) {
			scanf("%d", &x);
			root = add(root, x);
		}
		memset(memo, -1, sizeof memo);
		printf("%d\n", solve(root));
	}
}

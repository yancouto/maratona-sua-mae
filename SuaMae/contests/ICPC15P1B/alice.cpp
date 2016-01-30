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

ll pot[120];

int main() {
	for(int i = 1; i <= 55; i++)
		pot[i] = (pot[i-1] + 1) * 2 - 1;

	for_tests(t, tt) {
		ll h, x, n, root, leaf, lvl;
		root = leaf = 0;
		scanf("%lld %lld", &n, &x);
		for(h = 1; h <= 55 && pot[h] <= n; h++);
		h--;
		if(x > h) { puts("0 0"); continue; }

		if(x <= h - 1) root = pot[x+1] - pot[x];
		else root = n - pot[h];

		if(n == pot[h]) leaf = pot[h-x] - pot[max(h - x - 1, 0ll)];
		else {
			leaf = n - pot[h];
			for(int i = 1; i <= x; i++) { leaf++; leaf /= 2; }
			ll qtd = (leaf + 1) / 2;
			if(h >= x + 1)
				leaf += pot[h-x] - pot[h-x-1] - qtd;
		}
		printf("%lld %lld\n", root, leaf);
	}
	return 0;
}

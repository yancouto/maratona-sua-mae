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

int mx[10009], mx_ind[10009], seen[10009], ind[10009];
int main() {
	freopen("generators.in", "r", stdin);
	freopen("generators.out", "w", stdout);
	int i, n, k, x, a, b, c, j;
	scanf("%d %d", &n, &k);
	int best = 2000;
	int sec_i, sec_ind;
	int tot = 0;
	for(i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &x, &a, &b, &c);
		int id = 0;
		while(seen[x] != i) {
			seen[x] = i;
			ind[x] = id++;
			mx[i] = max(mx[i], x);
			x = (a * x + b) % c;
		}
		mx_ind[i] = ind[mx[i]];
		tot += mx[i];
		for(j = 999; j >= 0; j--)
			if(seen[j] == i && (j % k) != (mx[i] % k))
				break;
		if(j >= 0 && mx[i] - j < best) { best = mx[i] - j; sec_i = i; sec_ind = ind[j]; }
	}
	if((tot % k) == 0 && best == 2000) { puts("-1"); return 0; }
	if((tot % k) == 0) tot -= best, mx_ind[sec_i] = sec_ind;
	printf("%d\n", tot);
	for(i = 0; i < n; i++)
		printf("%d ", mx_ind[i + 1]);
	putchar('\n');
}

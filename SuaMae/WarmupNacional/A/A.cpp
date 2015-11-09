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
const int N = 300009;
ll bit[N];
ll get(int i) {
	ll sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}

ll add(int i, ll x) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] += x;
}


int a[N];
int main() {
	int i, j, n, q, x, l, r, op;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i + 1]);
	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d", &x);
			ll tot = 0;
			for(j = 1; j * j <= x; j++)
				if(!(x % j)) {
					tot += get(j);
					if(j * j != x) tot += get(x / j);
				}
			printf("%lld\n", tot + a[x]);
		} else {
			scanf("%d %d %d", &l, &r, &x);
			add(l, x);
			add(r + 1, -x);
		}
	}
}

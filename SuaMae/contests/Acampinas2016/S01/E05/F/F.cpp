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

int S[1009], sz[1009];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}

inline int sq(int x) { return x * x; }
int x[1009], y[1009], r[1009];
inline int dist2(int i, int j) { return sq(x[i] - x[j]) + sq(y[i] - y[j]); }

int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i <= n + 2; i++) S[i] = i;
	for(i = 0; i < n; i++) {
		scanf("%d %d %d", &x[i], &y[i], &r[i]);
		r[i] = min(r[i], 2000);
		for(j = 0; j < i; j++)
			if(dist2(i, j) <= sq(r[i] + r[j]))
				join(i, j);
		if(y[i] + r[i] >= 1000) join(i, n);
		if(y[i] - r[i] <= 0) join(i, n + 1);
	}
	if(find(n) == find(n + 1)) { puts("-1"); return 0; }
	double topl = 1000, topr = 1000;
	for(i = 0; i < n; i++)
		if(x[i] - r[i] <= 0 && find(i) == find(n))
			topl = min(topl, y[i] - sqrt(sq(r[i]) - sq(x[i])));
	for(i = 0; i < n; i++)
		if(x[i] + r[i] >= 1000 && find(i) == find(n))
			topr = min(topr, y[i] - sqrt(sq(r[i]) - sq(1000 - x[i])));
	printf("%.2f %.2f %.2f %.2f\n", 0., topl, 1000., topr);
		
}

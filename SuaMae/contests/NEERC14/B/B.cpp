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
const int N = 100009;
int g[N], a[N], b[N], p[N];
double G[N];
int main() {
	freopen("burrito.in", "r", stdin);
	freopen("burrito.out", "w", stdout);
	int i, n, A, B;
	scanf("%d %d %d", &n, &A, &B); 
	for(i = 0; i < n; i++)
		scanf("%d %d %d", &g[i], &a[i], &b[i]), p[i] = i;
	sort(p, p + n, [](int i, int j) { return b[i] * a[j] < b[j] * a[i]; });
	int cA = 0, cB = 0;
	for(i = 0; i < n && b[p[i]] == 0; i++)
		cA += g[p[i]] * a[p[i]];
	for(; i < n; i++) {
		int j = p[i];
		if(cB + g[j] * b[j] < B) { cB += g[j] * b[j]; cA += g[j] * a[j]; continue; }
		if(ll(B - cB) * ll(a[j]) < ll(A - cA) * ll(b[j])) break;
		double l = double(B - cB) / b[j];
		printf("%.15f %d\n", cA + l * a[j], B);
		for(int k = 0; k < i; k++)
			G[p[k]] = g[p[k]];
		G[j] = l;
		for(int k = 0; k < n; k++)
			printf("%.15f ", G[k]);
		putchar('\n');
		return 0;
	}
	if(cA >= A && cB <= B) {
		printf("%d %d\n", cA, cB);
		for(i = 0; i < n; i++)
			printf("%d ", g[i]);
		putchar('\n');
	} else puts("-1 -1");
}

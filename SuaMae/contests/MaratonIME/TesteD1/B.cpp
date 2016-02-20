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
const int N = 51000;
#define prev asdlsdsdf

int bit[N], prev[N], a[N], b[N], c[N], p[N];
void add(int i) {
	for(i += 2; i < N; i += (i & -i))
		bit[i]++;
}

int get(int i) {
	int sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}

int main() {
	int i, n;
	for_tests(t, tt) {
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%d %d %d", &a[i], &b[i], &c[i]), p[i] = i;
		for(i = 0; i < N; i++)
			prev[i] = i - 1, bit[i] = 0;
		sort(p, p + n, [](int i, int j) { return b[i] < b[j]; });
		for(i = 0; i < n; i++) {
			int more = c[p[i]] - (get(b[p[i]]) - get(a[p[i]] - 1));
			for(; more > 0; more--) {
				int j = prev[b[p[i]] + 1];
				add(j);
				prev[b[p[i]] + 1] = prev[j];
			}
		}
		printf("%d\n", get(50010));
	}
}

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
const int N = 1005;

int n, m;
int a[N], b[N];

bool check(int x, int y, int p) { return p >= x && p <= y; }

int main() {
	freopen("knockout.in", "r", stdin);
	freopen("knockout.out", "w", stdout);
	int i, j, x, y, t;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &t);
		int ans = 0;
		for(j = 0; j < n; j++) {
			int f = t / (b[j]-a[j]);
			int d = t % (b[j]-a[j]);
			if(f%2) ans += check(x, y, b[j] - d);
			else ans += check(x, y, a[j] + d);
		}
		printf("%d\n", ans);
	}
	return 0;
}

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
int v[N], h[N];
int main() {
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &v[i]);
	for(i = 0; i < m; i++)
		scanf("%d", &h[i]);
	int mx = 0;
	mx = max(mx, min(v[0], h[m - 1]));
	mx = max(mx, min(h[0], v[n - 1]));
	mx = max(mx, min(min(v[0], v[n - 1]), *max_element(h, h + m)));
	mx = max(mx, min(min(h[0], h[m - 1]), *max_element(v, v + n)));
	printf("%d\n", mx);
}

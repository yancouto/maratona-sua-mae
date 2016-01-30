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
int a[N], p[N], n, x;

bool pos(int k) {
	int po = 0, b = 0;
	for(int i = 1; i < n; i++) {
		if(po == k) po++;
		if(a[i] + p[po] > a[0] + p[k])
			po++, b++;
	}
	return b <= x;
}

int main() {
	freopen("hop.in", "r", stdin);
	freopen("hop.out", "w", stdout);
	int i;
	scanf("%d %d", &n, &x); x--;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n);
	for(i = 0; i < n; i++)
		scanf("%d", &p[i]);
	if(!pos(0)) { puts("-1"); return 0; }
	int l = 0, r = n - 1;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(pos(m)) l = m;
		else r = m - 1;
	}
	printf("%d\n", l + 1);
}

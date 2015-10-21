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
const int MAX = 1000009;
int seen[MAX], has[MAX];
const int N = 100009;
int p[N], pn;
int a[N], b[N], c[N];
int main() {
	int i, n;
	for_tests(t, tt) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
			seen[a[i]] = tt;
		}
		has[0] = (seen[0] == tt);
		for(i = 1; i < MAX; i++)
			has[i] = (seen[i] == tt) + has[i - 1];
		pn = 0;
		for(i = 0; i < n; i++) {
			//printf("%d %d %d\n %d < %d\n", a[i], b[i], c[i], has[b[i] - 1] + (a[i] >= b[i] && a[i] <= c[i]), has[c[i]]);
			if((b[i] == 0 && (a[i] <= c[i]) < has[c[i]]) || (has[b[i] - 1] + (a[i] >= b[i] && a[i] <= c[i]) < has[c[i]]))
				continue;
			p[pn++] = i;
		}
		sort(p, p + pn, [](int i, int j) { return c[i] < c[j]; });
		int last = -1; int tot = has[MAX - 1];
		for(i = 0; i < pn; i++)
			if(last < b[p[i]]) {
				last = c[p[i]];
				tot++;
			}
		printf("Case #%d: %d\n", tt, tot);
	}
}

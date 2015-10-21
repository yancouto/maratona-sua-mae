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

int p[1009], s[1009];
int main() {
	int i, j, n, k;
	for_tests(t, tt) {
		scanf("%d %d", &n, &k);
		for(i = 0; i < k; i++)
			scanf("%d", &p[i]);
		sort(p, p + k);
		memset(s, 0, sizeof s);
		for(i = 0; i < k; i++) {
			int tot = 0;
			for(j = p[i]; j <= n; j += p[i])
				tot += -(2 * s[j] - 1);
			if(tot >= 0)
				for(j = p[i]; j <= n; j += p[i])
					s[j] = !s[j];
		}
		printf("Case #%d: %d\n", tt, accumulate(s, s + n + 1, 0));
	}
}

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

char s[1009];

int main() {
	int i, n;
	for_tests(tn, tt) {
		scanf("%s", s);
		n = strlen(s);
		int tot = 0;
		int z[1009], zn = 0;
		for(i = 0; i < n; i++)
			if(s[i] != 'A') {
				tot += min(s[i] - 'A', 'Z' - s[i] + 1);
				z[zn++] = i;
			}
		if(zn == 0) { puts("0"); continue; }
		int mn = z[zn - 1];
		for(i = 0; i < zn - 1; i++)
			mn = min(mn, z[i] + n - z[i + 1] + min(z[i], n - z[i + 1]));
		printf("%d\n", mn + tot);
	}
}

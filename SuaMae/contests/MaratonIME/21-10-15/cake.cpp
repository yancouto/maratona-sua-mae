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

int memo[2003][2003];
int k; char s[2003]; int n;

int main() {
	int m, i, j;
	for_tests(t, tt) {
		scanf("%d %d %d", &n, &m, &k);
		scanf("%s", s);
		for(i = 0; i < 2 * n; i++)
			memo[i][0] = s[(i + 2 * n - 1) % (2 * n)] == 'A';
		for(j = 1; j <= m; j++)
			for(i = 0; i < 2 * n; i++) {
				int g = max(0, j - k);
				int val = memo[(i + 1) % (2 * n)][j - 1];
				if(g > 0) val -= memo[(i + 1) % (2 * n)][g - 1];
				if(s[i] == 'A')
					memo[i][j] = (val > 0);
				else
					memo[i][j] = !(val < min(k, j));
				memo[i][j] += memo[i][j - 1];
			}
		printf("Case #%d: %c\n", tt, !(memo[0][m] - memo[0][m - 1]) + 'A');
	}
}

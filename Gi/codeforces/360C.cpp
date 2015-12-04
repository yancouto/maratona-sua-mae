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
const int N = 2005;

int n, k;
char s[N];
ll memo[N][N], sum[N][N];

int main() {
	int i, j, t;
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	memo[0][0] = sum[0][0] = 1;
	for(i = 1; i <= n; i++) {
		for(j = 0; j <= k; j++) {
			memo[i][j] = mod(sum[i-1][j] * (s[i] - 'a'));
			for(t = i - 1; t >= 0; t--) {
				if(j < (i - t) * (n - i + 1)) break;
				memo[i][j] = mod(memo[i][j] + mod(memo[t][j - (i - t) * (n - i + 1)] * ('z' - s[i])));
			}
			sum[i][j] = mod(sum[i-1][j] + memo[i][j]);
		}
	}
	printf("%lld\n", sum[n][k]);
	return 0;
}

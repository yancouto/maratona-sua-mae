#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#define oo 1000000000

int n, k, l, F;
int fun[1005], diz[1005];
int memo[2][20005];

int main() {
	while(42) {
		scanf("%d %d %d", &n, &k, &l);
		if(n + k + l == 0) break;
		for(int i = 0; i < n; i++) scanf("%d %d", &fun[i], &diz[i]);
		memo[0][0] = 0;
		for(int i = 1; i <= 20 * n; i++) {
			memo[0][i] = oo;
			if(i == fun[0] && diz[0] <= l) memo[0][i] = diz[0];
		}
		for(int i = 1; i < n; i++) {
			int ii = (i - 1) % 2;
			for(int j = 0; j <= 20 * n; j++) {
				int &m = memo[i%2][j];
				m = max(0, memo[ii][j] - k);
				if(j >= fun[i] && (memo[ii][j - fun[i]] + diz[i]) <= l) 
					m = min(m, memo[ii][j - fun[i]] + diz[i]);
			}
		}
		int i;
		for(i = 20 * n; i >= 0; i--)
			if(memo[(n-1)%2][i] <= l) break;
		printf("%d\n", i);
	}
	return 0;
}

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

char s[2009];
int dp[1509][1509];
void build(int i, int j) {
	if(i > j) return;
	if(dp[i][j] == dp[i + 1][j]) return build(i + 1, j);
	for(int k = i + 1; k <= j; k++)
		if(s[i] == s[k] && dp[i][j] == 1 + dp[i + 1][k - 1] + dp[k + 1][j]) {
			printf("%d %d\n", i + 1, k + 1);
			build(i + 1, k - 1);
			build(k + 1, j);
			return;
		}
}

int main() {
	freopen("cable.in", "r", stdin);
	freopen("cable.out", "w", stdout);
	int i, j, k, n;
	scanf("%d", &n);
	scanf("%s", s);
	for(i = n - 1; i >= 0; i--)
		for(j = i + 1; j < n; j++) {
			int &r = dp[i][j];
			r = dp[i + 1][j];
			for(k = i + 1; k <= j; k++)
				if(s[i] == s[k])
					r = max(r, 1 + dp[i + 1][k - 1] + dp[k + 1][j]);
		}
	printf("%d\n", dp[0][n - 1]);
	build(0, n - 1);
}

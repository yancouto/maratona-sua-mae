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
const int N = 502;
int d[N][N];
int co[N], n;

int memo[N][N];
//int solve(int i, int k) {
//	if(k == 0) return 0;
//	int &ans = memo[i][k], cur = 0;
//	if(ans != -1) return ans;
//	ans = 0;
//	for(int j = i + 1; j < n; j++) {
//		cur += co[j] - d[i + 1][j];
//		ans = max(ans, solve(j, k - 1) + cur);
//	}
//	return ans;
//}

int main() {
	//memset(memo, -1, sizeof memo);
	int i, j, k;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++) {
			scanf("%d", &d[i][j]);
			co[i] += d[i][j];
		}
	for(j = 0; j < n; j++)
		for(i = n - 1; i >= 0; i--)
			d[i][j] += d[i + 1][j];
	for(j = 1; j < k; j++)
		for(i = 0; i < n; i++) {
			int cur = 0, &ans = memo[i][j];
			for(int g = i + 1; g < n; g++) {
				cur += co[g] - d[i + 1][g];
				ans = max(ans, memo[g][j - 1] + cur);
			}
		}
	int mx = 0, mxi = -1, cur = 0;
	for(i = 0; i < n; i++) {
		cur += co[i] - d[0][i];
		if(memo[i][k - 1] + cur > mx)
			mxi = i;
		mx = max(mx, memo[i][k - 1] + cur);
	}
	printf("%d\n", mx);
	printf("%d", mxi + 1);
	for(j = k - 1; j; j--) {
		int cur = 0, &ans = memo[mxi][j];
		for(int g = mxi + 1; g < n; g++) {
			cur += co[g] - d[mxi + 1][g];
			if(ans == memo[g][j - 1] + cur) {
				mxi = g;
				printf(" %d", g + 1);
				break;
			}
		}
	}
	putchar('\n');
}

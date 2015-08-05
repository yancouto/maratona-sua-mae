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
int a[15][4];
int n;

int memo[4][300][5000];
int solve(int c, int left, int bm) {
	int &ret = memo[c][left][bm];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 1; i <= 3; i++) {
		 if(c == i) continue;
		 for(int j = 0; j < n; j++) {
			  if(bm & (1 << j)) continue;
			  if(a[j][i] > left) continue;
			  ret = max(ret, 1 + solve(i, left - a[j][i], bm | (1 << j)));
		 }
	}
	return ret;
}


int main() {
	int i, j;
	for_tests(t, tt) {
		scanf("%d", &n);	
		for(j = 1; j <= 3; j++)
			for(i = 0; i < n; i++)
				scanf("%d", &a[i][j]);
		memset(memo, -1, sizeof memo);
		printf("%d\n", solve(0, 280, 0));
	}
	return 0;
}

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

int sz[(1 << 15) + 1];
int memo[(1 << 13) + 1][1003];
int a[1003], n;
int to[1003];

int solve(int l, int i) {
	int r = to[i] - l;
	int &ans = memo[l][i];
	if(ans != -1) return ans;
	ans = 0; int aa = a[i];
	if(i == n) return ans = ((((l * r == 0) && !((l+r) & (l+r-1))) || ((l == r) && !(l & (l - 1)))));
	if(l == 0) ans |= solve(aa, i + 1);
	if(r == 0) ans |= solve(l,  i + 1);
	if(l && (l & -l) >= aa) ans |= solve(l + aa, i + 1);
	if(r && (r & -r) >= aa) ans |= solve(l, i + 1);
	return ans;
}


int main() {
	int i, j;
	for_tests(t, tt) {
		scanf("%d", &n);
		int tot = 0; to[0] = 0;
		memset(sz, 0, sizeof sz);
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			tot += a[i];
			to[i + 1] = tot;
			sz[tot] = i + 1;
		}
		//for(i = tot; i >= 0; i--)
		//	for(j = tot; j >= 0; j--) {
		//		memo[i][j] = 0;
		//		if((i || j) && !sz[i + j]) continue;
		//		if(sz[i + j] == n) { memo[i][j] = (((i * j == 0) && !((i+j) & (i+j-1))) || ((i == j) && !(i & (i - 1)))); continue; }
		//		int &ans = memo[i][j]; ans = 0; int aa = a[sz[i + j]];
		//		if(i == 0) ans |= memo[aa][j];
		//		if(j == 0) ans |= memo[i][aa];
		//		if(j && !(j & ((1 << __builtin_ctz(aa)) - 1))) ans |= memo[i][j + aa];
		//		if(i && !(i & ((1 << __builtin_ctz(aa)) - 1))) ans |= memo[i + aa][j];
		//	}
		memset(memo, -1, sizeof memo);
		solve(0, 0);
		if(!memo[0][0]) { puts("no"); continue; }
		int l = 0, r = 0; i = 0;
		while(i < n) {
			//printf("%d\n", i);
			r = to[i] - l; int aa = a[i];
			if(1 == memo[aa][i+1]) { putchar('l'); l = aa; i++; continue; }
			if(1 == memo[l][i+1]) { putchar('r'); i++; continue; }
			if(1 == memo[l + aa][i + 1]) { putchar('l'); l += aa; i++; continue; }
			if(1 == memo[l][i + 1]) { putchar('r'); i++; continue; }
		}
		putchar('\n');
	}
}

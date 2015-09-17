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
#define oo 10000000
int mask[10004];
int memo[10004];
int M;
int solve(int n) {
	if(n <= 0) return oo;
	if(n >= M) return n - M;
	int &m = memo[n];
	if(m != -1) return m;
	if(mask[n]) return oo;
	mask[n] = 1;
	m = min(1 + solve(n * 2), 1 + solve(n - 1));
	mask[n] = 0;
	return m;
}
int main() {
	int n; scanf("%d %d", &n, &M);
	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(n));
	return 0;
}

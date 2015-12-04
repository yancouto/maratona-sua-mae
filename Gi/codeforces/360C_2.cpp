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

char s[N];
int n, k;
ll memo[N][N];

ll solve(int i, int kk) {
	//printf("State %d %d\n", i, kk);
	if(i == n) return !kk;
	ll &m = memo[i][kk];
	if(m != -1) return m;
	m = mod(solve(i + 1, kk) * (s[i] - 'a' + !kk));
	for(int j = i; j < n; j++) {
		if(kk < (j - i + 1) * (n - i)) break;
		m = mod(m + mod(solve(j + 1, kk - (j - i + 1) * (n - i)) * ('z' - s[i])));
	}
	printf("State (%d, %d) = %d\n", i, kk, m);
	return m;
}

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	memset(memo, -1, sizeof memo);
	ll ans = solve(0, k);
	printf("ans ini %lld\n", ans);
	for(int i = 1; i < n; i++) {
		if(k < (i + 1) * (n - i)) break;
		ans = mod(ans + mod(solve(i + 1, k - (i + 1) * (n - i)) * ('z' - s[i])));
		printf("Somando solve(%d, %d) onde %d é maior\n", i+1, k - (i + 1) * (n - i), i);
	}
	for(int i = 1; i < n; i++) {
		ans = mod(ans + mod(solve(i + 1, k) * (s[i] - 'a')));
		printf("Somando solve(%d,%d) onde %d é menor\n", i+1, k, i);
	}
	printf("%lld\n", ans); 
	return 0;
}

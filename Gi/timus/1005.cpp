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

int n;
int p[30], tot;
int memo[20][1000005];

int solve(int i, int sum) {
	if(sum >= tot / 2) return abs(tot - sum - sum);
	if(i == n) return abs(tot - sum - sum);
	int &m = memo[i][sum];
	if(m != -1) return m;
	m = min(solve(i + 1, sum), solve(i + 1, sum + p[i]));
	return m;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		tot += p[i];
	}
	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(0, 0));
	return 0;
}

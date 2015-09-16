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
const ull modn = 1000;
inline ull mod(ull x) { return x % modn; }

int n, m;
int v[1000005];
int memo[1005][1005];

int solve(int i, int sum) {
	if(i == n) return sum == 0;
	int &mem = memo[i][sum];
	if(mem != -1) return mem;
	mem = solve(i + 1, sum);
	if(mem) return mem;
	mem = solve(i + 1, (sum + v[i]) % m);
	return mem;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	if(n > m) { puts("YES"); return 0; }
	memset(memo, -1, sizeof memo);
	for(int i = 0; i < n; i++) {
		int ans = solve(i + 1, v[i] % m);
		if(ans) { puts("YES"); return 0; }
	}
	puts("NO");
	return 0;
}

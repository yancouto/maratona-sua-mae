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

int seen[22][2], tempo;
ull memo[22][2];
ull solve(int i, bool pre)

int main() {
	ull A, B;
	for_tests(t, tt) {
		scanf("%llu %llu", &A, &B);
		sprintf(s, "%llu", B);
		tempo++;
		ull x = solve(0, true);
		sprintf(s, "%llu", A - 1);
		tempo++;
		ull y = solve(0, true);
		printf("Case %d: %llu\n", tt, x - y);
	}
}

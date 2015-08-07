#include <cstdio>
#include <cstring>
#include <algorithm>
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

int dir[6][2] = {{-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}};
int memo[50][50][50];
int solve(int i, int j, int k) {
	if(k == 0) return i == 0 && j == 0;
	int &r = memo[i+15][j+15][k];
	if(r != -1) return r;
	r = 0;
	for(int d = 0; d < 6; d++)
		r += solve(i + dir[d][0], j + dir[d][1], k - 1);
	return r;
}


int main() {
	int n;
	memset(memo, -1, sizeof memo);
	for_tests(t, tt) {
		scanf("%d", &n);
		printf("%d\n", solve(0, 0, n));
	}
}

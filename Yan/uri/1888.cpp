// Incompleto
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

double bit[3009][3009];
double get(int x, int yy) {
	double sum;
	for(x += 2; x; x -= (x & -x))
		for(int y = yy + 2; y; y -= (y & -y))
			sum += bit[x][y];
	return sum;
}
void add(int x, int yy, double val) {
	for(x += 2; x < 3009; x += (x & -x))
		for(int y = yy + 2; y; y += (y & -y))
			bit[x][y] += val;
}

int main() {
	for_tests(t, tt) {
		scanf("%d %d", &n, &m, &k);
		scanf(" %s %s", s1, s2);
		memo[n][m] = 0;
		for(i = 0; i <= n + 7; i++)
			for(j = 0; j <= m + 7; j++)
				bit[i][j] = 0;
		for(i = n; i >= 0; i--)
			for(j = m; j >= 0; j--) {
				if(i == n && j == m) continue;
				if(s1[i] == s2[j]) { memo[i][j] = memo[i+1][j+1]; add(i, j, memo[i][j]); continue; }
				memo[i][j] = 1/0.;
				if(i < n) 
				if(i == n) memo[i][j] = 
			}

		printf("%.3f\n", solve(0, 0));
	}
}

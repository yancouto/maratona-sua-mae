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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000009;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif

void cp(ull a[3][3], ull b[3][3]) {
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			b[i][j] = a[i][j];

}

void mult(ull a[3][3], ull b[3][3], ull c[3][3]) {
	int i, j, k;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++) {
			c[i][j] = 0;
			for(k = 0; k < 3; k++)
				c[i][j] = mod(c[i][j] + mod(a[i][k] * b[k][j]));
		}
}
ull aux[3][3];

void fexp(ull a[3][3], ull x, ull c[3][3]) {
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			c[i][j] = (i == j);
	for(ull u = 1; u <= x; u <<= 1) {
		if(u & x) {
			mult(c, a, aux);
			cp(aux, c);
		}
		mult(a, a, aux);
		cp(aux, a);
	}
}

ull base[3][3] = {
	{0, 0, 1},
	{1, 0, 1},
	{0, 1, 1}
};
ull a1[3][3], a2[3][3];

int main() {
	while(true) {
		ull n;
		scanf("%llu", &n);
		if(!n) return 0;
		cp(base, a1);
		fexp(a1, n - 1, a2);
		printf("%llu\n", mod(a2[1][0] + 2 * a2[2][0]));
	}
}
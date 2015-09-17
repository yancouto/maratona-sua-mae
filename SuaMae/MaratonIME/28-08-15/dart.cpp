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

int a[20] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};
ld memo[505][505][2];
ld solve(int nA, int nB, bool A) {
	if(nA <= 0) return 1.;
	if(nB <= 0) return 0.;
	ld &prob = memo[nA][nB][A];
	if(prob > -.5) return prob;
	prob = 0;
	if(A) {
		for(int i = 0; i < 20; i++)
			prob += solve(nA - a[i], nB, false);
		prob /= 20.;
	} else {
		for(int i = 0; i < 20; i++)
			prob = max(prob, 1. - (solve(nA, nB - a[(i+19)%20], true) + solve(nA, nB - a[i], true) + solve(nA, nB - a[(i+1)%20], true))/3.);
		prob = 1. - prob;
	}
	printf("(%d, %d, %d) = %Lf\n", nA, nB, A, prob);
	return prob;
}

int main() {
	int i, j, n;
	for(i = 0; i <= 502; i++)
		for(j = 0; j <= 502; j++)
			memo[i][j][0] = memo[i][j][1] = -1;
	while(true) {
		scanf("%d", &n);
		if(!n) return 0;
		printf("%.12Lf %.12Lf\n", solve(n, n, true), 1. - solve(n, n, false));
	}
}

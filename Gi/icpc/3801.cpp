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
const int MAX = 1005;
<<<<<<< HEAD
=======
const int oo = 200000000;
>>>>>>> origin/master

int n;
int mat[MAX][MAX];
int prec[MAX][MAX];
<<<<<<< HEAD
int memo[MAX][3];

int solve(int i, int lst) {
	if(i == n + 1) return 0;
	int &m = memo[i][lst];
	if(m != -1) return m;
	m = max(solve(i+1, 0), ((lst)?0:prec[i-1]) + prec[i] + solve(i+1, 1));
	return m;
=======
int memo[MAX][MAX];

int solve(int r, int c) {
	if(r < c) return 0;
	int &m = memo[r][c];
	if(m != -1) return m;
	return max(solve(r - 1, c), prec[r][c] + solve(min(r + 1, n), c + 1));
>>>>>>> origin/master
}

int main() {
	while(42) {
		scanf("%d", &n);
		if(!n) return 0;
		memset(memo, -1, sizeof memo);
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= i; j++)
				scanf("%d", &mat[i][j]);
		for(int c = 1; c <= n; c++) {
			int cur = 0;
			for(int l = c; l <= n; l++) {
				cur += mat[l][c];
				prec[l][c] = cur;
			}
		}
<<<<<<< HEAD
		printf("%d\n", max(solve(1, 1), 0));
=======
		printf("%d\n", solve(n, 1));
>>>>>>> origin/master
	}
	return 0;
}

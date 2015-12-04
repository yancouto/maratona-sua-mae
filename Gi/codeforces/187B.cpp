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
const int N = 65;

int n, m, r;
int g[N][N][N], memo[N][N][N];

int solve(int i, int j, int k) {
	//printf("State %d %d %d\n", i+1, j+1, k);
	if(i == j) return 0;
	int &me = memo[i][j][k];
	if(me != -1) return me;
	me = g[0][i][j];
	for(int l = 0; l < n; l++) 
		if(k > 0 && l != i) me = min(me, solve(i, l, k - 1) + g[0][l][j]);
	return me;
}

int main() {
	int s, t, k, i, j, l;
	scanf("%d %d %d", &n, &m, &r);
	for(k = 0; k < m; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &g[k][i][j]);
	for(k = 0; k < m; k++)
		for(l = 0; l < n; l++)
			for(i = 0; i < n; i++) 
				for(j = 0; j < n; j++) {
					if(g[k][i][j] > g[k][i][l] + g[k][l][j])
						g[k][i][j] = g[k][i][l] + g[k][l][j];
					g[0][i][j] = min(g[0][i][j], g[k][i][j]);
				}
	memset(memo, -1, sizeof memo);
	for(i = 0; i < r; i++) {
		scanf("%d %d %d", &s, &t, &k);
		s--; t--;
		printf("%d\n", solve(s, t, min(k, n + 1)));
	}
	return 0;
}

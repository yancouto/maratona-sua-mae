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
const int N = 100;
char g[N][N];
int v[N][N];
int n, m;
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int dfs(int i, int j, int d) {
	if(v[i][j]) return v[i][j];
	if(g[i][j] != '+') return dfs(i + di[d], j + dj[d], d);
	for(int d2 = 0; d2 < 4; d2++) {
		if(d2 == d || d2 == (d ^ 1)) continue;
		int ni = i + di[d2], nj = j + dj[d2];
		if(valid(ni, nj) && (g[ni][nj] == 45 || g[ni][nj] == 124))
			return dfs(ni, nj, d2);
	}
}



int main() {
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	int i, j, d;
	scanf("%d %d", &n, &m);
	int vn = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf(" %c", &g[i][j]);
			if(g[i][j] == 79) v[i][j] = ++vn;
		}
	printf("%d\n", vn);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(v[i][j])
				for(d = 0; d < 4; d++) {
					int ni = i + di[d], nj = j + dj[d];
					if(!valid(ni, nj) || (g[ni][nj] != 45 && g[ni][nj] != 124)) continue;
					int k = dfs(ni, nj, d);
					if(k > v[i][j]) printf("%d %d\n", v[i][j], k);
				}
}

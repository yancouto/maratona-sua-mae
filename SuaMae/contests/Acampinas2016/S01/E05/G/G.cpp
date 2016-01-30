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

#define i first
#define j second
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
const int N = 1002;
char g[N][N];
int fi[N][N], ds[N][N];
int n, m;

inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }

queue<pii> qf;
void bfs_f() {
	while(!qf.empty()) {
		pii p = qf.front(); qf.pop();
		for(int d = 0; d < 4; d++) {
			int ni = p.i + di[d], nj = p.j + dj[d];
			if(!valid(ni, nj) || fi[ni][nj] <= fi[p.i][p.j] + 1 || g[ni][nj] == '#') continue;
			fi[ni][nj] = fi[p.i][p.j] + 1;
			qf.push(pii(ni, nj));
		}
	}
}

void bfs(pii s) {
	queue<pii> q; q.push(s);
	ds[s.i][s.j] = 0;
	while(!q.empty()) {
		s = q.front(); q.pop();
		for(int d = 0; d < 4; d++) {
			int ni = s.i + di[d], nj = s.j + dj[d];
			if(!valid(ni, nj)) { printf("%d\n", ds[s.i][s.j] + 1); exit(0); }
			if(ds[ni][nj] <= ds[s.i][s.j] + 1 || fi[ni][nj] <= ds[s.i][s.j] + 1 || g[ni][nj] == '#') continue;
			ds[ni][nj] = ds[s.i][s.j] + 1;
			q.push(pii(ni, nj));
		}
	}
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	pii s;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf(" %c", &g[i][j]);
			fi[i][j] = ds[i][j] = INT_MAX;
			if(g[i][j] == 'J') s = pii(i, j), g[i][j] = '.';
			if(g[i][j] == 'F') fi[i][j] = 0, qf.push(pii(i, j)), g[i][j] = '.';
		}
	bfs_f();
	bfs(s);
	puts("IMPOSSIBLE");
}

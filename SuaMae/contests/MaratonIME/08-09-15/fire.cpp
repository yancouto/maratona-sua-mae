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

int L, H, W, N;
char g[12][102][102];
int v[12][102][102];
int p[102], co[102];
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < H && j < W; }

struct no {
	int i, j, l;
	int d;
	no() {}
	no(int a, int b, int c, int dd) : i(a), j(b), l(c), d(dd) {}
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int seen[102][102][102], tempo;
void bfs(pii s) {
	queue<no> q;
	q.push(no(s.fst, s.snd, 0, 0));
	tempo++;
	while(!q.empty()) {
		no x = q.front(); q.pop();
		if(v[x.l][x.i][x.j]) co[v[x.l][x.i][x.j] - 1] = 3 * x.d;
		for(int d = 0; d < 4; d++) {
			int ni = x.i + dx[d], nj = x.j + dy[d];
			if(!valid(ni, nj) || g[x.l][ni][nj] == 'X' || seen[ni][nj][x.l] == tempo) continue;
			seen[ni][nj][x.l] = tempo;
			q.push(no(ni, nj, x.l, x.d + 1));
		}
		if(g[x.l][x.i][x.j] == 'U' && seen[x.i][x.j][x.l + 1] < tempo) {
			seen[x.i][x.j][x.l + 1] = tempo;
			q.push(no(x.i, x.j, x.l + 1, x.d + 1));
		}
		if(g[x.l][x.i][x.j] == 'D' && seen[x.i][x.j][x.l - 1] < tempo) {
			seen[x.i][x.j][x.l - 1] = tempo;
			q.push(no(x.i, x.j, x.l - 1, x.d + 1));
		}
	}
}

int memo[102][10002];
int solve(int i, int left) {
	if(i == N) return 0;
	int &r = memo[i][left];
	if(r != -1) return r;
	r = solve(i + 1, left);
	if(co[i] <= left) r = max(r, p[i] + solve(i + 1, left - co[i]));
	return r;
}


int main() {
	int i, j, k, S, f, r, c;
	pii s;
	for_tests(t, tt) {
		scanf("%d %d %d %d %d", &L, &H, &W, &N, &S);
		for(k = 0; k < L; k++) {
			for(i = 0; i < H; i++)
				for(j = 0; j < W; j++) {
					scanf(" %c", &g[k][i][j]);
					if(g[k][i][j] == 'S') {
						s.fst = i; s.snd = j;
						g[k][i][j] = '.';
					}
					v[k][i][j] = 0;
				}
		}
		for(i = 0; i < N; i++) {
			scanf("%d %d %d %d", &f, &r, &c, &p[i]); 
			v[--f][--r][--c] = i + 1;
			co[i] = 100009;
		}
		bfs(s);
		memset(memo, -1, sizeof memo);
		printf("%d\n", solve(0, S));
	}
}

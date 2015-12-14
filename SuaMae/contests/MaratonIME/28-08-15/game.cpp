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

char g[4][4];
char aux[40][4][4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int c[20][4][4], cmp;
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < 4 && j < 4; }
void dfs(int mv, int i, int j) {
	if(c[mv][i][j]) return;
	c[mv][i][j] = cmp;
	for(int d = 0; d < 4; d++) {
		int ni = i + dx[d], nj = j + dy[d];
		if(!valid(ni, nj) || g[ni][nj] != g[i][j]) continue;
		dfs(mv, ni, nj);
	}
}

inline void mark(int mv) {
	int i, j;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			c[mv][i][j] = 0;
	cmp = 1;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			if(g[i][j] != '.' && !c[mv][i][j])
				dfs(mv, i, j), cmp++;
}
inline void cp(char a[4][4], char b[4][4]) {
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			b[i][j] = a[i][j];
}
int p3[18];
inline int id(int i, int j) { if(g[i][j] == 'R') return 2; if(g[i][j] == 'B') return 1; return 0; }
int calc() {
	int x = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			x += p3[j + i*4] * id(i, j);
	return x;
}

int seen[20][16];
pii v[20][16];
pii rem(int mv, int p, int co);
map<pii, pii> mp;
pii solve(int mv, int p) {
	int x = calc();
	int i, j;
	if(mp.count(pii(x, mv))) return mp[pii(x, mv)];
	mark(mv);
	for(i = 0; i <= cmp; i++) seen[mv][i] = 0;
	cp(g, aux[mv]);
	int k = 0;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			if(g[i][j] != '.' && !seen[mv][c[mv][i][j]])
				v[mv][k++] = (rem(mv, p, c[mv][i][j]));
	int sm = INT_MAX, bg = INT_MIN;
	for(i = 0; i < k; i++) {
		if(v[mv][i].fst == p) sm = min(sm, v[mv][i].snd);
		else bg = max(bg, v[mv][i].snd);
	}
	if(sm == INT_MAX) mp[pii(x, mv)] = pii(!p, bg);
	else mp[pii(x, mv)] = pii(p, sm);
	return mp[pii(x, mv)];
}
inline bool empty() {
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(g[i][j] != '.')
				return false;
	return true;
}

inline pii rem(int mv, int p, int co) {
	int i, j;
	seen[mv][co] = 1;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			if(c[mv][i][j] == co)
				g[i][j] = '.';
	for(j = 0; j < 4; j++) {
		int k = 3;
		for(i = 3; i >= 0; i--)
			if(g[i][j] != '.')
				swap(g[i][j], g[k--][j]);
	}
	pii pp = empty()? pii(p, mv + 1) : solve(mv + 1, !p);
	cp(aux[mv], g);
	return pp;
}

int main() {
	int i, j;
	p3[0] = 1;
	for(i = 1; i < 18; i++)
		p3[i] = 3 * p3[i-1];
	for_tests(t, tt) {
		mp.clear();
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				scanf(" %c", &g[i][j]);
		pii p = solve(0, 1);
		if(p.fst == 1) printf("Case %d: win %d\n", tt, p.snd);
		else printf("Case %d: loss %d\n", tt, p.snd);
	}
	return 0;
}

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
bool bl[9][9];
int iv[9][9], ih[9][9], x[100], cur[100], sz[100], cs[100], bm[100];
int n, m;
char g[9][9];

inline void us(int id, int v, int s) {
	cur[id] += v;
	sz[id] -= s;
	if(s > 0) bm[id] |= (1 << v);
	else assert(((bm[id] >> (-v)) & 1)), bm[id] ^= (1 << (-v));
}

int mx[2048][10], mn[2048][10];

void pre() {
	for(int b = 0; b < 2048; b++)
		for(int S = 0; S < 10; S++) {
			int tot = 0, sz = S;
			for(int i = 9; sz && i > 0; i--)
				if(!((b >> i) & 1))
					tot += i, sz--;
			mx[b][S] = tot;
			tot = 0; sz = S;
			for(int i = 1; sz && i <= 9; i++)
				if(!((b >> i) & 1))
					tot += i, sz--;
			mn[b][S] = tot;
		}
}

inline bool ok(int v, int id) {
	int B = bm[id] | (1 << v);
	bool b = cur[id] + v + mn[B][sz[id]-1] <= x[id] && cur[id] + v + mx[B][sz[id]-1] >= x[id];
	return b && ((bm[id] >> v) & 1) == 0;
}

pii st[100]; int sn;
void bt(int id) {
	int i = st[id].fst, j = st[id].snd;
	if(id == sn) {
		for(i = 0; i < n; i++) {
			putchar('_');
			for(j = 1; j < m; j++)
				putchar(' '), putchar(g[i][j]);
			putchar('\n');
		}
		exit(0);
	}
	for(int v = 1; v <= 9; v++)
		if(ok(v, iv[i][j]) && ok(v, ih[i][j])) {
			us(iv[i][j], v, 1); us(ih[i][j], v, 1);
			g[i][j] = '0' + v;
			bt(id + 1);
			us(iv[i][j], -v, -1); us(ih[i][j], -v, -1);
		}
}

int w[100][8];
void pre2(int i, int sz, int sum) {
	w[sum][sz]++;
	if(sz == 5 || i == 10) return;
	pre2(i + 1, sz, sum);
	pre2(i + 1, sz + 1, sum + i);
}


char s[10];
int main() {
	srand(time(NULL));
	int i, j;
	pre();
	pre2(1, 0, 0);
	for(j = 1; j <= 45; j++) {
		int cur = 1;
		printf("[%2d] ", j);
		for(i = 1; i <= 5; i++) {
			cur *= i;
			printf("%5d ", w[j][i] * cur);
		}
		putchar('\n');
	}
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			iv[i][j] = i * 6 + j; ih[i][j] = i * 6 + j + 50;
			scanf("%s", s);
			if(s[0] != '.') bl[i][j] = true, g[i][j] = '_';
			else {
				st[sn++] = pii(i, j);
				iv[i][j] = iv[i - 1][j]; ih[i][j] = ih[i][j - 1];
				sz[iv[i][j]]++; sz[ih[i][j]]++;
			}
			if(isdigit(s[0])) x[iv[i][j]] = atoi(s);
			if(isdigit(s[3])) x[ih[i][j]] = atoi(s + 3);
		}
	random_shuffle(st, st + sn);
	bt(0);
}

// TLE
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

int pos[102];
int sz[102];
int b[210000];

const int MAX = 201009;
struct no {
	int i; pii p;
	bool operator < (no o) const { return p < o.p; }
	bool operator == (no o) const { return p == o.p; }
	no() {}
	no(int x, int y, int z) : p(x, y), i(z) {}
} l[MAX], g[2*MAX];
int c[2*MAX];
int p[MAX][20], r[MAX], lc[MAX][20], n, lg;
char s[MAX];
int lcp_(int i, int j) {
	int t = 0;
	for(int k = lg - 1; k >= 0; k--)
		if(p[i + t][k] == p[j + t][k] && i + t + (1 << k) <= n && j + t + (1 << k) <= n)
			t += 1 << k;
	return t;
}
int d[256];
inline int lcp(int i, int j) {
	i = p[i][lg - 1]; j = p[j][lg - 1];
	if(i > j) swap(i, j); j--;
	int e = 31 - __builtin_clz(j - i + 1);
	return min(lc[i][e], lc[j - (1 << e) + 1][e]);
}

int main() {
	int i, j, k, m;
	scanf("%s", s); n = strlen(s);
	scanf("%d", &m); s[n++] = ';';
	for(i = 0; i < m; i++) {
		pos[i] = n;
		scanf("%s", s + n);
		sz[i] = strlen(s + n);
		n += sz[i];
		s[n++] = '|';
	}
	lg = 33 - __builtin_clz(n);
	memset(d, 0, sizeof d);
	for(i = 0; i < n; i++)
		d[s[i]]++;
	for(i = 1; i < 256; i++)
		d[i] += d[i-1];
	for(j = 0; j < lg; j++) {
		for(i = 0; i < n; i++) {
			if(j) l[i] = no(p[i][j - 1], i + (1 << (j - 1)) < n? p[i + (1 << (j - 1))][j - 1] : -n, i);
			else l[i] = no(d[s[i] - 1], -n, i);
			g[l[i].p.snd + c[l[i].p.snd + n]++ + n] = l[i];
		}
		int sz = 0;
		for(i = 0; i < 2*n; i++) {
			for(k = 0; k < c[i]; k++)
				l[sz++] = g[i + k];
			c[i] = 0;
		}
		assert(sz == n);
		for(i = 0; i < n; i++)
			g[l[i].p.fst + c[l[i].p.fst]++] = l[i];
		sz = 0;
		for(i = 0; i < n; i++) {
			for(k = 0; k < c[i]; k++)
				l[sz++] = g[i + k];
			c[i] = 0;
		}
		assert(sz == n);

		for(i = 0; i < n; i++)
			p[l[i].i][j] = i && l[i] == l[i - 1]? p[l[i - 1].i][j] : i;
	}
	for(i = 0; i < n; i++)
		r[p[i][lg - 1]] = i;
	for(i = 0; i < n - 1; i++)
		lc[i][0] = lcp_(r[i], r[i + 1]);
	for(j = 1; j < lg; j++)
		for(i = 0; i < n - 1; i++) {
			lc[i][j] = lc[i][j-1];
			if(i + (1 << (j - 1)) < n - 1)
				lc[i][j] = min(lc[i][j], lc[i + (1 << (j - 1))][j-1]);
		}
	int tot = 0;
	for(i = 0; i < m; i++) {
		if(sz[i] == 1) continue;
		for(j = 0; s[j] != ';'; j++)
			b[j] = INT_MAX;
		b[j] = INT_MAX;
		for(j = 0; s[j] != ';'; j++) {
			int lx = lcp(j, pos[i]);
			b[j + lx] = min(b[j + lx], sz[i] - lx);
			if(j) b[j] = min(b[j], b[j-1]);
		}
		for(j--; j >= 0; j--) {
			if(b[j+1] < sz[i] - 1)
				b[j] = min(b[j], b[j+1] + 1);
			b[j] = max(b[j], 1);
			if(b[j] == INT_MAX) continue;
			if(lcp(sz[i] - b[j] + pos[i], j) >= b[j]) break;
		}
		if(j >= 0) tot++;
	}
	printf("%d\n", tot);
}

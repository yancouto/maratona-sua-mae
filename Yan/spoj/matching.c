// TLE
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define true 1
#define false 0
int min(int a, int b) {
	if(a < b) return a;
	return b;
}
#define maxv 100009
#define maxe (250009 * 2)
typedef int num;
int n = maxv;

int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv];
num cp[maxe], fl[maxe];
num inf = INT_MAX;


int bfs(int s, int t) {
	int i, a, b;
	memset(lv, -1, sizeof(int) * n);
	lv[s] = 0;
	a = 0; b = 0;
	qu[b++] = s;
	while(a < b) {
		for(i = es[qu[a]]; i != -1; i = nx[i]) {
			if(cp[i] > fl[i] && lv[to[i]] == -1) {
				lv[to[i]] = lv[qu[a]] + 1;
				qu[b++] = to[i];
				if(to[i] == t) return true;
			}
		}
		a++;
	}
	return false;
}

int us[maxv], te, cr[maxv];
int dfs(int u, int t, num mx) {
	int i, a;
	if(u == t) return mx;
	if(us[u] == te) return 0;
	us[u] = te;
	for(i = cr[u]; i != -1; i = nx[i]) {
		if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1) {
			if(a = dfs(to[i], t, min(mx, cp[i] - fl[i]))) {
				fl[i] += a;
				fl[i ^ 1] -= a;
				cr[u] = i;
				return a;
			}
		}
	}
	cr[u] = i;
	return 0;
}


int max_flux(int s, int t) {
	int fl = 0, a, i;
	while(bfs(s, t)) {
		te++;
		for(i = 0; i < n; i++) cr[i] = es[i];
		while(a = dfs(s, t, inf))
			fl += a, te++;
	}
	return fl;
}

void reset_all(int n2) { n = n2; en = 0; memset(es, -1, sizeof(int) * n); }

void add_edge(int a, int b, int c, int rc) {
	fl[en] = 0; to[en] = b; cp[en] = c;  nx[en] = es[a]; es[a] = en++;
	fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
}

int main() {
	int i, n, m, p, a, b;
	scanf("%d %d %d", &n, &m, &p);
	reset_all(n + m + 2);
	for(i = 0; i < n; i++)
		add_edge(n + m, i, 1, 0);
	for(i = 0; i < m; i++)
		add_edge(n + i, n + m + 1, 1, 0);
	for(i = 0; i < p; i++) {
		scanf("%d %d", &a, &b); a--; b = b - 1 + n;
		add_edge(a, b, 1, 0);
	}
	printf("%d\n", max_flux(n + m, n + m + 1));
	return 0;
}

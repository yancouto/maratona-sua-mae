#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int tab[MAXN], n;
double dp[MAXN][MAXN];

double f(int pos, int tur) {
	if (tur == 0) return pos == n ? 1 : 0;
	if(tur < 0) return 0;
	if(pos == n) return 1;
	double &ret = dp[pos][tur];
	if(ret == -1) {
		ret = 0;
		for(int i = 1; i <= 6; i++) {
			int npos;
			if(i > n - pos) {
				npos = n - (i - (n - pos));
			} else {
				npos = pos + i;
			}
			if(tab[npos] == 1) ret += 1./6 * f(npos, tur - 2);
			else if(tab[npos] == 2) ret += 1./6 * f(0, tur - 1);
			else ret += 1./6 * f(npos, tur - 1);
		}
	}
	return ret;
}

int main() {
	int t, l, b;
	while(scanf("%d%d%d%d", &n, &t, &l, &b) && n) {
		for(int i = 0; i <= n; i++) {
			tab[i] = 0;
			for(int j = 1; j <= t; j++)
				dp[i][j] = -1;
		}
		while(l--) {
			int idx;
			scanf("%d", &idx);
			tab[idx] = 1;
		}
		while(b--) {
			int idx;
			scanf("%d", &idx);
			tab[idx] = 2;
		}
		printf("%.6lf\n", f(0, t));
	}
	return 0;
}

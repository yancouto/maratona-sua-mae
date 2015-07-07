#include <cstdio>
#include <cstring>
#include <algorithm>
typedef double ld;
using namespace std;

int C, D, H, S;
ld memo[17][17][17][17][5][5];

ld solve (int c, int d, int h, int s, int j1, int j2) {
	if (c >= C && d >= D && h >= H && s >= S)
		return 0;

	ld &m = memo[c][d][h][s][j1][j2];
	if (m > (ld)-0.5) return m;

	int left = 54 - (c + d + h + s);
	ld ans = 0;
	int cc, dd, hh, ss;
	int prob = 13-c;
	if (j1 == 1) prob++; if (j2 == 1) prob++;
	cc = prob;
	if (prob > 0) ans += ((ld)prob/left) * (1 + solve(c + 1, d, h, s, j1, j2));

	prob = 13-d;
	if (j1 == 2) prob++; if (j2 == 2) prob++;
	dd = prob;
	if (prob > 0) ans += ((ld)prob/left) * (1 + solve(c, d + 1, h, s, j1, j2));

	prob = 13-h;
	if (j1 == 3) prob++; if (j2 == 3) prob++;
	hh = prob;
	if (prob > 0) ans += ((ld)prob/left) * (1 + solve(c, d, h + 1, s, j1, j2));

	prob = 13-s;
	if (j1 == 4) prob++; if (j2 == 4) prob++;
	ss = prob;
	if (prob > 0) ans += ((ld)prob/left) * (1 + solve(c, d, h, s + 1, j1, j2));

	prob = 2 - (j1>0) - (j2>0);
	if (prob > 0) {
		double joker = 10000000;
		if (j1 == 0) {
			joker = min(joker, 1 + solve(c+1, d, h, s, 1, j2));
			joker = min(joker, 1 + solve(c, d+1, h, s, 2, j2));
			joker = min(joker, 1 + solve(c, d, h+1, s, 3, j2));
			joker = min(joker, 1 + solve(c, d, h, s+1, 4, j2));
		} else {
			joker = min(joker, 1 + solve(c+1, d, h, s, j1, 1));
			joker = min(joker, 1 + solve(c, d+1, h, s, j1, 2));
			joker = min(joker, 1 + solve(c, d, h+1, s, j1, 3));
			joker = min(joker, 1 + solve(c, d, h, s+1, j1, 4));
		}
		ans += ((ld)prob/left) * joker;
	}
	return m = ans;
}

void mem() {
	for (int i = 0; i <= 16; i++)
		for (int j = 0; j <= 16; j++)
			for (int k = 0; k <= 16; k++)
				for (int l = 0; l <= 16; l++)
					for (int m = 0; m <= 4; m++)
						for (int n = 0; n <= 4; n++)
							memo[i][j][k][l][m][n] = (ld)-1;
}

int main () {
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d %d %d %d", &C, &D, &H, &S);
		mem();	
		printf("Case %d: ", tt);
		if (C + D + H + S > 54 || (max(C-13,0) + max(D-13,0) + max(H-13,0) + max(S-13,0)) > 2)
			printf("-1.000\n");
		else {
			ld r = solve(0,0,0,0,0,0);
			if (r < 0.0000009)
				printf("0.000\n");
			else printf("%.3f\n", r);
		}
	}
	return 0;
}
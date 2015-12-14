#include <bits/stdc++.h>

using namespace std;

const int N = 503;

int mat[N][N];
int n, m, q, a, b, lo, hi, midl, midh;

int main () {
	while (scanf("%d %d", &n, &m) != EOF && n && m) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);

		scanf("%d", &q);

		while (q--) {
			int res = 0;
			scanf("%d %d", &a, &b);
			for (int i = -n+1; i < m; i++) {
				int lin, col;
				lin = max(-i, 0);
				col = max(i, 0);

				lo = 0;
				hi = min(min(n, m), min(n+i, m-i));
				midl = lo+(hi-lo)/2;
				while (lo < hi) {
					if (mat[lin+midl][col+midl] < a)
						lo = midl+1;
					else 
						hi = midl;
					midl = lo+(hi-lo)/2;
				}

				lo = 0;
				hi = min(min(n, m), min(n+i, m-i));
				midh = lo+(hi-lo)/2;
				while (lo < hi) {
					if (mat[lin+midh][col+midh] <= b)
						lo = midh+1;
					else 
						hi = midh;
					midh = lo+(hi-lo)/2;
				}
				res = max(res, midh-midl);
			}

			printf("%d\n", res);
		}
		printf("-\n");
	}
}

#include <cstdio>
#include <algorithm>
#include <cstring>
#define NMAX 105
using namespace std;

int n1, n2;
int p1[NMAX], p2[NMAX];
int memo[NMAX][NMAX];

int solve(int i, int j) {
	int ans = -1;
	if (i == n1 || j == n2) return 0;
	int &m = memo[i][j];
	if (m != -1) return m;

	if (p1[i] == p2[j]) ans = max(ans, 1 + solve(i+1, j+1));

	ans = max(ans, solve(i, j + 1));
	ans = max(ans, solve(i + 1, j));

	return m = ans;
}

int main() {
	scanf("%d%d", &n1, &n2);
	int c = 0;
	while (n1!=0 && n2!=0) {
		memset(memo, -1, sizeof(memo));
		int i;
		for (i = 0; i < n1; i++)
			scanf("%d", &p1[i]);
		for (i = 0; i < n2; i++)
			scanf("%d", &p2[i]);

		printf("Twin Towers #%d\n", ++c);
		printf("Number of Tiles : %d\n\n", solve(0,0));
		scanf("%d%d", &n1, &n2);
	}
	return 0;
}
//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1007
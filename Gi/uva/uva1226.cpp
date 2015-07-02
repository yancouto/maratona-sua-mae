#include <cstdio>
#include <cstring>
#include <algorithm>
#define NMAX 105
using namespace std;

int r, c;
int memo[NMAX][NMAX];
int A[NMAX][NMAX];

int solve (int i, int j) {
	int ans = -1;
	int stop = 1;
	int &m = memo[i][j];
	if (m != -1) return m;

	if (i > 0 && A[i][j] > A[i-1][j]) {
		stop = 0;
		ans = max(ans, 1 + solve(i - 1, j));
	}
	if (i < r - 1 && A[i][j] > A[i+1][j]) {
		stop = 0;
		ans = max(ans, 1 + solve(i + 1, j));
	}
	if (j > 0 && A[i][j] > A[i][j-1]) {
		stop = 0;
		ans = max(ans, 1 + solve(i, j - 1));
	}
	if (j < c - 1 && A[i][j] > A[i][j+1]) {
		stop = 0;
		ans = max(ans, 1 + solve(i, j + 1));
	}

	if (stop) return 1;

	return m = ans;
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		char name[NMAX];
		scanf("%s%d%d", name, &r, &c);
		int i, j;
		memset(memo, -1, sizeof(memo));
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				scanf("%d", &A[i][j]);
		int ans = -1;
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				ans = max(ans, solve(i, j));

		printf("%s: %d\n",name, ans);

	}

	return 0;
}

//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1226

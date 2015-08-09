#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1000000000

using namespace std;

int n;
int A[105][105], memo[105][105];

int solve (int i, int j) {
	int ans = -inf;
	if (i == n && j == n) return 0;
	int &m = memo[i][j];
	if (m != -1) return m;

	int sum = 0;
	for (int k = 0; k <= j; k++)
		sum += A[i][k];
	if (i + 1 <= n) {
		ans = max(ans, sum + solve(i + 1, j));
		ans = max(ans, solve(i + 1, j));
	}
	if (j + 1 <= n)
		ans = max(ans, solve(i, j + 1));

	return m = ans;
}

int main () {
	memset(memo, -1, sizeof(memo));
	scanf("%d", &n);
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	printf("%d\n", solve(0, 0));
	return 0;
}

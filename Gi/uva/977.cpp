#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
int num[10005];
int memo[10005][102];

int solve (int i, int sum) {
	int ans = -1;
	if (i == n) return (sum == 0);
	
	int &m = memo[i][sum];
	if (m != -1) return m;

	ans = max(ans, solve(i + 1, (sum + num[i]) % k));
	ans = max(ans, solve(i + 1, (sum - num[i]) % k));

	return m = ans;
}

int main () {
	int m;
	scanf("%d", &m);
	while (m--) {
		memset(memo, -1, sizeof(memo));
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) 
			scanf("%d", &num[i]);
		if (solve(0,0)) printf("Divisible\n");
		else printf("Not divisible\n");
	}
	return 0;
}
//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=977
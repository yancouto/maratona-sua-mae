#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1000000000

using namespace std;
int M, C;
int G[25][25];
int memo[25][205];

int solve (int cat, int money) {
	int ans = -inf;
	int &m = memo[cat][money];
	if (m != -1) return m;
	if (money < 0) return -inf;
	if (cat == C) return 0;

	for (int i = 0; i < G[cat][0]; i++) 
		ans = max(ans, G[cat][i+1] + solve(cat + 1, money - G[cat][i+1]));
	
	m = ans;
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(memo, -1, sizeof(memo));
		scanf("%d%d", &M, &C);
		for (int i = 0; i < C; i++) {
			int k;
			scanf("%d", &k);
			G[i][0] = k;
			for (int j = 0; j < k; j++)
				scanf("%d", &G[i][j+1]);
		}
		int a = solve(0, M);
		if (a < 0) printf("no solution\n");
		else printf("%d\n", a);

	}

	return 0;
}
//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2445
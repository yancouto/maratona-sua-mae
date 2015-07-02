#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 1000000000

using namespace std;

int v1, v2, T, d;
int memo[105][1200];


int solve (int t, int v) {
	if (t == T && v == v2) return v;
	
	if (t >= T) return -inf;
	int &m = memo[t][v];
	if (m != -1) return m;
	

	int ans = -inf, linf = -d;
	if (v - d < 0) linf = -v;
	for (int k = linf; k <= d; k++)
		ans = max(ans, v + solve(t + 1, v + k));

	return m = ans;
}

int main () {
	scanf("%d%d%d%d", &v1, &v2, &T, &d);
	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(1, v1));
	return 0;
}
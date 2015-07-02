#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int m, s;
char nmin[105], nmax[105];
int memo[105][905];


int solve (int i, int cs) {
	int ans = 0;
	if (i == m && cs == s) return 1;
	if (i >= m || cs > s) return 0;
	int &m = memo[i][cs];
	if (m != -1) return m;

	int fim = 0;
	if (i == 0) fim = 1;
	for (int k = 9; k >= fim; k--) 
		ans = max(ans, solve(i + 1, cs + k));

	return m = ans;
}

void buildmax (int i, int cs) {

	if (i == m && cs == s) return;
	if (i >= m || cs > s) return;

	int fim = 0;
	if (i == 0) fim = 1;
	for (int k = 9; k >= fim; k--) 
		if (solve(i + 1, cs + k) == 1) {
			printf("%d", k);
			buildmax(i + 1, cs + k);
			return;
		}

	return;
}

void buildmin (int i, int cs) {

	if (i == m && cs == s) return;
	if (i >= m || cs > s) return;
	
	int ini = 0;
	if (i == 0) ini = 1;
	for (int k = ini; k <= 9; k++) 
		if (solve(i + 1, cs + k) == 1) {
			printf("%d", k);
			buildmin(i + 1, cs + k);
			return;
		}

	return;
}

int main () {
	scanf("%d%d", &m, &s);
	memset(memo, -1, sizeof(memo));

	if (m == 1 && s == 0) printf("0 0\n");
	else if (solve(0,0) == 0) printf("-1 -1\n");
	else {
		buildmin(0, 0);
		printf(" ");
		buildmax(0, 0);
		printf("\n");
	}

	return 0;
}

//http://codeforces.com/problemset/problem/489/C
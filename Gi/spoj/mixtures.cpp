#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 100000000

using namespace std;

int n, m[105];
int memo[105][105];

int soma(int i, int j) {
	int s = 0;
	for (int k = i; k <= j; k++)
		s = s + m[k];
	s = s % 100;
	return s;
}

int solve(int i, int j) {
	int s = inf;
	int &r = memo[i][j];
	//printf("%d %d \n",i, j);
	
	if (r != -1) return r;
	if (i == j) return 0;
	for (int k = i; k < j; k++)
		s = min(s, solve(i, k) + solve(k + 1, j) + soma(i, k)*soma(k+1, j));
	r = s;
	return s;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < n; i++)
			scanf("%d", &m[i]);
		printf("%d\n", solve(0, n-1));
	}
	return 0;
}

//http://www.spoj.com/problems/MIXTURES/
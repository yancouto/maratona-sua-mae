#include <cstdio>
#include <cstring>


long long memo[1000000];

long long max(long long a, long long b) {
	if (a > b) return a;
	return b;
}

long long solve (long long n) {
	long long ans = 0;
	if (n < 1000000) if (memo[n] != -1) return memo[n];
	if (n == 1) return 0;
	
	if (n % 2 != 0) ans += 1 + solve(3*n + 1);
	else ans += 1 + solve(n/2);
	
	if (n < 1000000) memo[n] = ans;
	return ans;
}

int main() {
	int i, j;
	memset(memo, -1, sizeof(memo));
	while (scanf("%d %d", &i, &j) != EOF) {
		long long ans = -1;
		if (i > j) {
			for (int k = j; k <= i; k++) 
				ans = max(ans, solve(k) + 1);	
			printf("%d %d %lld\n", i, j, ans);
		} else {
			for (int k = i; k <= j; k++) 
				ans = max(ans, solve(k) + 1);	
			printf("%d %d %lld\n", i, j, ans);
		}
	}
	return 0;
}

//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=36
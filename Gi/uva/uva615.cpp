#include <cstdio>
#include <cstring>

int N;
int op[5];
long memo[8000][7];

long solve (int n, int coin) {
	long ans = 0;
	if (n == 0) return 1;
	if (n < 0 || coin == 5) return 0;
	
	long &m = memo[n][coin];
	if (m != -1) return m;
	ans += solve(n, coin + 1);
	for (int i = 0; i < n/op[coin]; i++) {
		ans += solve(n-(i+1)*op[coin], coin + 1);
	}

	m = ans;
	return ans;
}

int main() {
	op[0] = 50; 
	op[1] = 25; 
	op[2] = 10; 
	op[3] = 5; 
	op[4] = 1;
	memset(memo, -1, sizeof(memo));
	while (scanf("%d", &N) != EOF) {	
		printf("%ld\n", solve(N, 0));
	}

	return 0;
}

//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=615
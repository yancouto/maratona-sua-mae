#include <cstdio> 
#include <cstring>

int n, s;
long long memo[55][1005];
long long solve (int i, int csum) {
	long long ans = 0;
	if (i == n && csum == s) return 1;
	if (i == n) return 0;
	long long &m = memo[i][csum];
	if (m != -1) return m;
	for (int k = 0; k <= 9 && csum + k <= s; k++)
		ans += solve(i + 1, csum + k);

	return m = ans;
}

int main () {
	scanf("%d%d", &n, &s);
	if (s % 2 != 0) printf("0\n");
	else {
		s /= 2;
		memset(memo, -1, sizeof(memo));
		long long a = solve(0,0);
		printf("%lld\n", a*a);
	}
	return 0;
}

//http://acm.timus.ru/problem.aspx?space=1&num=1036
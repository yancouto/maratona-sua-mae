#include <cstdio>
#include <cstring>

int N;
long long memo[505][505];

long long solve (int total, int ant) {
	long long ans = 0;
	if (total == N && ant != N) return 1;
	if (total > N) return 0;
	long long &m = memo[total][ant];
	if (m != -1) return m;

	for (int i = ant + 1; i <= N - total; i++) {
		ans += solve(total + i, i);
	}

	return m = ans;
}

int main () {
	scanf("%d", &N);
	memset(memo, -1, sizeof(memo));
	printf("%lld\n", solve(0,0));
	return 0;
}



//http://acm.timus.ru/problem.aspx?space=1&num=1017
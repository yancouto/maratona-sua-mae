#include <cstdio>
#include <cstring>

int N, K;
int memo[2][45];

int solve (int ant, int i) {
	int ans = 0;
	if (i == N) return 1;
	int &m = memo[ant][i];
	if (m != -1) return m;

	ans += solve(0, i + 1);
	if (!ant) ans += solve(1, i + 1);

	return m = ans;
}

char seq[45];
int iseq, k;

void build(int ant, int i) {
	int a1 = 0, a2 = 0;
	if (i == N) {
		if (k == 1) {
			seq[iseq] = '\0';
			printf("%s\n", seq);
		} else
			printf("-1\n");

		return;
	}

	a1 = solve(0, i + 1);
	if (!ant) a2 = solve(1, i + 1);
	if (a1 >= k || ant) {
		seq[iseq++] = '0';
		build(0, i + 1);
	} else {
		k = k - a1;
		seq[iseq++] = '1';
		build(1, i + 1);
	}

	return;
}

int main () {
	scanf("%d%d", &N, &K); 
	memset(memo, -1, sizeof(memo));
	k = K; iseq = 0;
	build(0,0);
	return 0;	
}

//http://acm.timus.ru/problem.aspx?space=1&num=1081
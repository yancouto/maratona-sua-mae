#include <cstdio>
#include <cstring>
#include <algorithm>

int a[10], b[10], x[10];
int na, nb, n;
int memo[10][3][12];
int memo2[10][12];

int solve (int i, int ant, int dig) {
	printf("State(%d,%d,%d)\n", i, ant, dig);
	if (i == n) return 0;
	int &m = memo[i][ant][dig];
	if (m != -1) return m;
	
	int ans = 0;
	if (ant) {
		//printf("hashsa\n");
		int ini = 0;
		for (int k = ini; k < x[i]; k++)
			if (k == dig)
				ans += 1 + solve(i+1, 1, dig);
			else {
			//	printf("ini=%d x = %d, i = %d\n", ini, x[i], i);
				ans += solve(i+1, 0, dig);
			}
		ans += solve(i+1, 1, dig);
		if (dig == x[i])
			ans++;
	}
	else { 
		int ini = 0;
		for (int k = ini; k <= 9; k++) {
			if (k == dig && k == x[i])
				ans += 1 + solve(i+1, 1, dig);
			else if(k == dig)
				ans += 1 + solve(i+1, 0, dig);
			else if (k == x[i])
				ans += solve(i+1, 1, dig);
			else
				ans += solve(i+1, 0, dig);
		}
	}
	
	return m = ans;

}

int solve2 (int i, int dig) {
	if (i == n) return 0;
	int ans = 0;
	int &m = memo2[i][dig];
	for (int k = 0; k <= 9; k++)
		if (k == dig)
			ans += 1+ solve2(i+1, dig);
		else
			ans += solve2(i+1, dig);
	return m = ans;
}

int main () {
	int A, B;
	while (true) {
		int totA[10], totB[10];
		scanf("%d %d", &A, &B);
		if (A == 0 && B == 0) break;
		int num;
		memset(memo, -1, sizeof(memo));
		memset(memo2, -1, sizeof(memo2));
		na = 0; 
		num = A-1;
		while (num > 0) {
			a[na++] = num % 10;
			num/=10;
		}
		n = na;
		for (int i = 0; i < na; i++)
			x[n-i-1] = a[i];
		int resp = 0;
		for (int i = na-2; i >= 0; i++) {
			n = i+1;
			resp += solve2(0, 1);
		}
		n = na;
		resp += solve(0, 1, 1);
		printf("solve=%d\n", resp);

/*
		for (int i = 0; i <= 9; i++)		
			totA[i] = solve(0, 1, 0, i);

		for (int i = 0; i <= 9; i++)
			printf("%d ", totA[i]);
		printf("\n");
*/

/*
		memset(memo, -1, sizeof memo);
		nb = 0; num = B;
		while (num > 0) {
			x[nb++] = num % 10;
			num/=10;
		}
		n = nb;
		for (int i = 0; i <= 9; i++)		
			totB[i] = solve(0, 1, 0, i);

		for (int i = 0; i <= 9; i++)
			printf("%d ", totB[i]-totA[i]);
		printf("\n");
*/
	}
	return 0;
}
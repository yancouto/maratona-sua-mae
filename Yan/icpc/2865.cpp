#include <cstdio>
#include <cstring>
typedef unsigned long long ull;

int K[62];
int get(int i) {
	if(K[i] == -1) K[i] = get(__builtin_popcount(i)) + 1;
	return K[i];
}

int k;
ull l[2];
ull memo[2][62][2][62];
ull solve(int x, int d, bool pref, int num) {
	if(d == 61) return (get(num) + 1) == k;
	ull &m = memo[x][d][pref][num];
	if(m != -1) return m;
	m = 0;
	for(int i = 0; i <= 1; i++) {
		if(pref && i && !(l[x] & (1ull << (60 - d))))
			break;
		if(d < 60 || num)
			m += solve(x, d + 1, pref && (i == !!(l[x] & (1ull << (60 - d)))), num + i);
		else
			m += (k == 0);
	}
	return m;
}


int main() {
	memset(K, -1, sizeof K);
	K[0] = K[1] = 0;
	while(true) {
		scanf("%llu %llu %d", &l[0], &l[1], &k); l[0]--;
		if(!l[1]) return 0;
		memset(memo, -1, sizeof memo);
		printf("%llu\n", solve(1, 0, true, 0) - solve(0, 0, true, 0));
	}
}
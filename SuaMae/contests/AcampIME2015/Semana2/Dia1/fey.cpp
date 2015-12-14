#include <cstdio>

int main() {
	int n, i;
	while(true) {
		unsigned long long tot = 0;
		scanf("%d", &n);
		if(!n) return 0;
		for(i = 1; i <= n; i++) {
			tot += (n - i + 1) * (n - i + 1);
		}
		printf("%llu\n", tot);
	}
}
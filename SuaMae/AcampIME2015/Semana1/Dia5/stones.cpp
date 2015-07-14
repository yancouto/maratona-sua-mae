#include <cstdio>
typedef unsigned long long ull;

ull get(ull x) {
	if(x == 1ull) return 0;
	if(x % 2)
		return get(x - (x / 2) - 1);
	return x / 2;
}


int main() {
	int t, i;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		ull num = 0, x;
		for(i = 0; i < n; i++) {
			scanf("%llu", &x);
			num ^= get(x);
		}
		if(num) puts("YES");
		else puts("NO");
	}
	return 0;
}
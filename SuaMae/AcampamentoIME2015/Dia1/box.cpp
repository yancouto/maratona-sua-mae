#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int fib[46];

void pre() {
	fib[0] = fib[1] = 1;
	for(int i = 2; i < 46; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
}
int n;

ull solve(int x) {
	int f = *(upper_bound(fib, fib + 46, x) - 1);
	if(f == x) return 1;
	return solve(x - f) + 1;
}

int main() {
	pre();
	int t, x;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++) {
		ull tot = 1;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &x);
			tot *= solve(x);
		}
		printf("Case %d: %llu\n", tt, tot);
	}
	return 0;
}
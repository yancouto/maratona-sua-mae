#include <bits/stdc++.h>
using namespace std;

bool solve(bool rod, int a, int b, int left) {
	if(left >= 3) return solve(rod, a + left / 3, b, left % 3);
	if(a == 0 && b == 0) return !rod;
	if(a && rod == solve(!rod, a - 1, b, left + 1)) return rod;
	if(a && rod == solve(!rod, a - 1, b + 1, left)) return rod;
	if(b && rod == solve(!rod, a, b - 1, left + 1)) return rod;
	return !rod;
}

int main() {
	for(int i = 2;; i++)
		printf("%d -> %d\n", i, solve(true, i - 1, 0, 0));
}

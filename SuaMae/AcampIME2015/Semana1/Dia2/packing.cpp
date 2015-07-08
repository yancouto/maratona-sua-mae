#include <cstdio>

int main () {
	int t, l, w, h;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d %d %d", &l, &w, &h);
		if (l <= 20 && w <= 20 && h<= 20)
			printf("Case %d: good\n", tt);
		else
			printf("Case %d: bad\n", tt);

	}
	return 0;
}
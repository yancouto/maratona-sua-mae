// WAAAAAAAA
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

int main() {
	int t, x, y;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++) {
		int h, w;
		scanf("%d %d", &h, &w);
		ull tot = 0; 
		for(x = 0; x < w; x++)
			for(y = 0; y < h; y++) {
				ull a = min((h - y) / 2, min(w - x, x));
				ull b = min(y / 2, min(w - x, x));
				ull c = min(x / 2, min(y, h - y));
				ull d = min((w - x) / 2, min(y, h - y));
				printf("(%d, %d) = %llu\n", x, y, a*b+c*d);
				// printf("(%d, %d) -> up %llu left %llu\n", x, y, up, left);
				tot += (a * b + c * d);// - min(a, b) - min(c, d);
			}
		printf("Case %d: %llu\n", tt, tot);
	}
	return 0;
}
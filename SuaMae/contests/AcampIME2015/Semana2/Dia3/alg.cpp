#include <algorithm>
#include <cstdio>
using namespace std;

char str[100009];
int nx[100009], ny[100009], nz[100009];
int main() {
	scanf(" %s", str);
	int i, q, l, r, x, y, z;
	for(i = 1; str[i-1]; i++) {
		nx[i] = nx[i-1] + (str[i-1] == 'x');
		ny[i] = ny[i-1] + (str[i-1] == 'y');
		nz[i] = nz[i-1] + (str[i-1] == 'z');
	}
	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		scanf("%d %d", &l, &r);
		if((r - l + 1) < 3) {
			puts("YES");
			continue;
		}
		x = nx[r] - nx[l - 1];
		y = ny[r] - ny[l - 1];
		z = nz[r] - nz[l - 1];
		int m = min(min(x, y), z);
		if((x-m)<=1&&(y-m)<=1&&(z-m)<=1) puts("YES");
		else puts("NO");
	}
	return 0;
}

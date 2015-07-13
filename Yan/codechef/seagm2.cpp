// WA
#include <cstdio>
#include <cmath>

long double ps[15];

int main() {
	int t, i, j; double d;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) {
			ps[i] = 1;
			for(j = 0; j < m; j++) {
				scanf("%lf", &d);
				ps[i] *= d;
			}
			if(i > 0)
				ps[i] += ps[i - 1];
		}
		if(std::isfinite(ps[0] / ps[n - 1])) printf("%.6Lf\n", ps[0] / ps[n - 1]);
		else puts("0.000000");
	}
	return 0;
}
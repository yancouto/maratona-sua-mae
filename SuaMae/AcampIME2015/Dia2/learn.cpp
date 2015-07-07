#include <cstdio>
int p[103];
int to[103];
int main() {
	int t, i, x, y, v;
	scanf("%d", &t);
	for(int tt = 1; tt <= t; tt++) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			to[i] = -1;
		}
		for(i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			if(to[x] == -1) to[x] = y;
			else if(p[to[x]] < p[y]) to[x] = y;
		}
		int tot = 0, prev = 0;
		for(i = 0; i != -1;) {
			tot += p[i];
			prev = i;
			i = to[i];
		}
		printf("Case %d: %d %d\n", tt, tot, prev);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int r, n;
const int N = 120;
int x[N], y[N], p[N];
int dist(int i, int j) {
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

bool bad1(int xx, int i) { return x[i] - r >= xx || x[i] + r <= xx; }
bool bad2(int xx, int i) { return x[i] - r >= xx || x[i] + r <  xx; }
bool bad3(int xx, int i) { return x[i] - r >  xx || x[i] + r <= xx; }

int sweep(int xx, bool (*bad)(int, int )) {
	int i, j;
	int mx = 1, cur = 0;
	for(i = 0; i < n; i++) {
		if(bad(xx, p[i])) continue;
		cur = 1;
		for(j = i + 1; j < n; j++) {
			if(bad(xx, p[j])) continue;
			if(dist(p[i], p[j]) > 4 * r * r) break;
			cur++;
		}
		mx = max(mx, cur);
	}
	return mx;
}

int ev[40114];
int main() {
	int i, R;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]), p[i] = i;
	sort(p, p + n, [](int i, int j) { return y[i] < y[j]; });
	scanf("%d %d", &R, &r);
	if(R < r) { puts("0"); return 0; }
	if(R == r) { puts("1"); return 0; }
	r = R - r;
	for(i = 0; i < n; i++) {
		ev[20008 + x[i] - r] = 1;
		ev[20008 + x[i] + r] = 1;
	}
	int mx = 1;
	for(i = -20004; i <= 20004; i++)
		if(ev[20008 + i]) {
			//mx = max(mx, sweep(i, bad1));
			mx = max(mx, sweep(i, bad2));
			mx = max(mx, sweep(i, bad3));
		}
	printf("%d\n", mx);
}

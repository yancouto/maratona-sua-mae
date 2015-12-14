#include <bits/stdc++.h>

using namespace std;

const int N = 200;

pair<int, int> tim[N];
int n, t;
int res[N], val[N];

int main () {
	freopen("cubes.in", "r", stdin);

	scanf("%d", &t);

	for (int ts = 1; ts <= t; ts++) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &val[i]);
			tim[i].second = -i;
			tim[i].first = i*(n-i-1) + 1 + i + n-i-1;
		}
		
		sort(tim, tim+n);
		sort(val, val+n);

		for (int i = 0; i < n; i++) {
			res[-tim[i].second] = val[n-i-1];
		}

		printf("Case %d:\n", ts);
		for (int i = 0; i < n; i++) {
			if (i) printf(" ");
			printf("%d", res[i]);
		}
		printf("\n");
	}
}

#include <bits/stdc++.h>

using namespace std;

int a, b;
int da, db;

int main () {
	int t;
	freopen("ghanophobia.in", "r", stdin);
	scanf("%d", &t);
	for (int ts = 1; ts <= t; ts++) {
		scanf("%d:%d", &da, &db);
		a = 1;
		b = 6;
		a += da;
		b += db;
		
		if (a == b) {
			a = 2+da;
			b = 6+2*db;
		}

		printf("Case %d: ", ts);
		if (a == b)
			printf("PENALTIES\n");
		else if (a < b)
			printf("NO\n");
		else
			printf("YES\n");
	}
}

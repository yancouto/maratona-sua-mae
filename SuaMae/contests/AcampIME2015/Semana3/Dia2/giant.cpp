#include <bits/stdc++.h>

using namespace std;

struct tv {
	int rh, rv, sh, sv;
};

int fill (tv b, tv s) {
	int h = max((b.rh-1)/s.rh, (b.sh-1)/s.sh)+1;
	int v = max((b.rv-1)/s.rv, (b.sv-1)/s.sv)+1;
//	printf("%d %d %d %d\n", b.rh, b.rv, b.sh, b.sv);
//	printf("%d %d %d %d\n", s.rh, s.rv, s.sh, s.sv);
//	printf("needs %d\n", h*v);
	return h*v;
}

int main () {
	int n;
	tv big, aux1, aux2;
	while (scanf("%d %d %d %d", &big.rh, &big.rv, &big.sh, &big.sv) != EOF) {
		scanf("%d", &n);

		int mini = INT_MAX;
		int cost;

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d %d %d", &aux1.rh, &aux1.rv, &aux1.sh, &aux1.sv, &cost);
			aux2.rh = aux1.rv;
			aux2.sh = aux1.sv;
			aux2.rv = aux1.rh;
			aux2.sv = aux1.sh;

			mini = min(mini, min(cost*(fill(big, aux1)), cost*fill(big, aux2)));
		}

		printf("%d\n", mini);
	}
}


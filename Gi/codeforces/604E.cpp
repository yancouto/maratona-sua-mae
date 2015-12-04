#include <stdio.h>
#include <stdlib.h>

int value(int a, int k) {
	int s;

	if(k % 2 == 0) {
		if(a < 3) return a;
		return (a + 1) % 2;
	}
	if(a < 4) return a % 2;
	if(a % 2 != 0) return 0;
	for(s = 0; a % 2 == 0; a /= 2) {
		s++;
	}
	if(a == 3) {
		s++;
	}
	return 2 - (s % 2);
}

int main() {
	int n, k, a, v;

	scanf("%d%d", &n, &k);
	v = 0;
	while(n--) {
		scanf("%d", &a);
		printf("valor %d\n", value(a, k));
		v ^= value(a, k);
	}
	if(v) {
		printf("Kevin\n");
	} else {
		printf("Nicky\n");
	}

	return 0;
}

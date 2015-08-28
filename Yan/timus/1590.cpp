#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull modn = 3000017;
inline ull mod(ull x) { return x % modn; }
const ull modn2 = 3000029;
inline ull mod2(ull x) { return x % modn2; }
char str[5009];
int ha[modn], hb[modn];
ull pot[5009], pot2[5009];

int main() {
	int i, n, j;
	scanf("%s", str);
	n = strlen(str);
	int tot = 0;
	pot[0] = pot2[0] = 1;
	for(i = 1; i <= n; i++) {
		pot[i] = mod(pot[i - 1] * 37ull);
		pot2[i] = mod2(pot2[i - 1] * 263ull);
	}
	for(i = 0; i < n; i++) {
		ull h = 0;
		ull h2 = 0;
		for(j = i; j < n; j++) {
			h = mod(h + pot[j - i] * (str[j] - 'a' + 1));
			h2 = mod2(h2 + pot2[j - i] * str[j]);
			if(!ha[h] || !hb[h2]) tot++;
			ha[h] = 1; hb[h2] = 1;
		}
	}
	printf("%d\n", tot);
	return 0;
}

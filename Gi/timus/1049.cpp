#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int ddiv[10005];
int n;

void calc_div() {
	while(n % 2 == 0) { ddiv[2]++; n /= 2; }
	for(int i = 3; i*i <= n; i += 2) {
		if(n % i) continue;
		while(n % i == 0) { ddiv[i]++; n /= i; }
	}
	if(n > 1) ddiv[n]++;
}

int main() {
	for(int i = 0; i < 10; i++) {
		scanf("%d", &n);
		calc_div();
	}
	int ans = 1;
	for(int i = 1; i <= 10000; i++) {
		if(ddiv[i]) ans = (ans * (ddiv[i] + 1)) % 10;
	}
	printf("%d\n", ans);
	return 0;
}

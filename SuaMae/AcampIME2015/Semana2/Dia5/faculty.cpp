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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
ull divs[32];
ull num[32];
int dn;
ull n, k;

ull times(ull u) {
	ull a = n;
	ull t = 0;
	while(a) {
		a /= u;
		t += a;
	}
	return t;
}

int main() {
	for_tests(t, tt) {
		scanf("%llu %llu", &n, &k);
		dn = 0;
		for(ull i = 2; i*i <= k; i++) {
			if((k%i) == 0) {
				//printf("adding %llu\n", i);
				divs[dn] = i;
				num[dn++] = 0;
				while((k%i) == 0) {
					k /= i;
					num[dn - 1]++;
				}
			}
		}
		if(dn == 0) { printf("%llu\n", times(k)); continue; }
		if(k != 1) {
			divs[dn] = k;
			num[dn++] = 1;
		}
		ull tim = ULLONG_MAX;
		for(int i = 0; i < dn; i++) {
			//printf("div[%d] = %d || %d\n", i, divs[i], num[i]);
			tim = min(tim, times(divs[i]) / num[i]);
		}
		printf("%llu\n", tim);
	}
	return 0;
}

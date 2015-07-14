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
int n;
ull mdc[100009];
int pos[100009];
int mi;

ull gcd(ull a, ull b) {
	if(a < b) return gcd(b, a);
	if(b == 0) return a;
	return gcd(b, a % b);
}
ull mx;

int main() {
	int i, j, lx, lp;
	ull x;
	for_tests(t, tt) {
		mi = 0;
		scanf("%d", &n);
		scanf("%llu", &x);
		pos[mi] = 0;
		mdc[mi++] = x;
		mx = x;
		for(i = 1; i < n; i++) {
			scanf("%llu", &x);
			while(mi > 0 && gcd(x, mdc[mi - 1]) <= mdc[mi - 1]) {
				mi--;	
				lx = mdc[mi];
				lp = pos[mi];
			}
			pos[mi] = lp;
			mdc[mi++] = gcd(lx, x);
			if(mdc[mi - 1] != x) {
				pos[mi] = i;
				mdc[mi++] = x;
			}
			for(j = 0; j < mi; j++) {
				// printf("i%d pos[%d] = %d mdc %llu\n", i, j, pos[j], mdc[j]);
				if(mdc[j] * (i - pos[j] + 1) > mx)
					mx = mdc[j] * (i - pos[j] + 1);
			}
		}
		printf("%llu\n", mx);
	}
	return 0;
}
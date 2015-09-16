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

int tab[4], mv[3];

int sh(int m, int d) {
	if(d >= 0) return m << d;
	else return m >> (-d);
}

bool check(int mask) {
	int t[4] = {tab[0], tab[1], tab[2], tab[3]};
	for(int i = 0; i < 4; i++) 
		for(int j = 0; j < 4; j++) {
			int k = 1 << (i * 4 + j);
			if(k & mask) {
				for(int k = -1; k <= 1; k++) {
					if(i + k < 0) continue;
					if(i + k > 3) continue;
					t[i+k] = (t[i+k] ^ sh(mv[k+1], j-1));
				}
			}
		}
	bool yes = true;
	for(int i = 0; i < 4 && yes; i++) 
		if((t[i] & 0xf) != 0xf) yes = false;
	if(yes) return true;
	yes = true;
	for(int i = 0; i < 4 && yes; i++) 
		if(t[i] & 0xf) yes = false;
	return yes;
}


int main() {
	for(int i = 0; i < 4; i++) {
		tab[i] = 0;
		for(int j = 0; j < 4; j++) {
			char c; scanf(" %c", &c);
			if(c == 'B') 
				tab[i] = (tab[i] | (1 << j));
		}
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			char c; scanf(" %c", &c);
			if(c == '1')
				mv[i] = (mv[i] | (1 << j));
		}
	}
	int ans = INT_MAX;
	for(int mask = 0; mask < (1 << 16); mask++) {
		if(check(mask))
			ans = min(ans, __builtin_popcount(mask));
	}
	if(ans == INT_MAX) puts("Impossible");
	else printf("%d\n", ans);
	return 0;
}

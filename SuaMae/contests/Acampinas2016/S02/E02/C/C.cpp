#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

inline bool leap(int y) { return ((y % 400) == 0) || (((y % 4) == 0) && (y % 100)); }
int mo[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline int mon(int m, int y) {
	return leap(y) && m == 1? 29 : mo[m];
}

ll ct[13], freq[13], bk[400];

int main() {
	int s = 5;
	int d = 0;
	int y = 2000;
	int m = 0;
	int s13 = 0, a, b, i;
	while(true) {
		d++; s++;
		if(s == 7) s = 0;
		if(d == mon(m, y)) d = 0, m++;
		if(m == 12) { ct[s13]++; bk[y - 2000] = s13; m = 0, y++, s13 = 0; }
		if(s == 4 && d == 12) s13++;
		if(!(y % 400) && m == 0 && d == 0 && s == 5)
			break;
	}
	scanf("%d %d", &a, &b);
	for(; a <= b && (a % 400); a++) freq[bk[a % 400]]++;
	for(; a <= b && (b % 400); b--) freq[bk[b % 400]]++;
	if(a <= b) freq[bk[0]]++;
	ll mult = max(0, b - a) / 400;
	for(i = 0; i < 13; i++) freq[i] += mult * ct[i];
	for(i = 0; i < 13; i++) printf("%d: %lld\n", i, freq[i]);
}

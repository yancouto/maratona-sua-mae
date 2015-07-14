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

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


struct day {
	int d, y, m, c;
	bool bissex() {
		return ((y % 4) == 0 && (y % 100)) || ((y % 400) == 0);
	}
	bool after(day d1) {
		if(d > 1) {
			return d == (d1.d + 1) && y == d1.y && m == d1.m;
		} // d == 1
		if(m > 1) {
			if(m != 3 || !bissex()) return d1.m == (m - 1) && d1.d == month[m - 1] && y == d1.y;
			return d1.m == 2 && d1.d == 29 && y == d1.y;
		} // m == 1
		return d1.y == (y - 1) && d1.d == 31 && d1.m == 12;
	}
	void read() {
		scanf("%d %d %d %d", &d, &m, &y, &c);
	}
	void prn() {
		printf("%d/%d/%d\n", d, m, y);
	}
};

int main() {
	day d1, d2;
	while(true) {
		scanf("%d", &n);
		if(!n) return 0;
		d1.read();
		int count = 0; int val = 0;
		for(int i = 1; i < n; i++) {
			d2.read();
			if(d2.after(d1))  {
				count++;
				val += d2.c - d1.c;
			}
			d1 = d2;
		}
		printf("%d %d\n", count, val);
	}
}
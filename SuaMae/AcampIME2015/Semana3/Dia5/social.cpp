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
int n, m;
struct cons {
	 int a, b, c;
} cs[30];

int p[10];
int main() {
	int i, j, x;
	while(true) {
		scanf("%d %d", &n, &m);
		if(!n) return 0;
		for(i = 0; i < n; i++)
			p[i] = i;
		for(i = 0; i < m; i++) {
			 scanf("%d %d %d", &cs[i].a, &cs[i].b, &cs[i].c);
		}
		int count = 0;
		do {
			for(i = 0; i < m; i++) {
				cons &c = cs[i];
				if(c.c < 0) {
					if(abs(p[c.a] - p[c.b]) < -c.c)
						break;
					 
				}
				else if(abs(p[c.a] - p[c.b]) > c.c)
					break;
			}
			if(i == m) count++;

		} while(next_permutation(p, p + n));
		printf("%d\n", count);
	}
}

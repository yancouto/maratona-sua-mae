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

int tab[55][55];

int main() {
	for_tests(t, tt) {
		int n, r, x, y, l, c, i, j, dir;
		scanf("%d %d", &n, &r);
		memset(tab, 0, sizeof tab);
		for(i = 0; i < r; i++)
			scanf("%d %d", &x, &y), tab[y][x] = 1;
		scanf("%d %d", &x, &y);
		if(x == 0 || x > n) { dir = 1 + (x == 0); l = y; c = x; }  
		if(y == 0 || y > n) { dir = 3 + (y == 0); c = x; l = y; }  
		while(42) {
			if(dir == 1) {
				for(j = c-1; j >= 1 && !tab[l][j]; j--);
				if(j == 0) { printf("%d %d\n", j, l); break; }
				dir = 4; c = j;
			}
			else if(dir == 2) {
				for(j = c+1; j <= n && !tab[l][j]; j++);
				if(j > n) { printf("%d %d\n", j, l); break; }
				dir = 3; c = j;
			}
			else if(dir == 3) {
				for(i = l-1; i >= 1 && !tab[i][c]; i--);
				if(i == 0) { printf("%d %d\n", c, i); break; }
				dir = 1; l = i;
			}
			else if(dir == 4) {
				for(i = l+1; i <= n && !tab[i][c]; i++);
				if(i > n) { printf("%d %d\n", c, i); break; }
				dir = 2; l = i;
			}
		}
	}
	return 0;
}

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
char grid[13][13];
int mx;
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < 10 && j < 10; }

int seen[13][13];
int dirs[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
void solve(int x, int y, int count) {
	if(count > mx) mx = count;
	for(int di = 0; di < 4; di++) {
		int x2 = x + dirs[di][0], y2 = y + dirs[di][1];
		int x3 = x + 2*dirs[di][0], y3 = y + 2*dirs[di][1];
		if(valid(x2, y2) && valid(x3, y3) && !seen[x2][y2] && grid[x2][y2] == 'B' && grid[x3][y3] == '#') {
			seen[x2][y2] = 1;
			solve(x3, y3, count + 1);
			seen[x2][y2] = 0;
		}
	}
}


int main() {
	int i, j;
	for_tests(t, tt) {
		for(i = 0; i < 10; i++)
			scanf(" %s", grid[i]);
		mx = 0;
		for(i = 0; i < 10; i++)
			for(j = 0; j < 10; j++)
				if(grid[i][j] == 'W') {
					grid[i][j] = '#';
					solve(i, j, 0);
					grid[i][j] = 'W';
				}
		printf("%d\n", mx);
	}
}
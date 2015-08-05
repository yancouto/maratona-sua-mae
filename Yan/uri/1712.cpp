// WA ??
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
int g[52][52], n, m;
int mx;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int seen[52][52];
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < n; }
void s(int i, int j, int l, int sum) {
	if(seen[i][j]) return;
	if(l == 0) { mx = max(mx, sum); return; }
	seen[i][j] = 1;
	for(int d = 0; d < 4; d++) {
		int ni = i + dir[d][0], nj = j + dir[d][1];
		if(!valid(ni, nj)) continue;
		s(ni, nj, l - 1, sum + g[ni][nj]);
	}
	seen[i][j] = 1;
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	mx = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			s(i, j, m - 1, g[i][j]);
	printf("%d\n", mx);
	return 0;
}

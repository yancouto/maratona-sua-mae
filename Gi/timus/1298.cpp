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

int n;

bool isIn(int i, int j) {
	return (i >= 0) && (i < n) && (j >= 0) && (j < n);
}

void imp(int i, int j) {
	printf("%c%d\n", i + 'a', j + 1);
}

vector<pii> adj[10][10];
void add_edge(int i, int j) {
	if(isIn(i+1, j-2)) adj[i][j].pb(pii(i+1, j-2));
	if(isIn(i+2, j-1)) adj[i][j].pb(pii(i+2, j-1));
	if(isIn(i+2, j+1)) adj[i][j].pb(pii(i+2, j+1));
	if(isIn(i+1, j+2)) adj[i][j].pb(pii(i+1, j+2));
	if(isIn(i-1, j+2)) adj[i][j].pb(pii(i-1, j+2));
	if(isIn(i-2, j+1)) adj[i][j].pb(pii(i-2, j+1));
	if(isIn(i-2, j-1)) adj[i][j].pb(pii(i-2, j-1));
	if(isIn(i-1, j-2)) adj[i][j].pb(pii(i-1, j-2));
}

int mark[10][10];

bool dfs(int i, int j, int sz) {
	if(sz == n * n) { imp(i, j); return true; }
	mark[i][j] = 1;
	for(int k = 0; k < adj[i][j].size(); k++) {
		int x = adj[i][j][k].fst;
		int y = adj[i][j][k].snd;
		if(mark[x][y]) continue;
		if(dfs(x, y, sz + 1)) {
			imp(i, j);
			return true;
		}
	}
	mark[i][j] = 0;
	return false;
}

int main() {
	scanf("%d", &n);	
	if(n == 1) { puts("a1"); return 0; }
	bool r = false;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) 
			add_edge(i, j);
	for(int i = 0; i < n && !r; i++)
		for(int j = 0; j < n && !r; j++) 
			r = dfs(i, j, 1);	
	if(r) return 0;
	puts("IMPOSSIBLE");
	return 0;
}

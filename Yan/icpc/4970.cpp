// TLEEEE
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
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n; ull l;
ull adj[15][15];
vector<ull> v[1<<14][14][14];

int pos[15];

void create(int bm, int fst, int lst, ull tot) {
	int used = __builtin_popcount(bm);
	if(used == (n + 1) / 2) {
		if(fst <= lst)
			v[bm][fst][lst].pb(tot);
		return;
	}
	for(int i = n - used - 1; i >= 0; i--) {
		int j = pos[i];
		swap(pos[i], pos[n - used - 1]);
		create(bm | (1 << j), fst, j, tot + adj[lst][j]);
		swap(pos[i], pos[n - used - 1]);	
	}
}

bool create2(int bm, int fst, int lst, ull tot) {
	int used = __builtin_popcount(bm);
	if(used == (n/2)) {
		if(fst > lst) return false;
		int opp = (((1 << n) - 1) ^ bm);
		int x, y;
		for(int i = n - used - 1; i >= 0; i--) {
			for(int j = i - 1; j >= 0; j--) {
				x = pos[i];
				y = pos[j];
				if(x > y) continue;
				if(binary_search(v[opp][x][y].begin(), v[opp][x][y].end(), l - tot - adj[fst][x] - adj[lst][y]))
					return true;
				if(binary_search(v[opp][x][y].begin(), v[opp][x][y].end(), l - tot - adj[fst][y] - adj[lst][x]))
					return true;
			}
		}
		return false;
	}
	for(int i = n - used - 1; i >= 0; i--) {
		int j = pos[i];
		swap(pos[i], pos[n - used - 1]);
		if(create2(bm | (1 << j), fst, j, tot + adj[lst][j]))
			return true;
		swap(pos[i], pos[n - used - 1]);
	}
	return false;
}

int main() {
	int i, j, k;
	while(scanf("%d %llu", &n, &l) != EOF) {
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%llu", &adj[i][j]);
		if(n == 2) {
			if(adj[0][1] * 2llu == l) puts("possible");
			else puts("impossible");
			continue;
		}
		for(i = 0; i < n; i++) pos[i] = i;
		for(i = 0; i < (1 << n); i++)
			for(j = 0; j < n; j++)
				for(k = j + 1; k < n; k++)
					v[i][j][k].clear();
		for(i = 0; i < n - 1; i++) {
			swap(pos[i], pos[n - 1]);
			create(1 << i, i, i, 0);
			swap(pos[i], pos[n - 1]);
		}
		for(i = 0; i < (1 << n); i++)
			for(j = 0; j < n; j++)
				for(k = j + 1; k < n; k++) {
					sort(v[i][j][k].begin(), v[i][j][k].end());
					int a = unique(v[i][j][k].begin(), v[i][j][k].end()) - v[i][j][k].begin();
					v[i][j][k].erase(v[i][j][k].begin() + a, v[i][j][k].end());
				}
		for(i = 0; i < n - 1; i++) {
			swap(pos[i], pos[n - 1]);
			if(create2(1 << i, i, i, 0))
				break;
			swap(pos[i], pos[n - 1]);
		}
		if(i < n - 1) puts("possible");
		else puts("impossible");
	}
	return 0;
}

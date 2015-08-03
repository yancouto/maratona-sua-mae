// RE ?????
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
int n; ull l;
ull adj[15][15];
int p[20];
vector<ull> v[1 << 14][14][14];
int main() {
	int i, j, k;
	while(scanf("%d %llu", &n, &l) != EOF) {
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%llu", &adj[i][j]);
		if(n == 2) {
			if((adj[0][1] + adj[1][0]) == l) puts("possible");
			else puts("impossible");
			continue;
		}
		for(i = 0; i < (1 << n); i++) {
			if(__builtin_popcount(i) != ((n/2)+2)) continue;
			k = 0;
			for(j = 0; j < n; j++)
				if(i & (1 << j))
					p[k++] = j;
			do {
				if(p[0] > p[k - 1]) continue;
				ull tot = 0;
				for(j = 0; j < (k - 1); j++)
					tot += adj[p[j]][p[j + 1]];
				if(tot > l) continue;
				v[i][p[0]][p[k - 1]].pb(tot);
			} while(next_permutation(p, p + k));
		}
		for(i = 0; i < (1 << n); i++)
			for(j = 0; j < n; j++)
				for(k = j + 1; k < n; k++)
					if(v[i][j][k].size())
						sort(v[i][j][k].begin(), v[i][j][k].end());
		for(i = 0; i < (1 << n); i++) {
			if(__builtin_popcount(i) != ((n + 1) / 2)) continue;
			k = 0;
			for(j = 0; j < n; j++)
				if(i & (1 << j))
					p[k++] = j;
			bool found = false;
			do {
				if(p[0] > p[k - 1]) continue;
				ull tot = 0;
				for(j = 0; j < (k - 1); j++)
					tot += adj[p[j]][p[j + 1]];
				if(tot > l) continue;
				int bm = ((1 << n) - 1) ^ ((i ^ (1 << p[0])) ^ (1 << p[k - 1]));
				if(binary_search(v[bm][p[0]][p[k - 1]].begin(), v[bm][p[0]][p[k - 1]].end(), l - tot)) { found = true; break; }
			} while(next_permutation(p, p + k));
			if(found) break;
		}
		if(i < (1 << n)) puts("possible");
		else puts("impossible");
		for(i = 0; i < (1 << n); i++)
			for(j = 0; j < n; j++)
				for(k = j + 1; k < n; k++)
					v[i][j][k].clear();
	}
	return 0;
}

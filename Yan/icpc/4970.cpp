// era TLE virou RE???
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

int p[20];
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
		for(i = 0; i < (1 << n); i++)
			for(j = 0; j < n; j++)
				for(k = j + 1; k < n; k++)
					v[i][j][k].clear();
		for(i = 0; i < (1 << n); i++) {
			if(__builtin_popcount(i) != (n / 2) + 2) continue;
			k = 0;
			for(j = 0; j < n; j++)
				if((1 << j) & i)
					p[k++] = j;
			do {
				if(p[0] > p[k-1]) continue;
				ull tot = 0;
				for(j = 0; j < k - 1; j++)
					tot += adj[p[j]][p[j + 1]];
				v[i][p[0]][p[k-1]].pb(tot);
			} while(next_permutation(p, p + k));
		}
		for(i = 0; i < (1 << n); i++)
			for(j = 0; j < n; j++)
				for(k = j + 1; k < n; k++) {
					if(v[i][j][k].size() == 0) continue;
					sort(v[i][j][k].begin(), v[i][j][k].end());
					int a = unique(v[i][j][k].begin(), v[i][j][k].end()) - v[i][j][k].begin();
					v[i][j][k].erase(v[i][j][k].begin() + a, v[i][j][k].end());
				}
		bool ok = false;
		for(i = 0; !ok && i < (1 << n); i++) {
			if(__builtin_popcount(i) != ((n + 1) / 2)) continue;
			k = 0;
			for(j = 0; j < n; j++)
				if((1 << j) & i)
					p[k++] = j;
			do {
				if(p[0] > p[k-1]) continue;
				ull tot = 0;
				for(j = 0; j < k - 1; j++)
					tot += adj[p[j]][p[j+1]];
				int bm = (1 << n) - 1;
				bm ^= i; bm |= (1 << p[0]) | (1 << p[k-1]);
				if(tot > l) continue;
				if(binary_search(v[bm][p[0]][p[k-1]].begin(), v[bm][p[0]][p[k-1]].end(), l - tot)) ok = true;
			} while(!ok && next_permutation(p, p + k));
		}
		if(ok) puts("possible");
		else puts("impossible");
	}
	return 0;
}

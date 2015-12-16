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
const int N = 505;

int n;
int x[N], f[N], g[N][N];
ll ans[N][N], tot[N];

int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
		for(j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	for(i = 0; i < n; i++) 
		scanf("%d", &x[i]), x[i]--;
	for(i = n-1; i >= 0; i--) {
		f[x[i]] = 1; 
		for(j = 0; j < n; j++) if(f[j]) ans[x[i]][j] = g[x[i]][j], ans[j][x[i]] = g[j][x[i]];
		for(j = 0; j < n; j++) {
			if(!f[j]) continue;
			for(k = 0; k < n; k++) 
				if(f[k]) { 
					ans[j][x[i]] = min(ans[j][x[i]], ans[j][k] + ans[k][x[i]]);
					ans[x[i]][j] = min(ans[x[i]][j], ans[x[i]][k] + ans[k][j]);
				}
		}
		for(j = 0; j < n; j++) {
			if(!f[j]) continue;
			for(k = 0; k < n; k++) if(f[k]) ans[j][k] = min(ans[j][k], ans[j][x[i]] + ans[x[i]][k]);
		}
		for(j = 0; j < n; j++) if(f[j]) for(k = 0; k < n; k++) if(f[k]) tot[i] += ans[j][k];
	}
	for(i = 0; i < n; i++) printf("%lld ", tot[i]); putchar('\n');
	return 0;
}


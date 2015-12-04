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

int a[15][110], b[15][110], c[15][110];
int v[110];
int n, m, k, pi, pj;

bool comp(int i, int j) { return b[pj][i] - a[pi][i] > b[pj][j] - a[pi][j]; }

int main() {
	int i, j, kk, ans, sum;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < n; i++) {
		scanf("%*s");
		for(j = 0; j < m; j++) 
			scanf("%d %d %d", &a[i][j], &b[i][j], &c[i][j]);
	}
	ans = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i == j) continue;
			for(int l = 0; l < m; l++) v[l] = l;
			pi = i; pj = j;
			sort(v, v + m, comp);
			kk = k; sum = 0;
			for(int l = 0; l < m && kk > 0; l++) {
				sum += (b[pj][v[l]] - a[pi][v[l]]) * min(kk, c[pi][v[l]]);
				ans = max(ans, sum); 
				kk -= min(kk, c[pi][v[l]]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

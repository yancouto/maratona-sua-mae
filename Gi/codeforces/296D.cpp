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
int x[N], f[N], g[N][N], ans[N][N];

int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
		for(j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	for(i = 0; i < n; i++) 
		scanf("%d", &x[i]), x[i]--;
	reverse(x, x + n);
	for(i = 0; i < n; i++) {
		f[x[i]] = 1;
		for(i = 0; i < n; i++) ans[x[i]][i] = g[x[i]][i], ans[i][x[i]] = g[i][x[i]];
		for(i = 0; i < n; i++) 

	}
	
		
	
	return 0;
}


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

int v[1000];//, pd[2][200001][31];
clock_t c;
int res[1000], rn;
int solve(int i, int n, int k) {
	if(k == 0) return n == 0;
	if(v[i] == 0 || v[i] > n) return 0;
	if(double(clock() - c) / CLOCKS_PER_SEC >= 1.83) { puts("NO"); exit(0); }
	if(solve(i + 1, n - v[i], k - 1)) { res[rn++] = v[i]; return true; }
	else return solve(i + 1, n, k);
}


int main() {
	c = clock();
	freopen("squary.in", "r", stdin);
	freopen("squary.out", "w", stdout);
	int i, n, k, g, j;
	scanf("%d %d", &n, &k);
	for(i = 1; i * i < n; i++)
		v[i - 1] = n - i * i;
	reverse(v, v + i);
	
	//pd[i&1][0][0] = 1;
	//while(--i)
	//	for(j = 0; j <= n; j++)
	//		for(g = 0; g <= k; g++)
	//			pd[i&1][j][g] = pd[(i+1)&1][j][g] || (g && v[i] <= j && pd[(i+1)&1][j - v[i]][g - 1]);
	//printf("from pd %d\n", pd[1][n][k]);
	if(solve(1, n, k)) {
		puts("YES");
		for(i = 0; i < rn; i++)
			printf("%d ", res[i]);
		putchar('\n');
	}
	else printf("NO\n");
}

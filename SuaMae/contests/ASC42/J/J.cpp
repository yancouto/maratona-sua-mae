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
const int N = 412345;

int seen[N], tempo, val[N], deg[N], en;
int he[N], he2[N], nx[N], to[N];

void dfs(int u) {
	if(seen[u] == tempo) return;
	val[u]++;
	seen[u] = tempo;
	for(int e = he[u]; e != -1; e = nx[e])
		dfs(to[e]);
}

int dfs2(int u) {
	if(seen[u] == tempo) return 0;
	seen[u] = tempo;
	int n = 1;
	for(int e = he2[u]; e != -1; e = nx[e])
		n += dfs2(to[e]);
	return n;
}

int v[N], vn;

int main() {
	clock_t T = clock();
	srand(time(NULL));
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
	int i, a, b, n, m;
	int tn = 0, tm = 0;
	while(scanf("%d", &n) != EOF && n) {
		scanf("%d", &m);
		clock_t c = clock();
		double now = double(clock() - T) / CLOCKS_PER_SEC;
		double s1 = (n * (3.8 - now) / 2.) / (100001. - tn);
		double s2 = (m * (3.8 - now) / 2.) / (200001. - tm);

		double s = s1 + s2;
		vn = en = 0;
		for(i = 0; i < n; i++) val[i] = 0, deg[i] = 0, he[i] = he2[i] = -1;
		for(i = 0; i < m; i++) {
			scanf("%d %d", &a, &b); a--; b--;
			if(a == b) continue;
			to[en] = a; nx[en] = he[b]; he[b] = en++;
			to[en] = b; nx[en] = he2[a]; he2[a] = en++;
			deg[b]++;
		}
		for(i = 0; i < n; i++)
			if(deg[i] != 0)
				v[vn++] = i;
		for(int T = 0; vn && (T < 200 || double(clock() - c) / CLOCKS_PER_SEC < s); T++) {
			tempo++;
			int j = rand() % vn;
			swap(v[j], v[--vn]);
			dfs(v[vn]);
		}
		int bi = -1, bm;
		for(int k = 0; k < 10; k++) {
			int u = -1;
			for(i = 0; i < n; i++)
				if(deg[i] == 0 && (u == -1 || val[u] < val[i]))
					u = i;
			if(u == -1) break;
			val[u] = -1;
			tempo++;
			if(bi == -1 || dfs2(u) > bm)
				bi = u, bm = dfs2(u);
		}
		printf("%d %d\n", bi + 1, bm);
	}
}

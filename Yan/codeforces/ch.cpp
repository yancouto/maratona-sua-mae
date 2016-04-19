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

vector<int> adj[200009];
int seen[200009];

int mxh = -1, mv;
void dfs(int u, int p, int h) {
	seen[u] = true;
	if(h > mxh) {
		mxh = h;
		mv = u;
	}
	for(int v : adj[u])
		if(v != p) {
			assert(!seen[v]);
			dfs(v, u, h + 1);
		}
}

int en;
void ed(int a, int b) {
	a--, b--; en++;
	adj[a].pb(b);
	adj[b].pb(a);
}

int main() {
	int i, n, h, d, a, b;
	srand(time(NULL));
	while(true) {
		en = 0;
		n = (rand() % 100) + 3;
		d = (rand() % (n - 2)) + 2;
		h = ((d + 1) / 2) + (rand() % (d / 2));
		for(i =0 ; i < n; i++)
			adj[i].clear(), seen[i] = 0;
		printf("%d %d %d\n", n, d, h);
		//scanf("%d %d %d", &n, &d, &h);
		if(d == h && d == n - 1) {
			for(i = 0; i < n - 1; i++)
				ed(i + 1, i + 2);
		} else {
			if(n == 2 || (d - h) > h) { puts("-1"); return 0; }
			for(i = 0; i < h; i++)
				ed(i + 1, i + 2);
			int j = i + 2;
			if(d == h) {
				for(i = j; i <= n; i++)
					ed(j - 2, i);
			} else {
				ed(1, j);
				for(i = 0; i < d - h - 1; i++)
					ed(i + j, i + j + 1);
				for(; i + j + 1 <= n; i++)
					ed(1, i + j + 1);
			}
		}
		assert(en == n - 1);
		mxh = -1;
		dfs(0, 0, 0);
		assert(h == mxh);
		for(i = 0; i < n; i++)
			assert(seen[i]), seen[i] = false;
		dfs(mv, mv, 0);
		assert(d == mxh);
	}
}

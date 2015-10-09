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

<<<<<<< HEAD
int n, m, u, v, ied, q;
int sz[100005], id[100005], mark[10005];
vector<int> g[100005];
=======

int n, m, u, v, q;
int sz[100005], id[100005], mark[100005];
>>>>>>> origin/master
pii edge[100005];

int find(int v) {
	if(v == id[v]) return v;
	id[v] = find(id[v]);
	return id[v];
}

void join(int i, int j) {
	int x = find(i);
	int y = find(j);
<<<<<<< HEAD
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	id[y] = id[x];
=======
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	id[y] = x;
>>>>>>> origin/master
}

int main() {
	scanf("%d %d", &n, &m);
<<<<<<< HEAD
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		edge[ied++] = pii(u, v);
	}
=======
	for(int i = 0; i < m; i++) 
		scanf("%d %d", &edge[i].fst, &edge[i].snd);
>>>>>>> origin/master
	for(int i = 0; i < n; i++) {
		sz[i] = 1; id[i] = i; 
	}
	scanf("%d", &q);
	int qq[100005];
	for(int i = 0; i < q; i++) {
		scanf("%d", &qq[i]);
		qq[i]--; mark[qq[i]] = 1;
	}
	int comp = n;
	for(int i = 0; i < m; i++) {
		if(mark[i]) continue;
		int f = edge[i].fst; 
		int s = edge[i].snd;
<<<<<<< HEAD
		if(find(f) == find(v)) continue;
		comp--; join(f, s);
=======
		if(find(f) != find(s)) comp--;
		join(f, s);
>>>>>>> origin/master
	}
	vector<int> ans;
	for(int i = q-1; i >= 0; i--) {
		ans.pb(comp);
		int f = edge[qq[i]].fst;
		int s = edge[qq[i]].snd;
<<<<<<< HEAD
		if(find(f) != find(s)) comp--;
		join(f, s);
	}
	for(int i = q-1; i >= 0; i--)
		printf("%d ", ans[i]);
	putchar('\n');
	return 0;
}
=======
		if(find(f) != find(s)) comp--;	
		join(f, s);
	}
	for(int i = q-1; i >= 0; i--) {
		printf("%d", ans[i]);
		if(i > 0) putchar(' ');
	}
	putchar('\n');
	return 0;
}

>>>>>>> origin/master

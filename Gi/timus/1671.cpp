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

int n, m, u, v, ied, q;
int sz[100005], id[100005], mark[10005];
vector<int> g[100005];
pii edge[100005];

int find(int v) {
	if(v == id[v]) return v;
	id[v] = find(id[v]);
	return id[v];
}

void join(int i, int j) {
	int x = find(i);
	int y = find(j);
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	id[y] = id[x];
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		u--; v--;
		edge[ied++] = pii(u, v);
	}
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
		if(find(f) == find(v)) continue;
		comp--; join(f, s);
	}
	vector<int> ans;
	for(int i = q-1; i >= 0; i--) {
		ans.pb(comp);
		int f = edge[qq[i]].fst;
		int s = edge[qq[i]].snd;
		if(find(f) != find(s)) comp--;
		join(f, s);
	}
	for(int i = q-1; i >= 0; i--)
		printf("%d ", ans[i]);
	putchar('\n');
	return 0;
}

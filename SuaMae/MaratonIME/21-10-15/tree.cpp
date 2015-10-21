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
const int MAX = 20005;

int n, k;
int pai[MAX], mark[MAX];
int id[MAX], sz[MAX];
int query[5005];
vector<pii> q;
vector<int> c;

int find(int x) {
	if(x == id[x]) return x;
	return id[x] = find(id[x]);
}

void join(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	id[y] = x;
}

int main() {
	for_tests(t, tt) {
		char cc;
		int a, b;
		scanf("%d %d", &n, &k);
		memset(mark, 0, sizeof mark);
		memset(query, 0, sizeof query);
		q.clear(); c.clear();
		for(int i = 0; i < n; i++)
			scanf("%d", &pai[i+1]);
		for(int i = 1; i <= n; i++)
			sz[i] = 1, id[i] = i;
		for(int i = 0; i < k; i++) {
			scanf(" %c", &cc);
			if(cc == 'Q') {
				scanf("%d %d", &a, &b);
				q.pb(pii(a, b));
				query[i] = 1;
			}
			else {
				scanf("%d", &a);
				mark[a] = 1;
				c.pb(a);
			}
		}
		for(int i = 1; i <= n; i++) {
			if(mark[i]) continue;
			if(pai[i] == 0) continue;
			join(i, pai[i]);
		}
		int ans[5005];
		memset(ans, 0, sizeof ans);
		for(int i = k-1; i >= 0; i--) {
			if(query[i]) {
				pii x = q[q.size() - 1];
				ans[i] = (find(x.fst) == find(x.snd));
				q.pop_back();
			}
			else {
				int x = c[c.size() - 1];
				if(pai[x] != 0)
					join(x, pai[x]);
				c.pop_back();
				ans[i] = -1;
			}
		}
		printf("Case #%d:\n", tt);
		for(int i = 0; i < k; i++) {
			if(ans[i] == 1) puts("YES");
			else if(!ans[i]) puts("NO");
		}
	}
	return 0;
}

#include <cstdio>
#include <vector>
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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int k, n, e;
vector<int> adj[1030];
ld bit[103][12];
ld memo[1030][103];
ld s(int v, int k) {
	if(k == 0) return 1. / (1 << n);
	ld &r = memo[v][k];
	if(r > -.5) return r;
	r = 0;
	for(int i = 0; i < adj[v].size(); i++) {
		r += s(adj[v][i], k - 1) / adj[adj[v][i]].size();
		//printf("+= %Lf / %d\n", s(adj[v][i], k - 1), adj[adj[v][i]].size());

	}
	//printf("s(%d, %d) = %Lf\n", v, k, r);
	return r;
}

int main() {
	int i, j, a, b;
	while(true) {
		scanf("%d %d %d", &k, &n, &e);
		if(!k) return 0;
		for(i = 0; i < (1 << n); i++) adj[i].clear();
		for(i = 0; i < e; i++) {
			scanf("%d %d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		for(i = 0; i < (1 << n); i++)
			for(j = 0; j < k; j++)
				memo[i][j] = -1;
		bool ok = true;
		for(i = 0; i < k; i++) {
			for(j = 0; j < n; j++) {
				bit[i][j] = 0;
				for(a = 0; a < (1 << n); a++)
					if(a & (1 << j))
						bit[i][j] += s(a, i);
				//printf("bit[%d][%d] = %Lf\n", i, j, bit[i][j]);
				if(bit[i][j] < .25 || bit[i][j] > .75) ok = false;
			}
		}
		if(!ok) puts("No");
		else puts("Yes");
	}
}

#include <bits/stdc++.h>
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
int dc[203], sub[203];
vector<int> adj[203];
map<string, int> mp;
int get_n(char *c) {
	string ss(c);
	if(!mp.count(ss)) {
		 int a = mp.size();
		 mp[ss] = a;
	}
	return mp[ss];
}
int deg[203], tempo;
const int inf = 800000000;

int c(int, int, int);
int d(int v, int j) {
	if(j == 0) return 0;
	if(j > sub[v]) return inf;
	//printf("d(%d, %d) = c(%d,%d,%d)=%d or %d\n", v, j, v, adj[v].size(), j, c(v, adj[v].size(), j), dc[v]);
	return min(c(v, adj[v].size(), j), dc[v]);
}
int memo[203][203];
int c(int v, int m, int j) {
	if(j == 0) return 0;
	if(m == 0) return inf;
	if(m == 1) return d(adj[v][0], j);
	int &ans = memo[adj[v][m-1]][j];
	if(ans != -1) return ans;
	ans = inf;
	for(int k = 0; k <= j; k++)
		ans = min(ans, c(v, m - 1, j - k) + d(adj[v][m-1], k));
	return ans;
}

int dfs(int u) {
	int all = 1;
	for(int v : adj[u])
		all += dfs(v);
	return sub[u] = all;
}

int main() {
	int n, m, i, x;
	char name[200];
	char rest[202*101 + 500];
	while(true) {
		tempo++;
		if(scanf("%d %d", &n, &m) != 2) return 0;
		mp.clear();
		for(i = 0; i < n; i++) {
			scanf(" %s %d", name, &x);
			int ii = get_n(name);
			adj[ii].clear();
			dc[ii] = x;
			//printf("%s %d\n", name, ii);
			fgets(rest, sizeof rest, stdin);
			int ind = 0;
			while(true) {
				 while(isspace(rest[ind])) ind++;
				 if(!rest[ind]) break;
				 sscanf(rest + ind, " %s", name);
				 //printf("%d -> %s(%d)\n", ii, name, get_n(name));
				 adj[ii].pb(get_n(name));
				 while(!isspace(rest[ind])) ind++;
			}
		}
		vector<int> d0;
		for(i = 0; i < mp.size(); i++)
			for(int v : adj[i])
				deg[v] = tempo;
		for(i = 0; i < mp.size(); i++)
			if(deg[i] < tempo)
				d0.pb(i);
		adj[mp.size()].swap(d0);
		dc[mp.size()] = inf;
		dfs(mp.size());
		memset(memo, -1, sizeof memo);
		printf("%d\n", d(mp.size(), m));
	}
}

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
const int MAX = 100005;

vector<int> g[MAX];
vector<pii> ed;
int memo[MAX][2], mm[MAX][2][2];
int d[MAX];

int solve(int no, int can) {
	int &mem = memo[no][can];
	if(mem != -1) return mem;
	int sum1 = 0, sum2 = 0;	
	bool inn = false;
	for(int i = 0; i < g[no].size(); i++) {
		if(d[g[no][i]] <= d[no]) continue;
		sum1 += solve(g[no][i], 1);
		if(can) sum2 += solve(g[no][i], 0);
		inn = true;
	}
	mm[no][can][0] = sum1;
	mm[no][can][1] = sum2 + inn;
	if(can) mem = max(inn + sum2, sum1);
	else mem = sum1;
	printf("State %d %d retornando %d\n", no, can, mem);
	return mem;
}

set<pii> edges;
void build(int no, int can) {
	int ans = solve(no, can);
	bool inn = true;
	for(int i = 0; i < g[no].size(); i++) {
		if(d[g[no][i]] <= d[no]) continue;
		build(g[no][i], ans == mm[no][can][0]);
		if(ans == mm[no][can][1] && inn) {
			edges.insert(pii(no, g[no][i]));
			inn = false;
		}
	}
}

int seen[MAX];
int beg = 0;
void dfs(int no) {
	seen[no] = 1;
	d[no] = beg++;
	for(int i = 0; i < g[no].size(); i++) {
		if(seen[g[no][i]]) continue;
		dfs(g[no][i]);
	}
}

int main() {
	int i, u, v, n, m;
	scanf("%d %d", &n, &m);
	memset(memo, -1, sizeof memo);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		ed.pb(pii(u, v));
		g[u].pb(v); g[v].pb(u);
	}
	dfs(1);
	printf("%d\n", solve(1, 1));	
	build(1, 1);
	for(int i = 0; i < ed.size(); i++) {
		if(edges.count(ed[i])) printf("%d %d\n", ed[i].fst, ed[i].snd);
		else if(edges.count(pii(ed[i].snd, ed[i].fst)))
			printf("%d %d\n", ed[i].snd, ed[i].fst);
	}
	return 0;
}

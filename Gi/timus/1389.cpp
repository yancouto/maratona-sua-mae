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
int ed[2*MAX][3];
int memo[MAX][2], mm[MAX][2][2];
int d[MAX], ied;

int solve(int no, int can) {
	int &mem = memo[no][can];
	if(mem != -1) return mem;
	int sum = 1000000, sum1 = 0, kid = 0;	
	bool inn = false;
	for(int i = 0; i < g[no].size(); i++) {
		int x = ed[g[no][i]][1];
		if(d[x] <= d[no]) continue;
		int a = solve(x, 1), b = solve(x, 0);
		sum1 += a; inn = true;
		if(a - b < sum) { sum = a - b; kid = g[no][i]; }
	}
	if(!inn) return mem = 0;
	mem = sum1;
	mm[no][can][0] = sum1;
	if(can) mm[no][can][1] = kid;
	if(can) mem = max(sum1, 1 + sum1 - sum);
	return mem;
}

void build(int no, int can) {
	int ans = solve(no, can);
	if(ans == mm[no][can][0]) {
		for(int i = 0; i < g[no].size(); i++) {
			int x = ed[g[no][i]][1];
			if(d[x] <= d[no]) continue;
			build(x, 1);
		}
	}
	else {
		int edge = mm[no][can][1];
		build(ed[edge][1], 0);
		if(ed[edge][2]) printf("%d %d\n", ed[edge][0], ed[edge][1]);
		else printf("%d %d\n", ed[edge][1], ed[edge][0]);
		for(int i = 0; i < g[no].size(); i++) {
			int x = ed[g[no][i]][1];
			if(d[x] <= d[no]) continue;
			if(g[no][i] == mm[no][can][1]) continue;
			build(x, 1);
		}
	}
}

int seen[MAX];
int beg = 0;
void dfs(int no) {
	seen[no] = 1;
	d[no] = beg++;
	for(int i = 0; i < g[no].size(); i++) {
		int x = ed[g[no][i]][1];
		if(seen[x]) continue;
		dfs(x);
	}
}

int main() {
	int i, u, v, n, m;
	scanf("%d %d", &n, &m);
	memset(memo, -1, sizeof memo);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		ed[ied][0] = u; ed[ied][1] = v; ed[ied][2] = 1 ; g[u].pb(ied); ied++;
		ed[ied][0] = v; ed[ied][1] = u; ed[ied][2] = 0 ; g[v].pb(ied); ied++;
	}
	dfs(1);
	printf("%d\n", solve(1, 1));	
	build(1, 1);
	return 0;
}

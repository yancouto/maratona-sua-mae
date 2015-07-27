// TLE
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
int N, M, B, K, R, T;
struct ed {
	int b, t, m;
	ed() {}
	ed(int a, int bb, int c) : b(a), t(bb), m(c) {}
};
vector<ed> adj[102];
int salt[6][102];

struct no {
	int i, k, t, m, s;
	bool co;
	no() {}
	no(int a, int b, int c, int d, int e, bool h) : i(a), k(b), t(c), m(d), s(e), co(h) {}
	bool operator < (const no &o) const {
		return !((t == o.t)? m > o.m : t < o.t);
	}
};

int seen[102][6][202][5][2], tempo;
int solve() {
	priority_queue<no> pq;
	tempo++;
	pq.push(no(0, 0, 0, R, 0, false));
	while(!pq.empty()) {
		no x = pq.top();
		pq.pop();
		if(x.t > T || (x.k && (x.i == 0 || x.i == N - 1))) continue;
		if(x.i == N - 1 && x.t == T) return x.m;
		if(seen[x.i][x.k][x.t][x.s][x.co] == tempo) continue;
		seen[x.i][x.k][x.t][x.s][x.co] = tempo;
		if(!x.co) {
			if(x.s < B && x.i != 0 && x.i != N - 1 && x.m >= salt[x.k][x.i])
				pq.push(no(x.i, x.k, x.t, x.m - salt[x.k][x.i], x.s + 1, true));
			if(x.s && x.i && x.i != N - 1)
				pq.push(no(x.i, x.k, x.t, x.m + salt[x.k][x.i], x.s - 1, true));
		}
		if(x.i && x.i != N - 1)
			pq.push(no(x.i, (x.k + 1) % K, x.t + 1, x.m, x.s, false));
		for(int i = 0; i < adj[x.i].size(); i++) {
			ed &e = adj[x.i][i];
			if(x.m >= e.m && x.t + e.t <= T)
				pq.push(no(e.b, x.k, x.t + e.t, x.m - e.m, x.s, false));
			 
		}
	}
	return -1;
}

int main() {
	int i, j, a, b, t, m;
	for_tests(c, cn) {
		scanf("%d %d %d %d %d %d", &N, &M, &B, &K, &R, &T);
		for(i = 0; i < N; i++) adj[i].clear();
		for(i = 0; i < K; i++)
			for(j = 0; j < N; j++)
				scanf("%d", &salt[i][j]);
		for(i = 0; i < M; i++) {
			scanf("%d %d %d %d", &a, &b, &t, &m);
			adj[--a].pb(ed(--b, t, m));
			adj[b].pb(ed(a, t, m));
		}
		int mx = solve();
		if(mx == -1) printf("Case #%d: Forever Alone\n", cn);
		else printf("Case #%d: %d\n", cn, mx);
	}
}

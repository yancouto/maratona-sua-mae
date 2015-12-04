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
const int N = 405;

int rail[N][N];
int seen[N];
int n;

struct vert {
	int fst, snd;
	vert(){}
	vert(int fst, int snd) : fst(fst), snd(snd) {}
	bool operator <(const vert &o) const{
		return o.fst < fst;
	}
};

int solve(int o, int f) {
	priority_queue<vert> pq;
	pq.push(vert(0, o));
	while(!pq.empty()) {
		vert x = pq.top(); pq.pop();
		seen[x.snd] = 1;
		if(x.snd == n) return x.fst;
		for(int i = 1; i <= n; i++) {
			if(seen[i] || i == x.snd) continue;
			if(rail[i][x.snd] != f) continue;
			pq.push(vert(x.fst + 1, i));
		}
	}
	return -1;
}

int main() {
	int m, i, j, u, v;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		rail[u][v] = 1; rail[v][u] = 1;
	}
	int s = 1;
	if(rail[1][n]) s = 0;
	printf("%d\n", solve(1, s));
	return 0;
}

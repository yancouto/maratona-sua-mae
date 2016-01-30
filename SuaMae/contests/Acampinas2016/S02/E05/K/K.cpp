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
const int N = 104;
const ll oo = 1000000000000;

int R, C, r1, c1, r2, c2, t;
int seen[N][N][4][2];
int di[4] = {0, 1, 0,-1};
int dj[4] = {1, 0,-1, 0};
ll g[N][N][5];


struct No{
	int i, j, d, can; ll dist;
	No() {}
	No(int i, int j, int d, int can, ll dist) : i(i), j(j), d(d), can(can), dist(dist) {}
	bool operator <(const No &o) const{
		return o.dist < dist;
	}
};

bool isIn(int i, int j) { return i >= 0 && i < R && j >= 0 && j < C; }

ll solve(int i, int j) {
	priority_queue<No> pq;
	pq.push(No(i, j, 0, 1, 0ll));
	while(!pq.empty()) {
		No x = pq.top(); pq.pop();
		if(seen[x.i][x.j][x.d][x.can]) continue;
		//printf("No %d %d %d %d\n", x.i, x.j, x.d, x.can);
		if(x.i == r2 && x.j == c2 && x.can) return x.dist;
		seen[x.i][x.j][x.d][x.can] = 1;
		for(int k = 0; k < 4; k++) {
			int nxi = x.i + di[k], nxj = x.j + dj[k];
		//	printf("(%d, %d) -> dir %d\n", x.i, x.j, k);
		//	printf("%d || %d || %d\n", !isIn(nxi, nxj), (k != x.d && !x.can), !g[x.i][x.j][k]);
			if(!isIn(nxi, nxj) || (k != x.d && !x.can) || !g[x.i][x.j][k]) continue;
		//	printf("(%d, %d) -> (%d, %d)\n", x.i, x.j, nxi, nxj);
			pq.push(No(nxi, nxj, k, 0, x.dist + (ll)(1 + x.can) * g[x.i][x.j][k]));
			pq.push(No(nxi, nxj, k, 1, x.dist + 2ll * g[x.i][x.j][k]));
		}
	}
	return oo;
}

int main() {
	while(42) {
		int x, i, j;
		scanf("%d %d %d %d %d %d", &R, &C, &r1, &c1, &r2, &c2);
		if(R + C + r1 + c1 + r2 + c2 == 0) break;
		memset(g, 0, sizeof g); memset(seen, 0, sizeof seen);
		r1--; c1--; r2--; c2--;
		for(i = 0; i < 2*R-1; i++)
			for(j = 0; j < ((i&1)?C:C-1); j++) {
				scanf("%d", &x);
				if(i&1) g[i/2][j][1] = g[i/2+1][j][3] = x;
				else g[i/2][j][0] = g[i/2][j+1][2] = x;
			}
		ll ans = solve(r1, c1);
		printf("Case %d: ", ++t);
		if(ans == oo) puts("Impossible");
		else printf("%lld\n", ans);
	}
	return 0;
}

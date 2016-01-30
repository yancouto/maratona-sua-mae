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
#define temp template<typename num>
#define ptn point<num>
#define ws asldhasjkdgfjkasdf

temp struct point {
	num x, y;
	ptn() {}
	ptn(num a, num b) : x(a), y(b) {}
	ptn operator - (ptn o) const { return ptn(x - o.x, y - o.y); }
	num operator * (ptn o) const { return x * o.x + y * o.y; }
	num operator ^ (ptn o) const { return x * o.y - y * o.x; }
	bool operator == (ptn o) const { return x == o.x && y == o.y; }
};
temp inline num cross(ptn a, ptn b, ptn c) { return (c - a) ^ (b - a); }
temp inline bool betweenSeg(ptn a, ptn b, ptn c) { return cross(a, b, c) == 0 && ((b - c) * (a - c) <= 0); }
temp bool intersectSeg(ptn a, ptn b, ptn c, ptn d) {
	if(betweenSeg(a, b, c) || betweenSeg(a, b, d) || betweenSeg(c, d, a) || betweenSeg(c, d, b)) return true;
	if((cross(a, b, c) > 0) ^ (cross(a, b, d) > 0) && ((cross(c, d, a) > 0) ^ (cross(c, d, b) > 0))) return true;
	return false;
}

typedef point<int> pti;

const int N = 12009;
vector<int> adj[N];

int st[N], sn;
int d[N], low[N], seen[N], tempo, cmp[N], cn;
bool ok = true;
void dfs(int u) {
	seen[u] = true;
	d[u] = low[u] = tempo++; 
	st[sn++] = u;
	for(int v : adj[u]) {
		if(seen[v]) low[u] = min(low[u], d[v]);
		else { dfs(v); low[u] = min(low[u], low[v]); }
	}
	if(low[u] >= d[u]) {
		cn++; int a = -1;
		while(a != u) {
			a = st[--sn];
			if(cmp[a ^ 1] == cn) ok = false;
			cmp[a] = cn;
			low[a] = INT_MAX;
		}
	}
}

pti ws[N], pe[N]; int pi[N];

int main() {
	int i, j, w, p;
	scanf("%d %d", &w, &p);
	for(i = 0; i < w; i++)
		scanf("%d %d", &ws[i].x, &ws[i].y);
	for(i = 0; i < p; i++)
		scanf("%d %d %d", &pi[i], &pe[i].x, &pe[i].y), pi[i]--;
	for(i = 0; i < p; i++)
		for(j = i + 1; j < p; j++) {
			if(pi[i] == pi[j]) continue;
			if(pe[i] == pe[j] || intersectSeg(ws[pi[i]], pe[i], ws[pi[j]], pe[j])) {
				adj[2*i].pb(2*j+1);
				adj[2*i+1].pb(2*j);
				adj[2*j].pb(2*i+1);
				adj[2*j+1].pb(2*i);
			}
		}
	for(i = 0; i < p; i++)
		if(!seen[i])
			dfs(i);
	if(ok) puts("possible");
	else puts("impossible");
}

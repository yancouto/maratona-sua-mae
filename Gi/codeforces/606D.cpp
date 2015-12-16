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
const int N = 100010;

struct Edge { int i, u, v, w, f; };
bool cmp(Edge a, Edge b) { if(a.f == b.f) return a.w < b.w; return a.f > b.f; }
bool cmp2(Edge a, Edge b) { return a.i < b.i; }

int n, m;
Edge ed[N];

int main() {
	int i, u, v;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) 
		scanf("%d %d", &ed[i].w, &ed[i].f), ed[i].i = i;
	sort(ed, ed + m, cmp);
	for(i = 0; i < n - 1; i++)
		ed[i].u = i, ed[i].v = i + 1;
	u = -1; v = 1;
	for(i = n - 1; i < m; i++) {
		if(u+2 == v) v++, u = 0;
		else u++; 
		if(ed[i].w < ed[v-1].w) { puts("-1"); return 0; }
		ed[i].u = u; ed[i].v = v;
	}
	sort(ed, ed+m, cmp2);
	for(i = 0; i < m; i++) printf("%d %d\n", ed[i].u+1, ed[i].v+1);
	return 0;
}

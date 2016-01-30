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
const int N = 1000009;
int S[N], sz[N];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}
void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}

int u[N], v[N], w[N], p[N];
int main() {
	int i, n, m;
	while(true) {
		scanf("%d %d", &n, &m);
		if(!n) return 0;
		for(i = 0; i < m; i++)
			scanf("%d %d %d", &u[i], &v[i], &w[i]), p[i] = i;
		for(i = 0; i < n; i++) S[i] = i, sz[i] = 1;
		sort(p, p + m, [](int i, int j) { return w[i] < w[j]; });
		for(i = 0; i < m; i++) {
			join(u[p[i]], v[p[i]]);
			if(sz[find(u[p[i]])] == n) { printf("%d\n", w[p[i]]); break; }
		}
		if(i == m) puts("IMPOSSIBLE");
	}
}

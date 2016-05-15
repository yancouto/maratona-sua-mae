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
const int N = 312345;

int deg[N], d0, d2, P[N], qp[N], ansn[N], ansm[N];
vector<pii> ar[N];
int S[N], sz[N], ok[N], cyc[N], cur_g0, g0[N];

void go(int u) {
	deg[u]--;
	if(deg[u] == 0) d0++;
	else if(deg[u] == 2) d2++;
	else if(deg[u] == 1) d2--;
}

int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

int mx[N], d[N];
void join(int a, int b) {
	int da = ++d[a]; int db = ++d[b];
	a = find(a); b = find(b);
	mx[a] = max(mx[a], da); mx[b] = max(mx[b], db);
	if(a == b) {
		if(!cyc[a]) {
			cyc[a] = 1;
			ok[a] = mx[a] < 3 && da == 2 && db == 2;
			cur_g0 += ok[a];
		} else {
			cur_g0 -= ok[a];
			ok[a] = 0;
		}
		return;
	}
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
	if(cyc[b]) cyc[a] = 1, cur_g0 -= ok[b];
	if(cyc[a]) cur_g0 -= ok[a], ok[a] = 0;
	mx[a] = max(mx[a], mx[b]);
}

int main() {
	int n, m, i, a, b, p, q, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &p); a--; b--;
		ar[p].pb(pii(a, b));
		deg[a]++; deg[b]++;
	}
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1, ok[i] = 0, cyc[i] = 0, mx[i] = 0;
	for(i = 310000; i >= 0; i--) {
		for(pii e : ar[i])
			join(e.fst, e.snd);
		g0[i] = cur_g0;
	}
	for(i = 0; i < n; i++)
		if(deg[i] == 0) d0++;
		else if(deg[i] == 2) d2++;
	scanf("%d", &q);
	for(i = 0; i < q; i++)
		scanf("%d", &qp[i]), P[i] = i;
	sort(P, P + q, [](int i, int j) { return qp[i] < qp[j]; });
	int mx = 0, all = m;
	for(i = 0; i < q; i++) {
		j = P[i];
		while(mx < qp[j]) {
			for(pii e : ar[mx++])
				go(e.fst), go(e.snd), all--;
		}
		ansn[j] = n - d0 - d2 + g0[mx];
		ansm[j] = all - d2 + g0[mx];
	}
	for(i = 0; i < q; i++) printf("%d %d\n", ansn[i], ansm[i]);
}

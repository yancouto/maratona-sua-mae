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
const int N = 30009;
int S[N], sz[N];
int S_[N], sz_[N];
int seen[N], cur;

inline int &S2(int i) {
	if(seen[i] < cur) { seen[i] = cur; S_[i] = S[i]; sz_[i] = sz[i]; }
	return S_[i];
}
inline int &sz2(int i) {
	if(seen[i] < cur) { seen[i] = cur; S_[i] = S[i]; sz_[i] = sz[i]; }
	return sz_[i];
}

int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

int find2(int i) {
	if(S2(S2(i)) != S2(i)) S2(i) = find(S2(i));
	return S2(i);
}

void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}

void join2(int a, int b) {
	if((a = find2(a)) == (b = find2(b))) return;
	if(sz2(a) < sz2(b)) swap(a, b);
	sz2(a) += sz2(b);
	S2(b) = a;
}

int a[N], b[N], c[N], p[N];

int main() {
	int i, j, n, m, k;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		a[i]--; b[i]--; p[i] = i;
	}
	sort(p, p + m, [](int i, int j) { return c[i] < c[j]; });
	int sq = ceil(sqrt(m));
	int mn = INT_MAX;
	int nx;
	for(i = 0; i < m; i++) {
		cur++;
		if((i % sq) == 0) {
			for(j = 0; j < n; j++) S[j] = j, sz[j] = 1;
			bool ok = false; nx = -1;
			for(j = i; j < n && sz2(find2(0)) != n; j++) {
				join2(a[p[j]], b[p[j]]);
				if(!ok && (j > i) && ((j % sq) == 0)) ok = true, nx = j;
				if(ok) join(a[p[j]], b[p[j]]);
			}
			if(nx == -1) nx = m;
			if(sz2(find2(0)) == n) mn = min(mn, c[p[j - 1]] - c[p[i]]);
			continue;
		}
		for(k = nx - 1; k >= i; k--)
			join2(a[p[k]], b[p[k]]);
		for(; j < n && sz2(find2(0)) != n; j++) {
			join2(a[p[j]], b[p[j]]);
			join(a[p[j]], b[p[j]]);
		}
		if(sz2(find2(0)) == n) mn = min(mn, c[p[j - 1]] - c[p[i]]);
	}
	printf("%d\n", mn);
}

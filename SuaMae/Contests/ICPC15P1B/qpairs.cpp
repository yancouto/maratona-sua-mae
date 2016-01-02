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

const int N = 100009;
int a[N], b[N], c[2*N], cn, p[N];
int qi[N], qa[N], qb[N], ans[N];

pii t[N << 3];
inline int L(int i) { return i << 1; }
inline int R(int i) { return L(i) + 1; }
void build(int i, int l, int r) {
	t[i] = pii(INT_MAX, -2);
	if(l == r) return;
	int m = (l + r) / 2;
	build(L(i), l, m);
	build(R(i), m + 1, r);
}

pii get(int i, int l, int r, int ql, int qr) {
	if(r < ql || l > qr) return pii(INT_MAX, -2);
	if(l >= ql && r <= qr) return t[i];
	int m = (l + r) / 2;
	return min(get(L(i), l, m, ql, qr),
	           get(R(i), m + 1, r, ql, qr));
}

void upd(int i, int l, int r, int x, pii val) {
	t[i] = min(t[i], val);
	if(l == r) return;
	int m = (l + r) / 2;
	if(x <= m) upd(L(i), l, m, x, val);
	else upd(R(i), m + 1, r, x, val);
}
int comp(int x) {
	return lower_bound(c, c + cn, x) - c;
}

inline void add_pt(int i) {
	upd(1, 0, cn - 1, comp(b[i]), pii(b[i] + a[i], i));
}

inline int get_ans(int bb) {
	pii r = get(1, 0, cn - 1, comp(bb), cn - 1);
	return r.snd + 1;
}


int main() {
	int i, n, q;
	scanf("%d %d", &n, &q);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < n; i++) {
		scanf("%d", &b[i]), p[i] = i;
		c[i] = b[i];
	}
	sort(p, p + n, [](int i, int j) { return a[i] > a[j]; });
	for(i = 0; i < q; i++) {
		scanf("%d %d", &qa[i], &qb[i]), qi[i] = i;
		c[i + n] = qb[i];
	}
	sort(c, c + n + q);
	cn = unique(c, c + n + q) - c;
	build(1, 0, cn - 1);
	sort(qi, qi + q, [](int i, int j) { return qa[i] > qa[j]; });
	int pos = 0;
	for(i = 0; i < q; i++) {
		int j = qi[i];
		while(pos < n && a[p[pos]] >= qa[j])
			add_pt(p[pos++]);
		ans[j] = get_ans(qb[j]);
	}
	for(i = 0; i < q; i++)
		printf("%d\n", ans[i]);
}

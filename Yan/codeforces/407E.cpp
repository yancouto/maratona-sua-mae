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

const int MAX = 200003;
int n, k, d, a[MAX];
struct tr {
	int mn, mx, sz;
	tr() {}
	tr(int a, int b, int c) : mn(a), mx(b), sz(c) {}
	inline int& operator[](int i) {
		if(i == 0) return mn;
		if(i == 1) return mx;
		return sz;
	}
	int val() const { return mx - mn + 1 - sz; }
	bool operator < (const tr &o) const { return val() < o.val(); }
};
struct tt {
	tr a, b[2];
	tt() : a(0, 2000000009, 0) {
		b[0] = tr(0, 2000000009, 0);
		b[1] = tr(-2000000009, 0, 0);
	}
};
tt join(const tt &a, const tt &b) {
	tt c;
	c.a = min(a.a, b.a);
	c.b[0] = min(a.b[0], b.b[0]);
	c.b[1] = min(a.b[1], b.b[1]);
	return c;
}
tt tree[MAX << 2];
int li[2][MAX << 2], lsz[MAX << 2];
inline int l(int i) { return i << 1; }
inline int r(int i) { return (i << 1) + 1; }

void unlazei(int ind, int i, int from, int to) {
	if(!li[ind][i]) return;
	tree[i].a = tree[i].b[ind];
	tree[i].a[ind] = li[ind][i];
	tree[i].b[ind^1][ind] = li[ind][i];
	if(from != to)
		li[ind][l(i)] = li[ind][r(i)] = li[ind][i];
	li[ind][i] = 0;
}
void unlazesz(int i, int from, int to) {
	if(!lsz[i]) return;
	tree[i].a.sz += lsz[i];
	tree[i].b[0].sz += lsz[i];
	tree[i].b[1].sz += lsz[i];
	if(from != to) {
		lsz[l(i)] += lsz[i];
		lsz[r(i)] += lsz[i];
	}
	lsz[i] = 0;
}

void unlaze(int i, int from, int to) {
	if(li[0][i] && li[1][i]) {
		for(int j = 0; j < 2; j++) {
			tree[i].b[!j][j] = tree[i].a[j] = li[j][i];
			if(from != to) li[j][l(i)] = li[j][r(i)] = li[j][i];
			li[j][i] = 0;
		}
	} else
		for(int j = 0; j < 2; j++)
			unlazei(j, i, from, to);
	unlazesz(i, from, to);
}

tt query(int i, int from, int to, int ql, int qr) {
	unlaze(i, from, to);
	if(from > qr || to < ql) return tt();
	if(from >= ql && to <= qr) return tree[i];
	int mid = (from + to) / 2;
	return join(query(l(i), from, mid, ql, qr), query(r(i), mid + 1, to, ql, qr));
}

void set_i(int ind, int i, int from, int to, int ql, int qr, int val) {
	unlaze(i, from, to);
	if(from > qr || to < ql) return;
	if(from >= ql && to <= qr) {
		li[ind][i] = val;
		unlazei(ind, i, from, to);
		return;
	}
	int mid = (from + to) / 2;
	set_i(ind, l(i), from, mid, ql, qr, val);
	set_i(ind, r(i), mid + 1, to, ql, qr, val);
	tree[i] = join(tree[l(i)], tree[r(i)]);
}

void add1_sz(int i, int from, int to, int ql, int qr) {
	unlaze(i, from, to);
	if(from > qr || to < ql) return;
	if(from >= ql && to <= qr) {
		lsz[i] = 1;
		unlazesz(i, from, to);
		return;
	}
	int mid = (from + to) / 2;
	add1_sz(l(i), from, mid, ql, qr);
	add1_sz(r(i), mid + 1, to, ql, qr);
	tree[i] = join(tree[l(i)], tree[r(i)]);
}
int mxx[MAX][19], mnn[MAX][19];
void pre() {
	int i, j;
	for(i = 0; i < n; i++)
		mxx[i][0] = mnn[i][0] = a[i] / d;
	for(j = 1; j < 19; j++)
		for(i = 0; i < n; i++) {
			if(i + (1 << (j - 1)) >= n) {
				mxx[i][j] = mxx[i][j - 1];
				mnn[i][j] = mnn[i][j - 1];
				continue;
			}
			mxx[i][j] = max(mxx[i][j - 1], mxx[i + (1 << (j - 1))][j - 1]);
			mnn[i][j] = min(mnn[i][j - 1], mnn[i + (1 << (j - 1))][j - 1]);
		}
}
int mn(int s, int e) {
	int p = 31 - __builtin_clz(e - s + 1);
	return min(mnn[s][p], mnn[e - (1 << p) + 1][p]);
}
int mx(int s, int e) {
	int p = 31 - __builtin_clz(e - s + 1);
	return max(mxx[s][p], mxx[e - (1 << p) + 1][p]);
}

map<int, int> ocs, noc;

void add(int num) {
	ocs[noc[num]]--;
	ocs[++noc[num]]++;
}

void rem(int num) {
	if(--ocs[noc[num]] == 0) ocs.erase(noc[num]);
	ocs[--noc[num]]++;
}

int bl, br;
void d0() {
	for(int i = n - 1; i >= 0; ) {
		int j = i;
		for(i--; i >= 0 && a[i] == a[i + 1]; i--);
		if(j - i >= br - bl + 1) {
			bl = i + 1;
			br = j;
		}
	}
	printf("%d %d\n", bl + 1, br + 1);
	exit(0);
}
void process(int s, int e) {
	int i;
	ocs.clear(); noc.clear();
	ocs[0] = 0; int cr = e;
	for(i = e; i >= s; i--) {
		add(a[i]);
		while(true) {
			auto it = ocs.end(); --it;
			if(it->fst <= 1) break;
			rem(a[cr--]);
		}
		//printf("pos %d -> %d\n", i, cr);
		//for(int j = i; j <= cr; j++) {
		//	tt t = query(1, 0, n - 1, j, cr);
		//	printf("(%d, %d, %d) ", t.a.mn, t.a.mx, t.a.sz);
		//	//printf("%d ", t.a.val());
		//}
		//putchar('\n');
		add1_sz(1, 0, n - 1, i, cr);
		int mnl = i, mnr = cr;
		while(mnl < mnr) {
			int m = (mnl + mnr + 1) / 2;
			if(mn(i, m) == a[i]) mnl = m;
			else mnr = m - 1;
		}
		//for(int j = i; j <= cr; j++) {
		//	tt t = query(1, 0, n - 1, j, cr);
		//	printf("(%d, %d, %d) ", t.a.mn, t.a.mx, t.a.sz);
		//	//printf("%d ", t.a.val());
		//}
		//putchar('\n');
		set_i(0, 1, 0, n - 1, i, mnl, a[i]);
		mnl = i; mnr = cr;
		while(mnl < mnr) {
			int m = (mnl + mnr + 1) / 2;
			if(mx(i, m) == a[i]) mnl = m;
			else mnr = m - 1;
		}
		//for(int j = i; j <= cr; j++) {
		//	tt t = query(1, 0, n - 1, j, cr);
		//	printf("(%d, %d, %d) ", t.a.mn, t.a.mx, t.a.sz);
		//	//printf("%d ", t.a.val());
		//}
		//putchar('\n');
		set_i(1, 1, 0, n - 1, i, mnl, a[i]);
		//for(int j = i; j <= cr; j++) {
		//	tt t = query(1, 0, n - 1, j, cr);
		//	printf("(%d, %d, %d) ", t.a.mn, t.a.mx, t.a.sz);
		//	//printf("%d ", t.a.val());
		//}
		//putchar('\n');
		//for(int j = i; j <= cr; j++) {
		//	tt t = query(1, 0, n - 1, j, j);
		//	printf("(%d, %d, %d) ", t.a.mn, t.a.mx, t.a.sz);
		//	//printf("%d ", t.a.val());
		//}
		//putchar('\n');
		//for(int j = i; j <= cr; j++) {
		//	tt t = query(1, 0, n - 1, j, cr);
		//	//printf("(%d, %d, %d) ", t.a.mn, t.a.mx, t.a.sz);
		//	printf("%d ", t.a.val());
		//}
		//putchar('\n');
		mnl = i; mnr = cr;
		while(mnl < mnr) {
			int m = (mnl + mnr + 1) / 2;
			if(query(1, 0, n - 1, m, cr).a.val() <= k) mnl = m;
			else mnr = m - 1;
		}
		//printf("gto %d -> %d\n", i, mnl);
		if(mnl - i + 1 >= br - bl + 1) {
			bl = i;
			br = mnl;
			//printf("%d -> %d: ", bl, br);
			//for(int j = bl; j <= br; j++)
			//	printf("%d ", a[j]);
			//printf("ok\n");
		}
	}
}

int main() {
	int i;
	scanf("%d %d %d", &n, &k, &d);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] += 1000000001;
	}
	bl = 0; br = -1;
	if(d == 0) d0();
	pre();
	for(i = n - 1; i >= 0;) {
		int j = i;
		for(i--; i >= 0 && (a[i] % d) == (a[i+1] % d); i--) a[i+1] /= d;
		a[i+1] /= d;
		process(i + 1, j);
		//puts("----------------");
	}
	printf("%d %d\n", bl + 1, br + 1);
	return 0;
}

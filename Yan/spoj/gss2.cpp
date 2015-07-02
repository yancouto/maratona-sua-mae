// SIGSEV????
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#define debug(args...) //fprintf(stderr, "%3d: ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
using namespace std;
typedef long long ull;

const int MAX = 100009;
int n, q, sq_n;
int a[MAX];
int ql[MAX], qr[MAX];
int qs[MAX];

inline int bl(int i) { return i / sq_n; }
inline int mx_bl(int b) { return (b + 1) * sq_n - 1; }
bool cmp_r(int i, int j) { return qr[i] < qr[j]; }
bool cmp_block(int i, int j) { return bl(ql[i]) < bl(ql[j]); }

inline int l(int i) { return i << 1; }
inline int r(int i) { return l(i) + 1; }
struct inter {
	ull left, right, all;
	inter& operator = (ull i) {
		left = right = all = i;
		return *this;
	}
};
inter *tree, *treebak;
int *tree_seen, tempo;
inter& update_tree(int ind, int from, int to, int i, int x) {
	inter &t = tree[ind];
	if(treebak && tree_seen[ind] < tempo) {
		tree_seen[ind] = tempo;
		t = treebak[ind];
	}
	if(i < from || i > to) return t;
	if(from == to) {
		t.all = x;
		t.left = t.right = max(0, x);
		return t;
	}
	int mid = (from + to) / 2;
	inter &tl = update_tree(l(ind), from, mid, i, x);
	inter &tr = update_tree(r(ind), mid + 1, to, i, x);
	t.left = max(tl.left, tl.all + tr.left);
	t.right = max(tr.right, tr.all + tl.right);
	t.all = tl.all + tr.all;
}
// inter query(int ind, int from, int to, int i) {
// 	if(from == to) {
// 		if(treebak && tree_seen[ind] < tempo) {
// 			tree_seen[ind] = tempo;
// 			tree[ind] = treebak[ind];
// 		}
// 		return tree[ind];	
// 	} 
// 	int mid = (from + to) / 2;
// 	if(i <= mid) return query(l(ind), from, mid, i);
// 	else return query(r(ind), mid + 1, to, i);
// }
void set_and_update(inter *t, inter *tb, int *ts, int i, int x) {
	tree = t; treebak = tb; tree_seen = ts;
	update_tree(1, 0, n - 1, i, x);
}

int mp[MAX], seen[MAX];
inter *tl, *tr, *tbl, *tbr;
int *ll, *lbl, *lr, *lbr;
int tseen[2][MAX << 2];
inline int get(int *last, int *lastbk, int i) {
	if(lastbk && seen[i] < tempo) {
		seen[i] = tempo;
		last[i] = lastbk[i];
	}
	return last[i];
}


struct resp {
	ull left, right, best;
	resp() : left(0), right(0), best(0) {}
	void update() {
		if(tbl && tseen[0][1] < tempo) {
			tl[1] = tbl[1];
			tseen[0][1] = tempo;
		}
		if(tbr && tseen[1][1] < tempo) {
			tr[1] = tbr[1];
			tseen[1][1] = tempo;
		}
		right = tr[1].right;
		left = tl[1].left;
		best = max(max(left, right), best);
	}
	void add_right(int i) {
		int x = mp[a[i]];
		if(get(lr, lbr, a[i]) != -1)
			set_and_update(tr, tbr, tseen[1], lr[a[i]], 0);
		else {
			ll[a[i]] = i;
			set_and_update(tl, tbl, tseen[0], i, x);
		}
		lr[a[i]] = i;
		set_and_update(tr, tbr, tseen[1], i, x);
		update();
	}
	void add_left(int i) {
		debug("adding %d [%d]", i + 1, mp[a[i]]);
		// tree = tl; treebak = tbl;
		// for(int i = 0; i < n; i++)
		// 	printf("%3d ", query(1, 0, n - 1, i).all);
		// printf("\n");
		int x = mp[a[i]];
		if(get(ll, lbl, a[i]) != -1)
			set_and_update(tl, tbl, tseen[0], ll[a[i]], 0);
		else  {
			lr[a[i]] = i;
			set_and_update(tr, tbr, tseen[1], i, x);
		}
		ll[a[i]] = i;
		set_and_update(tl, tbl, tseen[0], i, x);
		update();
		// tree = tl; treebak = tbl; tree_seen = tseen[0];
		// for(int i = 0; i < n; i++)
		// 	printf("%3d ", query(1, 0, n - 1, i).all);
		// printf("\n");
		debug("left %d right %d best %d", left, right, best);
	}
};

inter ts[5][MAX << 2];
int ls[5][MAX];
ull rr[MAX];

int main() {
	int i, j, k;
	scanf("%d", &n); sq_n = ceil(sqrt(n));
	unordered_map<int, int> in; j = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		// printf("%d ", a[i]);
		ls[0][i] = -1;
		if(in.count(a[i])) a[i] = in[a[i]];
		else { mp[j] = a[i]; in[a[i]] = j; a[i] = j++; }
	}
	// printf("\n");

	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		scanf("%d %d", &ql[i], &qr[i]);
		qs[i] = i; ql[i]--; qr[i]--;
	}
	sort(qs, qs + q, cmp_r);
	stable_sort(qs, qs + q, cmp_block);
	// stuuuuuuuff
	for(i = j = 0; j < q; i++) {
		for(; j < q && bl(qr[qs[j]]) == i; j++) {
			debug("raça (%d, %d)", ql[qs[j]] + 1, qr[qs[j]] + 1);
			resp sol;
			lbl = lbr = ls[0];
			ll = ls[1]; lr = ls[2];
			tbl = tbr = ts[0]; tl = ts[1]; tr = ts[2];
			tempo++;
			for(k = ql[qs[j]]; k <= qr[qs[j]]; k++)
				sol.add_right(k);
			rr[qs[j]] = sol.best;
			debug("sol: %d\n", ql[qs[j]]);
		}
		for(k = 0; k < n; k++)
			ls[1][k] = ls[2][k] = -1;
		for(k = 0; k < 4*n + 3; k++)
			ts[1][k] = ts[2][k] = 0;
		resp r1; int r = mx_bl(i);
		for(; j < q && bl(ql[qs[j]]) == i; j++) {
			debug("nice (%d, %d)", ql[qs[j]] + 1, qr[qs[j]] + 1);
			lbl = lbr = NULL;
			ll = ls[1]; lr = ls[2];
			tbl = tbr = NULL;
			tl = ts[1]; tr = ts[2];
			while(r < qr[qs[j]]) r1.add_right(++r);
			debug("%d to %d --- best %d", mx_bl(i) + 2, qr[qs[j]] + 1, r1.best);
			resp r2 = r1;
			lbl = ls[1]; lbr = ls[2];
			ll = ls[3]; lr = ls[4];
			tbl = ts[1]; tbr = ts[2];
			tl = ts[3]; tr = ts[4];
			tempo++;
			for(k = mx_bl(i); k >= ql[qs[j]]; k--)
				r2.add_left(k);
			rr[qs[j]] = r2.best;
			debug("sol: %d\n", ql[qs[j]]);
		}
	}

	for(i = 0; i < q; i++)
		printf("%lld\n", rr[i]);
	return 0;
}
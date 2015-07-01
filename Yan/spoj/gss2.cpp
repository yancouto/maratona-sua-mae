// WROOOOOOOOOOOONG
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAX = 100009;
int n, q, sq_n;
int a[MAX];
int ql[MAX], qr[MAX];
int qs[MAX];

inline int bl(int i) { return i / sq_n; }
inline int mx_bl(int b) { return (b + 1) * sq_n - 1; }
bool cmp_r(int i, int j) { return qr[i] < qr[j]; }
bool cmp_block(int i, int j) { return bl(ql[i]) < bl(ql[j]); }
// ---------------------------------
inline int l(int i) { return i << 1; }
inline int r(int i) { return l(i) + 1; }
int it[MAX], tempo; int it2[MAX];

typedef pair<int, int> inter;
#define sum first
#define sz second

struct T {
	inter all, from_beg, to_end, all_true;
} treel[4 * MAX], treer[4 * MAX], treeaux[4 * MAX], treeaux2[2][4 * MAX];
T *tt, *tbak, *tl, *tr, *tbakr, *tbakl;
struct {
	inline T& operator [] (int i) {
		if(tbak && it2[i] < tempo) {
			it2[i] = tempo;
			tt[i] = tbak[i];
		}
		return tt[i];
	}
} tree;

inter operator +(const inter &a, const inter &b) {
	return make_pair(a.sum + b.sum, a.sz + b.sz);
}

void join(T &t, T &s1, T &s2, int from, int mid, int to) {
	//printf("from %d mid %d to %d\n", from + 1, mid + 1, to + 1);
	//printf("s1 (all=(%d, %d), from_beg=(%d, %d), to_end(%d, %d), all_true(%d, %d))\n", s1.all.sum, s1.all.sz, s1.from_beg.sum, s1.from_beg.sz, s1.to_end.sum, s1.to_end.sz, s1.all_true.sum, s1.all_true.sz);
	//printf("s2 (all=(%d, %d), from_beg=(%d, %d), to_end(%d, %d), all_true(%d, %d))\n", s2.all.sum, s2.all.sz, s2.from_beg.sum, s2.from_beg.sz, s2.to_end.sum, s2.to_end.sz, s2.all_true.sum, s2.all_true.sz);
	
	if(s1.to_end + s2.from_beg > max(s1.all, s2.all))
		t.all = s1.to_end + s2.from_beg;
	else
		t.all = max(s1.all, s2.all);

	if(s1.from_beg.sz == 0)
		t.from_beg = s2.from_beg;
	else if(s1.from_beg.sz == mid - from + 1 && s2.from_beg.sum >= 0)
		t.from_beg = s1.from_beg + s2.from_beg;
	else if(s1.all_true + s2.from_beg > s1.from_beg)
		t.from_beg = s1.all_true + s2.from_beg;
	else
		t.from_beg = s1.from_beg;
	
	if(s2.to_end.sz == 0)
		t.to_end = s1.to_end;
	else if(s2.to_end.sz == to - mid && s1.to_end.sum >= 0)
		t.to_end = s2.to_end + s1.to_end;
	else if(s1.to_end + s2.all_true > s2.to_end)
		t.to_end = s1.to_end + s2.all_true;
	else
		t.to_end = s2.to_end;
	
	t.all_true = s1.all_true + s2.all_true;
	
	//printf("t (all=(%d, %d), from_beg=(%d, %d), to_end(%d, %d), all_true(%d, %d))\n\n", t.all.sum, t.all.sz, t.from_beg.sum, t.from_beg.sz, t.to_end.sum, t.to_end.sz, t.all_true.sum, t.all_true.sz);
}

T& build_tree(int ind, int from, int to) {
	T &t = tree[ind];
	if(from == to) {
		t.all.sz = t.from_beg.sz = t.to_end.sz = t.all_true.sz = 1;
		t.from_beg.sum = t.to_end.sum = t.all_true.sum = t.all.sum = 0;
		return t;
	}
	int mid = (from + to) / 2;
	T &s1 = build_tree(l(ind), from, mid);
	T &s2 = build_tree(r(ind), mid + 1, to);
	join(t, s1, s2, from, mid, to);
	return t;
}

T empty;

T query_tree(int ind, int from, int to, int ql, int qr) {
	if(qr < from || ql > to) return empty;
	if(from >= ql && to <= qr) return tree[ind];
	int mid = (from + to) / 2;
	T a = query_tree(l(ind), from, mid, ql, qr);
	T b = query_tree(r(ind), mid + 1, to, ql, qr);
	if(a.all_true.sz == 0) return b;
	if(b.all_true.sz == 0) return a;
	T t;
	join(t, a, b, from, mid, to);
	return t;
}

T& update_tree(int ind, int from, int to, int i, int y) {
	T &t = tree[ind];
	if(to < i || from > i) return t;
	if(from == to) {
		t.all.sum = t.from_beg.sum = t.to_end.sum = t.all_true.sum = y;
		return t;
	}
	int mid = (from + to) / 2;
	T &s1 = update_tree(l(ind), from, mid, i, y);
	T &s2 = update_tree(r(ind), mid + 1, to, i, y);
	join(t, s1, s2, from, mid, to);
	return t;
}
// ---------------------------------


int *seen, *seen_bak;
int Sseen[3][MAX];
inline int& get(int i) { 
	if(seen_bak && it[i] < tempo) { it[i] = tempo; seen[i] = seen_bak[i]; }
	return seen[i];
}

int mp[MAX];
struct sol {
	int left, right, best, all;
	sol() : left(0), right(0), best(0), all(0) {}
	void add_right(int i) {
		printf("before add_right(%d)\nleft = %d\nright"
			"= %d\nbest = %d\nall = %d\n\n", i, left, right, best, all);
		tt = tr; tbak = tbakr;  int x = mp[a[i]];
		if(get(a[i]) != -1)
			update_tree(1, 0, n - 1, seen[a[i]], 0);
		else {
			all += x;
			tt = tl; tbak = tbakl;
			update_tree(1, 0, n - 1, i, x);
		}
		tt = tr; tbak = tbakr;
		seen[a[i]] = i;
		printf("x %d i %d\n", x, i);
		update_tree(1, 0, n - 1, i, x);
		right = query_tree(1, 0, n - 1, 0, n - 1).to_end.sum;
		for(int k = 0; k < n; k++) printf("%d ", query_tree(1, 0, n - 1, k, k).all_true.sum);
		printf("\nright %d\n", right);
		if(right < 0)
			right = 0;
		if(all > left) left = all;
		best = max(max(best, left), right);
		printf("after add_right(%d)\nleft = %d\nright"
			"= %d\nbest = %d\nall = %d\n\n", i, left, right, best, all);
	}
	void add_left(int i) {
		tt = tl; tbak = tbakl;  int x = mp[a[i]];
		if(get(a[i]) != -1)
			update_tree(1, 0, n - 1, seen[a[i]], 0);
		else {
			all += x;
			tt = tr; tbak = tbakr;
			update_tree(1, 0, n - 1, i, x);
		}
		tt = tl; tbak = tbakl;
		seen[a[i]] = i;
		update_tree(1, 0, n - 1, i, x);
		left = query_tree(1, 0, n - 1, 0, n - 1).from_beg.sum;
		for(int k = 0; k < n; k++) printf("%d ", query_tree(1, 0, n - 1, k, k).all_true.sum);
		printf("\nleft %d\n", left);
		if(left < 0)
			left = 0;
		if(all > right) right = all;
		best = max(max(best, right), left);
		printf("after add_left(%d)\nleft = %d\nright"
			"= %d\nbest = %d\nall = %d\n\n", i, left, right, best, all);
	}
};

int main() {
	int i, j, k;
	scanf("%d", &n); sq_n = ceil(sqrt(n));
	unordered_map<int, int> in; j = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		Sseen[0][i] = -1;
		if(in.count(a[i])) a[i] = in[a[i]];
		else { mp[j] = a[i]; a[i] = in[a[i]] = j++; }
	}
	tt = treeaux;
	build_tree(1, 0, n - 1);

	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		scanf("%d %d", &ql[i], &qr[i]);
		qs[i] = i; ql[i]--; qr[i]--;
	}
	sort(qs, qs + q, cmp_r);
	stable_sort(qs, qs + q, cmp_block);
	for(i = j = 0; j < q; i++) {
		seen = Sseen[2]; seen_bak = Sseen[0];
		for(; j < q && bl(qr[qs[j]]) == i; j++) {
			printf("raça (%d, %d)\n", ql[qs[j]] + 1, qr[qs[j]] + 1);
			sol resp; tempo++;
			tr = treer; tl = treel; tbakr = tbakl = treeaux;
			for(k = ql[qs[j]]; k <= qr[qs[j]]; k++)
				resp.add_right(k);
			ql[qs[j]] = resp.best;
		}
		for(k = 0; k < n; k++) Sseen[1][k] = -1;
		tt = treeaux2[0];
		build_tree(1, 0, n - 1);
		tt = treeaux2[1];
		build_tree(1, 0, n - 1);
		int r = mx_bl(i); sol resp;
		for(; j < q && bl(ql[qs[j]]) == i; j++) {
			printf("nice (%d, %d)\n", ql[qs[j]] + 1, qr[qs[j]] + 1);
			seen = Sseen[1]; seen_bak = NULL;
			tl = treeaux2[0]; tr = treeaux2[1]; tbak = tbakl = tbakr = NULL;
			while(r < qr[qs[j]]) resp.add_right(++r); 
			tempo++;
			seen = Sseen[2]; seen_bak = Sseen[1];
			sol resp2 = resp;
			tl = treel; tr = treer; tbakl = treeaux2[0]; tbakr = treeaux2[1];
			for(k = mx_bl(i); k >= ql[qs[j]]; k--) resp2.add_left(k);
			ql[qs[j]] = resp2.best;
		}
	}
	for(i = 0; i < q; i++)
		printf("%d\n", ql[i]);
	return 0;
}
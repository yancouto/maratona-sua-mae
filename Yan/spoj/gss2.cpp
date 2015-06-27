#include <cstdio>
#include <algorithm>
#include <unordered_set>
using namespace std;

int a[100003];
unordered_multiset<int> seen;

/////////////////////////////////////////////////////////////////////

inline int l(int i) { return i << 1; }
inline int r(int i) { return l(i) + 1; }

typedef pair<int, int> inter;
#define sum first
#define sz second

struct T {
	inter all, from_beg, to_end, all_true;
} tree[400009];

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
		t.all.sum = 0;
		t.all.sz = t.from_beg.sz = t.to_end.sz = t.all_true.sz = 1;
		t.from_beg.sum = t.to_end.sum = t.all_true.sum = t.all.sum;
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
	// if(ind == 1) printf("updating %d to %d\n", i, y);
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


/////////////////////////////////////////////////////////////////////
int ll, rr;
int n;
void right_l() {
	// printf("l(%d)++\n", ll);
	if(ll > rr) { ll++; return; }
	if(a[ll] && seen.count(a[ll]) == 1) update_tree(1, 0, n, ll, 0);
	seen.erase(seen.find(a[ll++]));
}

void left_l() {
	// printf("l(%d)--\n", ll);
	ll--;
	if(ll > rr) return;
	if(a[ll] && seen.count(a[ll]) == 0) update_tree(1, 0, n, ll, a[ll]);
	seen.insert(a[ll]);
}

void right_r() {
	// printf("r(%d)++\n", rr);
	rr++;
	if(rr < ll) return;
	if(a[rr] && seen.count(a[rr]) == 0) update_tree(1, 0, n, rr, a[rr]);
	seen.insert(a[rr]);
}

void left_r() {
	// printf("r(%d)--\n", rr);
	if(rr < ll) { rr--; return; }
	if(a[rr] && seen.count(a[ll]) == 1) update_tree(1, 0, n, rr, 0);
	seen.erase(seen.find(a[rr--]));
}


int ql[100004];
int qr[100004];
int qs[100004];
int sq_n;
bool cmp_r(const int &i, const int &j) {
	return qr[i] < qr[j];
}
bool cmp_block(const int &i, const int &j) {
	return ((int) (ql[i] / sq_n)) < ((int) (ql[j] / sq_n));
}

int main() {
	int q, x, y, i, j;
	empty.all = empty.from_beg = empty.to_end = empty.all_true = make_pair(0, 0);
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	for(sq_n = 1; sq_n * sq_n <= n; sq_n++);
	sq_n--;
	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		qs[i] = i;
		scanf("%d %d", &ql[i], &qr[i]);
		ql[i]--; qr[i]--;
	}
	sort(qs, qs + q, cmp_r);
	stable_sort(qs, qs + q, cmp_block);
	ll = 0;
	rr = -1;
	build_tree(1, 0, n);
	for(i = 0; i < q; i++) {
		while(ll < ql[qs[i]]) right_l();
		while(ll > ql[qs[i]]) left_l();
		while(rr < qr[qs[i]]) right_r();
		while(rr > qr[qs[i]]) left_r();
		ql[qs[i]] = query_tree(1, 0, n, 0, n).all.sum; //resposta
		// printf("got (%d) as %d\n", qs[i], ql[qs[i]]);
	}
	for(i = 0; i < q; i++)
		printf("%d\n", ql[i]);
	return 0;
}
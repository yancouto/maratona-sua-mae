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
const int MAX = 200009;
int S[MAX], sz[MAX];
int get1(int i) {
	if(S[S[i]] != S[i]) S[i] = get(S[i]);
	return S[i];
}
void join(int a, int b) {
	//printf("join %d %d\n", a, b);
	a = get1(a); b = get1(b);
	if(a == b) return;
	if(a > b) swap(a, b);
	S[b] = a;
}
int tree[MAX << 2], lazy[MAX << 2];
inline int l(int i) { return i << 1; }
inline int r(int i) { return (i << 1) + 1; }
void build_tree(int i, int from, int to) {
	lazy[i] = INT_MAX;
	if(from == to) {
		tree[i] = from;
		S[from] = from;
		return;
	}
	int mid = (from + to) / 2;
	build_tree(l(i), from, mid);
	build_tree(r(i), mid + 1, to);
	tree[i] = min(tree[l(i)], tree[r(i)]);
}

void unlaze(int i, int from, int to) {
	if(lazy[i] == INT_MAX) return;
	tree[i] = lazy[i];
	if(from != to) {
		lazy[l(i)] = min(lazy[l(i)], lazy[i]);
		lazy[r(i)] = min(lazy[r(i)], lazy[i]);
	}
	lazy[i] = INT_MAX;
}

int query_tree(int i, int from, int to, int ql, int qr) {
	unlaze(i, from, to);
	if(to < ql || from > qr) return INT_MAX;
	if(from >= ql && to <= qr) return tree[i];
	int mid = (from + to) / 2;
	return min(query_tree(l(i), from, mid, ql, qr), query_tree(r(i), mid + 1, to, ql, qr));
}

void set_tree(int i, int from, int to, int ql, int qr, int val) {
	unlaze(i, from, to);
	if(to < ql || from > qr) return;
	if(from >= ql && to <= qr) {
		lazy[i] = val;
		unlaze(i, from, to);
		return;
	}
	int mid = (from + to) / 2;
	set_tree(l(i), from, mid, ql, qr, val);
	set_tree(r(i), mid + 1, to, ql, qr, val);
	tree[i] = min(tree[l(i)], tree[r(i)]);
}

int n;
int get(int i) {
	int p = query_tree(1, 1, n, i, i);
	int qp = query_tree(1, 1, n, p, p);
	if(qp != p) {
		qp = get(p);
		set_tree(1, 1, n, p, p, qp);
	}
	return qp;
}

void deb(int i, int from, int to) {
	unlaze(i, from, to);
	if(from == to) {
		printf("%02d ", tree[i]);
		return;
	}
	int mid = (from + to) / 2;
	deb(l(i), from, mid);
	deb(r(i), mid + 1, to);
}


int main() {
	int i, q, t, x, y, gx, gy;
	scanf("%d %d", &n, &q);
	build_tree(1, 1, n);
	for(i = 0; i < q; i++) {
		scanf("%d %d %d", &t, &x, &y); 
		if(t == 1) {
			gx = query_tree(1, 1, n, x, x);
			gy = query_tree(1, 1, n, y, y);
			int m = min(gx, gy);
			join(gx, gy);
		} else if(t == 2) {
			int m = query_tree(1, 1, n, x, y);
			set_tree(1, 1, n, x, y, m);
		} else {
			printf("%s\n", (get(x) == get(y))? "YES" : "NO");			
		}
		deb(1, 1, n);
		printf("\n>: ");
	}
	return 0;
}

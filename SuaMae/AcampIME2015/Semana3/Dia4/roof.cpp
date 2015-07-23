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
int n, le[40009];
struct line {
	int x1, y1, x2, y2;
	void read() {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	}
} ls[40009];
bool up(ll x3, ll y3, const line &l) {
	ll x1 = l.x1, x2 = l.x2, y1 = l.y1, y2 = l.y2;
	return ((x2 - x1) * y1 + (x3 - x1) * (y2 - y1)) < y3*(x2-x1);
}

int shit = 0;
bool cmp_line(int i, int j) {
	if(i < j) return !cmp_line(j, i);
	bool u1 = up(ls[i].x1, ls[i].y1, ls[j]);
	bool u2 = up(ls[i].x2, ls[i].y2, ls[j]);
	bool u3 = up(ls[j].x1, ls[j].y1, ls[i]);
	bool u4 = up(ls[j].x2, ls[j].y2, ls[i]);
	if(u1 && u2) return true;
	if(!u1 && !u2) return false;
	if(u3 && u4) return false;
	if(!u3 && !u4) return true;
	return max(ls[i].y1, ls[i].y2) > max(ls[j].y1, ls[j].y2);
}
const int MAX = 1000001;
inline int l(int i) { return i << 1; }
inline int r(int i) { return (i << 1) + 1; }
int tree[2][(MAX + 1) << 2], lazy[2][(MAX + 1) << 2];
void unlaze(int k, int i, int from, int to) {
	if(lazy[k][i] == -1) return;
	tree[k][i] = lazy[k][i] * (to - from + 1);
	if(from != to)
		lazy[k][l(i)] = lazy[k][r(i)] = lazy[k][i];
	lazy[k][i] = -1;
}

void build_tree(int k, int i, int from, int to) {
	 lazy[k][i] = -1;
	 if(from == to) {
		  tree[k][i] = (k == 0);
		  return;
	 }
	 int mid = (from + to) / 2;
	 build_tree(k, l(i), from, mid);
	 build_tree(k, r(i), mid + 1, to);
	 tree[k][i] = tree[k][l(i)] + tree[k][r(i)];
}

void set_tree(int k, int i, int from, int to, int ql, int qr, int x) {
	 unlaze(k, i, from, to);
	 if(from > qr || to < ql) return;
	 if(from >= ql && to <= qr) {
		  lazy[k][i] = x;
		  unlaze(k, i, from, to);
		  return;
	 }
	 int mid = (from + to) / 2;
	 set_tree(k, l(i), from, mid, ql, qr, x);
	 set_tree(k, r(i), mid + 1, to, ql, qr, x);
	 tree[k][i] = tree[k][l(i)] + tree[k][r(i)];
}

int query_tree(int k, int i, int from, int to, int ql, int qr) {
	 unlaze(k, i, from, to);
	 if(from > qr || to < ql) return 0;
	 if(from >= ql && to <= qr) return tree[k][i];
	 int mid = (from + to) / 2;
	 return query_tree(k, l(i), from, mid, ql, qr) + query_tree(k, r(i), mid + 1, to, ql, qr);
}

int resp[40009];
int main() {
	int i;
	for_tests(t, tt) {
		if(tt > 1) putchar('\n');
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			ls[i].read();
			le[i] = i;
		}
		sort(le, le + n, cmp_line);
		build_tree(0, 1, 0, MAX);
		build_tree(1, 1, 0, MAX);

		for(i = 0; i < n; i++) {
			line &li = ls[le[i]];
			//printf("(%d, %d) (%d, %d)\n", li.x1, li.y1, li.x2, li.y2);
			int tot = query_tree(0, 1, 0, MAX, li.x1+1, li.x2);
			//printf("tot=%d\n", tot);
			set_tree(0, 1, 0, MAX, li.x1+1, li.x2, 0);
			tot += query_tree(1, 1, 0, MAX, li.x1, li.x2);
			set_tree(1, 1, 0, MAX, li.x1, li.x2, 0);
			resp[le[i]] = tot;
			if(li.y2 > li.y1) {
				set_tree(1, 1, 0, MAX, li.x1, li.x1, tot);
			}
			else {
				set_tree(1, 1, 0, MAX, li.x2, li.x2, tot);
			}
		}
		for(i = 0; i < n; i++)
			printf("%d\n", resp[i]);
	}
	return 0;
}

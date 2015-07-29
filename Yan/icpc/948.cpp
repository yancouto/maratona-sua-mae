// WAAAA (tem que mudar pra sweep)
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
template<typename num> struct point {
	num x, y;
	point() {}
	point(num a, num b) : x(a), y(b) {}
	point operator + (point o) const { return point(x + o.x, y + o.y); }
	point operator - (point o) const { return point(x - o.x, y - o.y); }
	num operator * (point o) const { return x * o.x + y * o.y; }
	num operator ^ (point o) const { return x * o.y - y * o.x; }
	point operator * (num i) const { return point(x * i, y * i); }
	point operator / (num i) const { return point(x / i, y / i); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num distSqr(point o) const { return (*this - o) * (*this - o); }
	bool operator < (point o) const { return x < o.x || (x == o.x && y < o.y); }
};

typedef point<int> pointi;
const int MAX = 1000002;
pointi ps[80005];
int perm[40009];
int n;

bool cmp_up(int i, int j) {
	pointi p1i = ps[2*i], p2i = ps[2*i+1], p1j = ps[2*j], p2j = ps[2*j+1];
	bool up1 = ((p2i - p1i) ^ (p1j - p1i)) > 0;
	bool up2 = ((p2i - p1i) ^ (p2j - p1i)) > 0;
	bool up3 = ((p2j - p1j) ^ (p1i - p1j)) > 0;
	bool up4 = ((p2j - p1j) ^ (p2i - p1j)) > 0;
	printf("ups %d %d %d %d\n", up1, up2, up3, up4);
	bool r;
	if((up1 == up2) && (up3 == up4) && (up2 == up3)) r = false;
	else if((up1 && up2) || (!up3 && !up4)) r = false;
	else r = true;
	//printf("(%d, %d)-(%d, %d) [%c] %s (%d, %d)-(%d, %d) [%c]\n", p1i.x, p1i.y, p2i.x, p2i.y, i + 'a',  r? "<" : "!<", p1j.x, p1j.y, p2j.x, p2j.y, j + 'a'); 
	printf("---------- %c %s %c ----------\n", i + 'a' + (i > 1),  r? "<" : "!<", j + 'a' + (j > 1)); 
	return r;
}

inline int l(int i) { return i << 1; }
inline int r(int i) { return (i << 1) + 1; }
int tree[2][(MAX+2) << 2], lazy[2][(MAX+2) << 2];
void build_tree(int tr, int i, int from, int to) {
	int *t = tree[tr];
	lazy[tr][i] = -1;
	if(from == to) {
		 t[i] = (tr == 0);
		 return;
	}
	int mid = (from + to) / 2;
	build_tree(tr, l(i), from, mid);
	build_tree(tr, r(i), mid + 1, to);
	t[i] = t[l(i)] + t[r(i)];
}

int* unlaze(int tr, int i, int from, int to) {
	int *t = tree[tr];
	if(lazy[tr][i] == -1) return t;
	t[i] = lazy[tr][i] * (to - from + 1);
	if(from != to)
		 lazy[tr][l(i)] = lazy[tr][r(i)] = lazy[tr][i];
	lazy[tr][i] = -1;
	return t;	 
}

int query_tree(int tr, int i, int from, int to, int ql, int qr) {
	 int *t = unlaze(tr, i, from, to);
	 if(to < ql || from > qr) return 0;
	 if(from >= ql && to <= qr) return t[i];
	 int mid = (from + to) / 2;
	 return query_tree(tr, l(i), from, mid, ql, qr) + query_tree(tr, r(i), mid + 1, to, ql, qr);
}

void set_tree(int tr, int i, int from, int to, int ql, int qr, int val) {
	int *t = unlaze(tr, i, from, to);
	if(to < ql || from > qr) return;
	if(from >= ql && to <= qr) {
		 lazy[tr][i] = val;
		 unlaze(tr, i, from, to);
		 return;
	}
	int mid = (from + to) / 2;
	set_tree(tr, l(i), from, mid, ql, qr, val);
	set_tree(tr, r(i), mid + 1, to, ql, qr, val);
	t[i] = t[l(i)] + t[r(i)];
}

int resp[40009];
int main() {
	int i;
	for_tests(t, tt) {
		if(tt > 1) putchar('\n');
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			perm[i] = i;
			scanf("%d %d %d %d", &ps[2*i].x, &ps[2*i].y, &ps[2*i+1].x, &ps[2*i+1].y);
			//if(i >= 1) printf("%d\n", cmp_up(i-1, i));
		}
		sort(perm, perm + n, cmp_up);
		build_tree(0, 1, 0, MAX);
		build_tree(1, 1, 0, MAX);
		for(i = 0; i < n; i++) {
			pointi p1 = ps[2*perm[i]], p2 = ps[2*perm[i]+1];
			printf("looking (%d, %d) to (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
			int qt = query_tree(0, 1, 0, MAX, p1.x + 1, p2.x) + query_tree(1, 1, 0, MAX, p1.x, p2.x);
			printf("qt = %d\n", qt);
			set_tree(0, 1, 0, MAX, p1.x + 1, p2.x, 0); set_tree(1, 1, 0, MAX, p1.x, p2.x, 0);
			resp[perm[i]] = qt;
			if(p1.y < p2.y)
				set_tree(1, 1, 0, MAX, p1.x, p1.x, qt);
			else
				set_tree(1, 1, 0, MAX, p2.x, p2.x, qt);
		}
		for(i = 0; i < n; i++)
			printf("%d\n", resp[i]);
	}
	return 0;
}

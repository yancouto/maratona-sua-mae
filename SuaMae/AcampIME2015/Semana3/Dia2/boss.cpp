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
#ifndef ONLINE_JUDGE
#	define debug(args...) {fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");}
#else
#	define debug(args...) {}
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
struct per {
	int h, id, sub, sal;
	per *boss;
	int bossid;
	void read() { scanf("%d %d %d", &id, &sal, &h); sub = 0; }
} ps[30009];
struct ss {
	int i;
	ss() {}
	ss(int a) : i(a) {}
	bool operator < (const ss &o) const { return ps[i].sal < ps[o.i].sal;  }
};
bool cmp_h(const per &a, const per &b) {
	if(a.h < b.h) return true;
	if(a.h == b.h) return a.sal < b.sal;
	return false;
}
bool cmp_id(const per &a, const per &b) { return a.id < b.id; }
int m, q;

int main() {
	int i, j, x;
	for_tests(t, tt) {
		scanf("%d %d", &m, &q);
		for(i = 0; i < m; i++) ps[i].read();
		sort(ps, ps + m, cmp_h);
		ps[m - 1].boss = NULL;
		ps[m - 1].bossid = 0;
		set<ss> s;
		s.insert(ss(m - 1));
		for(i = m - 2; i >= 0; i--) {	
			per *b = &ps[s.upper_bound(ss(i))->i];
			ps[i].boss = b;
			ps[i].bossid = b->id;
			s.insert(ss(i));
		}
		for(i = 0; i < m - 1; i++)
			ps[i].boss->sub += ps[i].sub + 1;
		sort(ps, ps + m, cmp_id);
		for(i = 0; i < q; i++) {
			scanf("%d", &x);
			per pp; pp.id = x;
			per *p = lower_bound(ps, ps + m, pp, cmp_id);
			printf("%d ", p->bossid);
			printf("%d\n", p->sub);
		}
	}
}

#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 50009;
int x[N], y[N];
int dist(pii a, pii b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

bool good(set<pii> &s, pii p) {
	return prev(s.upper_bound(p))->y > p.y;
}
pii a, b;
pii dists(pii p) {
	return pii(dist(p, a), dist(p, b));
}

int main() {
	int i, j, n, m;
	for_tests(t, tt) {
		scanf("%d %d", &m, &n);
		for(i = 0; i < n; i++)
			scanf("%d %d", &x[i], &y[i]);
		if(x[0] > x[1]) swap(x[0], x[1]);
		set<pii> s;
		vector<pii> o;
		s.insert(pii(-1, 300000));
		s.insert(pii(300000, -1));
		a = pii(x[0], y[0]); b = pii(x[1], y[1]);
		for(i = 0; i < n; i++) {
			pii k(x[i], y[i]);
			o.pb(k);
			pii p(dists(k));
			if(prev(s.lower_bound(p))->y <= p.y) continue;
			auto it = s.insert(p).first;
			while(next(it)->y >= p.y) {
				s.erase(next(it));
			}
		}
		sort(o.begin(), o.end());
		int tot = 0;
		for(i = 0; i < m; i++) {
			if(!good(s, dists(pii(i, y[0])))) continue;
			int le = y[0], ri = m - 1;
			while(le < ri) {
				int mi = (le + ri + 1) / 2;
				pii p(i, mi);
				if(good(s, dists(p))) le = mi;
				else ri = mi - 1;
			}
			tot += le - y[0];
			le = 0; ri = y[0];
			while(le < ri) {
				int mi = (le + ri) / 2;
				pii p(i, mi);
				if(good(s, dists(p))) ri = mi;
				else le = mi + 1;
			}
			tot += y[0] - le + 1;
		}
		printf("%d\n", tot);
	}
}

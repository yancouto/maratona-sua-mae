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
int n, v;
struct per {
	int tot, paid, i;
	inline bool operator < (per o) const {
		if(distn() != o.distn()) return distn() < o.distn();
		if(tot != o.tot) return tot > o.tot;
		return i < o.i;
	}
	inline int distn() const { return paid * n - v; }
} p[102];

struct cmp {
	bool operator()(int i, int j) {
		return !(p[i] < p[j]);
	}
};

int main() {
	int i, x;
	for_tests(t, tt) {
		scanf("%d %d", &v, &n);
		int tot = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &x);
			p[i].paid = 0; p[i].i = i;
			p[i].tot = x;
			tot += x;
		}
		if(tot < v) { puts("IMPOSSIBLE"); continue; }
		priority_queue<int, vector<int>, cmp> s;
		x = v / n;
		int need = v;
		for(i = 0; i < n; i++) {
			need -= min(x, p[i].tot);
			p[i].paid += min(x, p[i].tot);
			if(p[i].paid != p[i].tot) s.push(i);
		}
		for(i = 0; i < need; i++) {
			x = s.top(); s.pop();
			p[x].paid++;
			if(p[x].paid != p[x].tot) s.push(x);
		}
		printf("%d", p[0].paid);
		for(i = 1; i < n; i++)
			printf(" %d", p[i].paid);
		putchar('\n');
	}
}

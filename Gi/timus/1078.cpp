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

struct Seg {
	int l, r, ind;
	bool operator < (const Seg &o) const {
		if(l == o.l) return r < o.r;
		return l < o.l;
	}
};

int n;
int memo[505][505];
Seg seg[505];

int solve(int i, int lst) {
	if(i == n) return 0;
	int &m = memo[i][lst];
	if(m != -1) return m;
	m = 0;
	int l = seg[i].l, r = seg[i].r;
	int ll = seg[lst].l, rl = seg[lst].r;
	m = max(m, solve(i + 1, lst));
	if(l > ll && l < rl && r > ll && r < rl)
		m = max(m, 1 + solve(i + 1, i));
	return m;
}
vector<int> resp;
void build(int i, int lst) {
	if(i == n) return;
	int ans = solve(i, lst);
	if(ans == solve(i + 1, lst)) { build(i + 1, lst); }
	else {
		resp.pb(seg[i].ind);
		build(i + 1, i);
	}
}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d", &n);
	seg[0].l = -10001;
	seg[0].r = 10001;
	seg[0].ind = 0;
	n++;
	for(int i = 1; i < n; i++) {
		scanf("%d %d", &seg[i].l, &seg[i].r);
		seg[i].ind = i;
	}
	sort(seg, seg + n);
	printf("%d\n", solve(1, 0));
	build(1, 0);
	for(int i = resp.size() - 1; i >= 0; i--) {
		printf("%d", resp[i]);
		if(i > 0) putchar(' ');
	}
	putchar('\n');

	return 0;
}

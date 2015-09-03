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
const ll oo = 1000000000000000;
int n, k;
ll v[205];
ll memo[205][205][32];
ll pre[205][205][205];

ll mmin(ll a, ll b) { if(a < b) return a; return b; }

ll csum(int x, int i, int y) {	
	if(x == i) return 0;
	ll &sum = pre[x][i][y];
	if(sum == -1)
		sum = mmin(v[i] - v[x], v[y] - v[i]) + csum(x, i-1, y);
	return sum;
}

ll solve(int r, int lst, int d) {
	if(r == n && d == k) return csum(lst, n - 1, n);
	else if(r == n) return oo;
	ll &m = memo[r][lst][d];
	if(m != -1) return m;
	m = solve(r + 1, lst, d);
	if(d < k) m = mmin(m, csum(lst, r - 1, r) + solve(r + 1, r, d + 1));
	return m;
}

vector<pii> resp;
void build(int r, int lst, int d) {
	if(r == n) return;
	ll m = solve(r, lst, d);
	if(m == solve(r + 1, lst, d))
		build(r + 1, lst, d);
	else {
		int i;
		if(d == 0) resp.pb(make_pair(1, r));
		else {
			for(i = lst + 1; i <= r; i++) {
				if(v[i] - v[lst] < v[r] - v[i])	continue;
				resp.pb(make_pair(i, r));
				break;
			}
		}
		build(r + 1, r, d + 1);
	}
}

int main() {
	int tt = 1;
	while(42) {
		memset(memo, -1, sizeof memo);
		memset(pre, -1, sizeof pre);
		scanf("%d %d", &n, &k);
		if(n + k == 0) break; n++;
		for(int i = 1; i < n; i++) scanf("%lld", &v[i]);
		v[0] = -oo; v[n] = oo;
		build(1, 0, 0);
		int dp = 1;
		resp.pb(make_pair(n, n));
		printf("Chain %d\n", tt++);
		for(int i = 0; i < resp.size() - 1; i++) {
			int a = resp[i].fst, b = resp[i+1].fst;
			int r = resp[i].snd;
			if(b - a == 1) 
				printf("Depot %d at restaurant %d serves restaurant %d\n",dp++, r, a);
			else
				printf("Depot %d at restaurant %d serves restaurants %d to %d\n",dp++, r, a, b-1);
		}
		printf("Total distance sum = %lld\n\n", memo[1][0][0]);
		resp.clear();
	}
	return 0;
}

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
const int N = 110;

int n;
ll memo[N][2][2];
int a[N];

ll mx(ll a, ll b) { return a > b? a : b; }
ll mn(ll a, ll b) { return a < b? a : b; }

ll solve(int i, int f, int vez) {
	if(i == n) return 0;
	ll &m = memo[i][f][vez];
	if(m != -1) return m;
	if(!f) return m = solve(i, 1, !vez);
	m = a[i] * (!vez) + solve(i + 1, 1, !vez);
	if(a[i] >= 4) m = (vez? mn : mx)(m, (a[i]-4) * (!vez) + 4 * vez + solve(i + 1, 0, !vez));
	return m;
}

int main() {
	freopen("diamonds.in", "r", stdin);
	freopen("diamonds.out", "w", stdout);
	int i, vez;
	scanf("%d", &n);
	memset(memo, -1, sizeof memo);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	cout << solve(0, 0, 0) << ' ' << accumulate(a, a + n, 0ll) - solve(0, 0, 0) << '\n';
	return 0;
}

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
const int N = 2005;
const ll oo = 100000000000;

int n, k, tmp;
ll x;
ll a[N], seen[N], memo[N];
ll acc[N];

ll labs(ll x) { if(x < 0) return -x; return x; }
ll mmin(ll a, ll b) { if(a < b) return a; return b; }

<<<<<<< HEAD

ll c = 0;
ll solve(int i, ll v) {
	if(i == n) return 0;
	ll &m = memo[i];
	if(seen[i] == tmp) return m;
	seen[i] = tmp; m = oo;
	a[n] = a[i];
	for(int j = i + 1; j <= n; j++) {
		if(labs(a[j] - a[i]) <= (j - i) * v) 
			m = mmin(m, j - i - 1 + solve(j, v));
		if(!i) m = mmin(m, j - i + solve(j, v));
	}
	return m;
=======
ll solve(int i, ll v) {
//	printf("State %d\n", i, a[i]);
	if(i >= n-1) return 0;
	ll &m = memo[i];
	if(seen[i] == tmp) return m;
	seen[i] = tmp; m = oo;
	for(int j = i + 1; j < n; j++) {
		if(labs(a[j] - a[i]) <= (j-i) * v) {
			m = mmin(m, j - i - 1 + solve(j, v));
		}
	}
	return m = mmin(m, i + 1 + solve(i + 1, v));
>>>>>>> asc G + cf
}

ll bs(ll l, ll r) {
	if(l >= r) return l;
	ll m = (l + r) / 2;
	tmp++;
<<<<<<< HEAD
=======
	//printf("(%lld %lld) solve(0, %d) = %lld k = %d\n", l, r, m, solve(0, m), k);
>>>>>>> asc G + cf
	if(solve(0, m) > k) return bs(m + 1, r);
	return bs(l, m);
}

int main() {
	int i;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
		scanf("%lld", &a[i]);
<<<<<<< HEAD
=======
//	tmp++;
//	printf("qtd %lld\n", solve(0, 0));
>>>>>>> asc G + cf
	printf("%lld\n", bs(0, 2000000000));	
	return 0;
}

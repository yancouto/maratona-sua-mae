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

ll a, b;
int x;
ll memo[2][70][2][70];
int num[2][70];
int pprec[70];

int prec(int nn) {
	if(nn == 1) return 0;
	if(pprec[nn] == -1) pprec[nn] = 1 + prec(__builtin_popcount(nn));
	return pprec[nn];
}

ll solve(int who, int i, int pre, int sum) {
	if(i == 61) { 
		if(!sum) return (x == 0);
		return (prec(sum) + 1) == x; 
	}
	ll &m = memo[who][i][pre][sum];
	if(m != -1) return m;
	ll ans = 0;
	for(int d = 0; d <= 1; d++) {
		if(pre && d > num[who][i]) break;
		ans += solve(who, i + 1, pre && (num[who][i] == d), sum + d);
	}
	return m = ans;
}

int generate(int who, ll n) {
	int ii = 0;
	int aux[70];
	while(n != 0) { aux[ii++] = (n % 2); n /= 2; }
	for(int i = 60, c = 0; i >= 0, c < ii; c++, i--) num[who][i] = aux[c];
}

int main() {
	memset(pprec, -1, sizeof pprec);
	pprec[0] = 0;
	while(42) {
		scanf("%lld %lld %d", &a, &b, &x);
		if((a + b + x) == 0) return 0;
		a--;
		memset(memo, -1, sizeof memo);	
		memset(num, 0, sizeof num);
		generate(0, a);
		generate(1, b);
		ll r1 = solve(1, 0, 1, 0);
		ll r2 = solve(0, 0, 1, 0);
		if(a > 0 && x == 1) r2--;
		if(a > 0 && x == 0) r2++;
		if(b > 0 && x == 1) r1--;
		if(b > 0 && x == 0) r1++;
		printf("%lld\n", r1 - r2);
	}
	return 0;
}

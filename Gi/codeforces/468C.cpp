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

int n;
int num[25];
ll memo[30][2][300];

ll solve(int i, int pre, int sum) {
	if(i == n) return sum; 
	ll &m = memo[i][pre][sum];
	if(m != -1) return m;
	ll ans = 0;
	for(int d = 0; d <= 9; d++) {
		if(pre && d > num[i]) break;
		ans += solve(i + 1, pre && (d == num[i]), sum + d);
	}
	return m = ans;
}

int count_dig(ll x) {
	int ret = 0;
	while(x != 0) { num[ret++] = x % 10; x /= 10; }
	for(int i = 0, j = ret - 1; i < j; i++, j--) { 
		int aux = num[i];
		num[i] = num[j];
		num[j] = aux;
	}
	return ret;
}

int fx(ll x) {
	int sum = 0;
	while(x) { sum += x % 10; x /= 10; }
	return sum;
}


ll bs(ll l, ll r, int x) {
	if(l >= r) return l;
	ll mid = (l + r) / 2;
	n = count_dig(mid);
	memset(memo, -1, sizeof memo);
	ll val = solve(0, 1, 0);
	if(val >= x) return solve(l, mid, x);
	return solve(mid + 1, r, x);
}

int main() {
	ll a, f, l, r; scanf("%lld", &a);
	l = bs(1, 100000000000000000ll, a);
	r = l;
	n = count_dig(l);
	memset(memo, -1, sizeof memo);
	f = solve(0, 1, 0) % a;
	l = 1;
	while(f) {
		if(f > 0) {	f -= fx(l); l++; }
		else { f += fx(r + 1); r++; }
	}
	printf("%lld %lld\n", l, r);		
	return 0;
	
}

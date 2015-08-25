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

ll pot[15];
vector<ll> pr;
bool mark[1000010];

void prec_pot() {
	pot[0] = 1;
	for(int i = 1; i < 13; i++)
		pot[i] = pot[i-1] * 10;
}

ll prec_pr() {
	ll n = 1000005;
	pr.pb(2);
	for(ll i = 4; i <= n; i += 2) mark[i] = true;
	for(ll i = 3; i <= n; i += 2) {
		if(mark[i]) continue;
		pr.pb(i);
		for(ll j = i + i; j <= n; j += i)
			mark[j] = true;
	}
}

ll generate(int n, ll pre) {
	ll ret = pre * pot[n];
	int dig[5] = {1, 3, 7, 9};
	ret += dig[rand() % 4];
	for(int i = 1; i < n; i++)
		ret += pot[i] * (rand() % 10);
	return ret;
}

int main() {
	srand(time(NULL)); rand(); rand();
	int k; scanf("%d", &k);
	ll x = 0; 
	if(k > 0) scanf("%lld", &x);
	if(x == 0) { printf("000000000003\n"); return 0; }
	if(k == 12) { printf("%lld\n", x); return 0; }
	
	prec_pot();
	prec_pr();
	ll num;	
	while(42) {
		num = generate(12 - k, x);
		bool found = true;
		for(int i = 0; i < pr.size(); i++) {
			if(pr[i] * pr[i] > num) break; 
			if(pr[i] == num) break; 
			if(num % pr[i] == 0) { found = false; break; }
		}
		if(found) break;
	}
	printf("%lld\n", num);
	return 0;
}

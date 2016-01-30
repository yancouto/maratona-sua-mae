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

ll p4[2009];
int ct[12];
void uniq(int &q) {
	for(int i = 1; i < 5; i++)
		q -= max(ct[i], ct[9 - i]) - min(ct[i], ct[9 - i]);
}

ll fexp(ll n, ll p) {
	ll r = 1;
	for(; p; p >>= 1) {
		if(p & 1) r = mod(r * n);
		n = mod(n * n);
	}
	return n;
}
inline ll inv(ll x) { return fexp(x, modn - 2); }


ll ways(int &q) {
	uniq(q);
	ll tot = 0;
	printf("after uniq q = %d\n", q);
	for(int n0 = 0; n0 <= q; n0++)
		for(int n9 = 0; n0 + n9 <= q; n9++) {
			int c9 = ct[9] + n9, c0 = ct[0] + n0, cq = q - n0 - n9;
			if(c9 > c0) cq -= c9 - c0;
			else if(((c0 - c9) & 1) || (cq & 1) || cq < 0) continue;
			printf("n0 %d n9 %d tot += 4^%d\n", n0, n9, cq / 2);
			tot += mod(mod(p4[cq / 2] * inv(fat[n0])) * inv(fat[n9]));
		}
	tot = mod(tot);
	for(int i = 1; i < 5; i++)
		tot = mod(tot * fat[max(ct[i], ct[9 - i]) - min(ct[i], ct[9 - i]))];
	
	return mod(tot);
}

char s[100009];
int main() {
	int i, q = 0;
	fat[0] = 1;
	for(ll i = 1; i < 2000; i++)
		fat[i] = mod(ll(i) * fat[i - 1]);
	p4[0] = 1;
	for(i = 1; i <= 2000; i++)
		p4[i] = mod(4ll * p4[i - 1]);
	scanf("%s", s);
	for(i = 0; s[i]; i++)
		if(isdigit(s[i]))
			ct[s[i] - '0']++;
		else q++;
	int Q = q;
	ll tot = 0;
	for(i = 1; i <= 5; i++) {
		q = Q;
		ct[i]--;
		ct[10-i]--;
		bool a = false, b = false;
		if(ct[i] < 0) ct[i]++, q--, a = true;
		if(ct[10 - i] < 0) ct[10 - i]++, q--, b = true;
		printf("tot %d = %lld\n", i, tot);
		tot += ways(q);
		if(!a) ct[i]++;
		if(!b) ct[10 - i]++;
	}
	for(i = 1; i <= Q; i++) tot = mod(tot * ll(i));
	printf("%d\n", int(tot));
}

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 10001;
inline ll mod(ll x) { return x % modn; }
ll t, poss[10009], ts[10009];

ll fexp(ll x, ll p) {
	ll y = x;
	//printf("%lld^%lld = ", x, p);
	ll resp = 1;
	for(ll i = 1; i <= p; i <<= 1) {
		if(i & p) resp = mod(resp * x);
		x = mod(x * x);
	}
	//printf("%lld (%lld)\n", resp, mod(resp * y));
	return resp;
}

int main() {
	int i;
	scanf("%lld", &t);
	for(i = 0; i < t; i++)
		scanf("%lld", &ts[i]);
	if(t == 1) { puts("69"); return 0; }
	for(i = 0; i < t - 1; i++) {
		for(ll a = 0; a < 10000; a++) {
			if(!((a+1)%73) || !((a+1)%137)) { poss[a] = -1; continue; }
			ll c = mod(ts[i + 1] - mod(a * a * ts[i]) + modn);
			c = mod(c * fexp(a + 1, 9791));
			if(i == 0 || poss[a] == c) poss[a] = c;
			else poss[a] = -1;
		}
		if(ts[i + 1] == ts[i]) {
			if(i == 0 || poss[10000] == 1) poss[10000] = 1;
			else poss[10000] = -1;
		} else poss[10000] = -1;
	}
	ll a = 0, b = -1, c;
	while(poss[a] == -1) a++;
	b = poss[a];
	for(i = 0; i < t; i++) {
		printf("%lld\n", mod(a * ts[i] + b));
	}
	return 0;
}

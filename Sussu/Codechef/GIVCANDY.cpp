

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

const ll INF = 1e14;

ll a, b, c, d;

ll gcd(ll i, ll j){
	if(j == 0ll) return i;
	return gcd(j, i%j);
}

int main (){
	for_tests(t, tt){
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		ll A = c, B = d, C = abs(-a+b);
		ll mdc = gcd(A, B);
		//printf("mdc %lld\n", mdc);
		printf("%lld\n", min(abs(mdc-(C%mdc)), C%mdc)); 
		//printf("%lld %lld\n", abs(mdc-(C%mdc)), C%mdc);
	}
}

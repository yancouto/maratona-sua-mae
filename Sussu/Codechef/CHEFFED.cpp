

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

ll n;

ll ans = 0;

ll sum(ll x){
	ll res = 0;
	while( x != 0){
		res += x%10;
		x/=10;
	}
	return res;
}

void test(ll x){
	ll s = sum(x);
	if( n == x + s + sum(s) )
		ans++;
}

int main (){
	scanf("%lld", &n);
	clock_t t;
	t = clock();
	ll nn = n;
	while(nn >= 0 && clock() - t < 0.9*CLOCKS_PER_SEC){
		test(nn);
		nn--;
	}
	printf("%lld\n", ans);

}

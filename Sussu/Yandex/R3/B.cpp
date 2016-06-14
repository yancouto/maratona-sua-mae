

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

ll n, k, res;

ll expo(ll base, ll exp){
	if (exp == 0) return 1;
	ll ans = expo(base, exp/2);
	ans = mod(ans*ans);
	if(exp&1){
		ans = mod(ans*base);
	}
	return ans;
}

int main (){
	scanf("%lld %lld", &n, &k);
	res = expo(2, k);
	res = mod(res + mod(expo(2, k-1) * (n-k))); 
	printf("%lld\n", res);
}

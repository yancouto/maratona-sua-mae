#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ll n, m, res;

inline ll neg(ll val){
	while(val < 0ll)
		val += modn;
	return val;
}

inline ll pa(ll i,ll f){
	ll ans = 0;
	if(f < i) return ans;
	if((f+i)%2ll==0ll)
		ans = mod(mod((f+i)/2ll)*mod(f-i+1ll));
	else
		ans = mod(mod(f+i)*mod((f-i+1ll)/2ll));
	return ans;
}

int main(){
	cin >> n >> m;
	res = mod(mod(n)*mod(m));
	ll ult;
	//accumulate with i = 1 -> sqrt(n)
	for(ll a=1ll;a <= m && a*a <= n;a++){
		ult = (n/a);
		res = neg(res - mod((ll)(n/a)*a));
	}
	//accumulate w/ (n/i) = 1 -> sqrt(n)
	for(ll a=1ll;a*a < n && a < ult;a++){
		res = neg(res - mod(a*pa((n/(a+1ll)) + 1ll, min((ll)(n/a),m))));
	}
	cout << res;
}
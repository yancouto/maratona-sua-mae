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

ll cnt(ll mx){
	ll ans = 0;
	for(ll a = 2; a*a*a <= mx ; a++){
		ans += mx/(a*a*a);
	}
	return ans;
}

int main (){
	cin >> n;
	ll i = 8, j = 1e17 + 1;
	while(i < j){
		ll m = (i + j)/2;
		if(cnt(m) >= n){
			j = m;
		}
		else{
			i = m+1;
		}
	}
	if(cnt(i) != n)
		puts("-1");
	else{
		cout << i;
	}
}

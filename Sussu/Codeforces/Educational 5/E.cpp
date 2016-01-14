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

ll n, m;

ll pa(ll a){
	ll ans = 0;
	if(a%2){
		ans = mod(mod(a)*mod((a+1)/2));
	}
	else{
		ans = mod(mod(a/2)*mod(a+1));
	}
	return ans;
}

int main (){
	cin >> n >> m;
	ll ant = n, atu, d = 1, res=0;
	if(m > n){
		res = mod(mod(m-n)*mod(n));
		m = n;
	}
	while(ant > 10000){
		d++;
		atu = (n/d)+1;
		if(m >= ant){
			res = mod(res + mod(pa(n%atu)));
			ant = atu-1;
		}
	}
	for(int a=1;a<ant;a++){
		res = mod(res + n%a);
	}
}
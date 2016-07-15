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

ll sum(ll x){
	ll ans = 0;
	while(x != 0){
		ans += x%10;
		x /=10ll;
	}
	return ans;
}

int main (){
	scanf("%I64d", &n);
	ll u = 0;
	while(u != 999999999999999999 && u*10ll + 9ll <= n){
		u = u*10ll + 9ll;
	}
	printf("%I64d\n%I64d %I64d\n", sum(u) + sum(n - u), u, n-u);

}

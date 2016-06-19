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

ll n, k;

ll fat[110];

ll expo(ll base, ll exp){
	if(exp == 0) return 1ll;
	ll ans = expo(base, exp/2ll);
	ans = mod(ans*ans);
	if(exp&1ll)
		ans = mod(ans*base);
	return ans;
}

ll bin(ll a, ll b){
	return mod(fat[a] * mod(expo(fat[b], modn-2) * expo(fat[a-b], modn-2)));
}

ll fato(ll a, ll b){
	return mod(fat[a] * expo(fat[b], modn-2));
}

int main (){	
	fat[0] = 1ll;
	for(ll a=1ll;a<=51ll;a++){
		fat[a] = mod(fat[a-1]*a);
	}
	for_tests(t, tt){
		scanf("%lld%lld", &n, &k);
		for(int a=0;a<n-1;a++){
			int i, j;
			scanf("%d %d", &i, &j);
		}
		ll res = 0ll;
		for(ll kk = min(n, k-1);kk >=0;kk--){
			//printf("%lld  -  %lld %lld\n", kk, bin(n-1, kk), fato(k, k-(kk+1)));
			res = mod(res + mod(bin(n-1ll, kk)*fato(k, k-(kk+1ll))));
		}
		printf("%lld\n", res);
	}
}

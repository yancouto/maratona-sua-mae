#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n;

map <ll, ll> cus;

ll h(ll x){
	ll i = 0;
	while(x >= (1ll<<i)){
		i++;
	}
	return i;
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int t;
		scanf("%d", &t);
		ll u, v, w;
		if(t == 1){
			cin >> u >> v >> w;
			if(h(v) > h(u))
				swap(u, v);
			while(h(u) > h(v)){
				cus[u] += w;
				u /= 2ll;
			}
			while(u != v){
				cus[u] += w;
				cus[v] += w;
				u /= 2;
				v /= 2;
			}
			//cout << u << " " << v; 
		}
		else{
			cin >> u >> v;
			ll ans = 0ll;
			if(h(v) > h(u))
				swap(u, v);
			while(h(u) > h(v)){
				ans += cus[u];
				u /= 2ll;
			}
			while(u != v){
				ans += cus[u];
				ans += cus[v];
				u /= 2;
				v /= 2;
			}
			cout << ans << endl;
		}
	}
}

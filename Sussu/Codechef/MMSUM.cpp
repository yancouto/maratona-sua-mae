
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const ll MAXN = 112345, INF = 1e9+2;

int n;
ll s[MAXN];
ll e[MAXN], d[MAXN], mx;
ll res;

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		mx = LLONG_MIN;
		res = LLONG_MIN;
		for(int a=1;a<=n;a++){
			scanf("%lld", &s[a]);
			mx = max(mx, s[a]);
		}
		if(mx <= 0){
			printf("%lld\n", mx);
			continue;
		}
		e[0] = e[n+1] = 0ll;
		d[0] = d[n+1] = 0ll;
		for(int a=1;a<=n;a++){
			e[a] = max(0ll, e[a-1] + s[a]);
		}
		for(int a=n;a>0;a--){
			d[a] = max(0ll, d[a+1] + s[a]);
		}
		for(int a=1;a<=n;a++){
			res = max(e[a-1] + max(0ll, s[a]) + d[a+1], res);
		}
		printf("%lld\n", res);
	}
}

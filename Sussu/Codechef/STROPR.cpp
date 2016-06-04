#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<int, piii> piiii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 100009;

int n, x;

ll m, s[MAXN], res;

ll expo(ll num, ll e){
	if(e == 0) return 1ll;
	ll ans = mod(expo(num,e/2ll));
	ans = mod(ans*ans);
	if(e&1ll)
		ans = mod(ans*num);
	return ans;
}

int main (){
	for_tests(t,tt){
		scanf("%d %d %lld", &n, &x, &m);
		for(int a=1;a<=n;a++){
			scanf("%lld", &s[a]);
			s[a] = mod(s[a]);
		}
		ll qnt = 1, p=mod(m), q=1;
		res = 0;
		res = mod(res + s[x]);
		x--;
		while(x){ 
			qnt = mod(mod(p*qnt)*expo(q, modn-2));
			res = mod(res + mod(qnt*s[x]));
			p = mod(p+1);
			q++;
			x--;
		}
		printf("%lld\n", res);
	}
}

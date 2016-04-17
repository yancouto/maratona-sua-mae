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

ll k, c, s;

int main (){
	for_tests(t, tt){
		scanf("%lld%lld%lld", &k , &c, &s);
		printf("Case #%d:", tt);
		ll kc = 1;
		for(int a=1;a<c;a++){
			kc*=k;
		}
		for(ll a=1;a<=k;a++){
			printf(" %lld", a*kc);
		}
		printf("\n");
	}
}
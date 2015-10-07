
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


const long long DEZ=10000000000LL;

ll n, p;

ll formu(ll val){
	return (val*(val+1))/2;
}

int main (){
	for_tests(t,tt){
		scanf("%lld", &n);
		ll i=0,f=DEZ;
		while(i<f){
			ll m = (i+f+1)/2;
			if(formu(m)<=n)
				i=m;
			else
				f=m-1;
		}
		printf("%lld\n", i);
	}
	return 0;
}

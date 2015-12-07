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

inline ll form(ll m){
	return ((m+k)*(k-m+1))/2ll - (k-m);
}

int main (){
	cin >> n >> k;
	if(n<=k){
		if(n!=1)
			printf("1");
		else
			printf("0");
		return 0;
	}
	ll i=2, f=k;
	while(i<f){
		ll m = (i+f)/2;
		if(form(m)>n)
			i = m+1;
		else
			f = m;
	}
	ll res = form(i);
	if((n-res+1 < i && n-res+1>=2) || n-res==0)
		cout << (k-i+1) + 1*(n-res!=0);
	else
		printf("-1");
	return 0;
}	
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

ll n, m;

bool test(ll a, ll b, ll c){
	ll nn = n, mm = m;
	bool ans = 0;
	if(a%n==0 && a/n <= m){
		mm = m - a/n;
		if(b%nn==0 && b/nn <= mm)
			ans =  max(ans, (c == (mm-b/nn)*nn));
		
		if(b%mm==0 && b/mm <= nn)
			ans = max(ans, (c == mm*(nn-b/mm)));
		
	}
	nn = n; mm = m;
	if(a%m == 0 && a/m <= n){
		nn -= a/m;
		if(b%nn==0 && b/nn <= mm)
			ans = max(ans, (c == (mm-b/nn)*nn));
		if(b%mm==0 && b/mm <= nn)
			ans = max(ans, (c == mm*(nn - b/mm)));
	}
	return ans;
}



int main(){
	for_tests(t, tt){
		ll a, b, c;
		scanf("%lld %lld %lld %lld%lld", &n, &m, &a, &b, &c);
		if(a+b+c != n*m){
			puts("No");
			continue;
		}
		if(test(a, b, c) || test(b, c, a) || test(c, a, b) || test(c, b, a) || test(b, a, c) || test(a, c, b))
			puts("Yes");
		else
			puts("No");
	}
}

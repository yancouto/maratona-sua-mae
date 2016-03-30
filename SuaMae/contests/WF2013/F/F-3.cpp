
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

const int MAXN = 1000010;

int n, m;
ll s[MAXN];

bool go(ll d){
	ll lim = 0;
	for(int a=0;a<=lim && a<2*m*n-1;a++){
		if(s[a+1] - s[a] <= d){
			lim += 2*m-1;
			a++;
		}
		if(lim > 2*m*n) break;
	}
	return (lim >= 2*m*n);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<2*n*m;a++){
		scanf("%lld", &s[a]);
	}
	sort(s, s+2*n*m);
	ll i = 0, j = 2000000010;
	while(i < j){
		ll m = (i+j)/2;
		if(go(m)) j = m;
		else i = m + 1;
	}
	printf("%lld\n", i);
}

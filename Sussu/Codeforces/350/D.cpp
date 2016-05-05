
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

const int MAXN = 100010;

ll s[MAXN], r[MAXN], k;

int n;



int main (){
	scanf("%d", &n);
	cin >> k;
	for(int a=0;a<n;a++){
		cin >> r[a];
	}
	for(int a=0;a<n;a++){
		cin >> s[a];
	}
	ll i = 0, f = 2500000000ll;
	while( i < f ){
		ll m = (i+f+1)/2ll;
		ll cus = 0;
		for(int a=0;a<n;a++){
			cus += max(0ll, r[a]*m - s[a]);
			if(cus > k) break;
		}
		if(cus <= k)
			i = m;
		else 
			f = m-1;
	}
	cout << i;
}
	

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

int n;

ll v[100], s[30];

int main(){
	v[0] = 1;
	v[1] = 1;
	int f = 0;
	for(int a=2;v[a-1] < 2000000000ll;a++){
		v[a] = v[a-1] + v[a-2];
		f = a;
	}
	for_tests(t, tt){
		scanf("%d", &n);
		ll res = 1;
		for(int a=0;a<n;a++){
			scanf("%lld", &s[a]);
			ll ans = 0;
			for(int b=f;b>=0;b--){
				if(s[a] >= v[b]){
					s[a] -= v[b];
					ans++;		
				}
			}
			res *= ans;
		}
		printf("Case %d: %lld\n", tt, res);
	}
}

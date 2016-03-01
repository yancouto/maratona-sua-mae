
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

const int MAXN = 1010;

int n, s[MAXN];

int main (){
	scanf("%d", &n);
	ll ult = n+1;
	ll res = 1;
	for(ll a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(s[a] == 1){
			if(ult == n+1){
				ult = a;
				continue;
			}
			res *= (a - ult);
			ult = a;
		}
	}
	if(ult == n+1) res = 0;
	cout << res;
}


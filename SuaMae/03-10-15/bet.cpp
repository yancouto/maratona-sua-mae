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
typedef long double ddd;

int main() {
	ll pot[25][25];
	ll fat[20];
	ll R, S, X, Y, W;
	for(ll i = 1; i <= 20; i++) {
		pot[i][0] = 1ll;
		for(ll j = 1; j <= 10; j++)
			pot[i][j] = pot[i][j-1] * i;
	}
	fat[1] = fat[0] = 1ll;
	for(ll i = 2; i <= 10; i++)
		fat[i] = fat[i-1] * i;
	int n; scanf("%d", &n);
	while(n--) {
		scanf("%lld %lld %lld %lld %lld", &R, &S, &X, &Y, &W);
		ddd prob = 0.0;
		for(; X <= Y; X++)
			prob += (ddd)((ddd)pot[S-R+1][X] / (ddd)pot[S][X]) * (ddd)((ddd)fat[Y] / ((ddd)fat[Y-X] * (ddd)fat[X]));
		prob *= (ddd)W;
		if(prob > 1.0) puts("yes");
		else puts("no");
	}
	return 0;	
}

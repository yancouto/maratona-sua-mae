#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const ll oo = 10000000000;
const int D = 8, dd = 30;

ll X, Y, tmp;
ll dx[D] = {1,-1, 1,-1,2,-2, 2,-2};
ll dy[D] = {2, 2,-2,-2,1, 1,-1,-1};
ll seen[100][100], memo[100][100];

ll dist(ll x,ll y) {
	int i, j;
	ll ret = oo;
	for(i = 0; i < D; i++)
		for(j = i + 1; j < D; j++) {
			ll A = dy[j] * dx[i] - dy[i] * dx[j], B = y * dx[i] - dy[i] * x;
			if(!A || abs(B) % A) continue;
			B = B / A;
			if(abs(x - dx[j] * B) % dx[i]) continue;
			A = (x - dx[j] * B) / dx[i];
			if(A < 0 || B < 0) continue;
			ret = min(ret, A + B);
		}
	return ret;
}

bool isIn(ll x, ll y) { return x <= X + dd && x >= X - dd && y <= Y + dd && y >= Y - dd; }

ll solve(ll x,ll y) {
	int xx = x - X + dd + 2, yy = y - Y + dd + 2;
	ll &ss = seen[xx][yy], &me = memo[xx][yy];
	if(ss == tmp) return oo;
	ss = tmp;
	ll ans = dist(x, y);
	for(int i = 0; i < D; i++)
		if(isIn(x + dx[i], y + dy[i])) 
			ans = min(ans, solve(x + dx[i], y + dy[i]) + 1);
	return me = ans;
}

int main() {
	while(scanf("%lld %lld", &X, &Y) != 0) {
		tmp++; printf("%lld\n", solve(X, Y)); 		
	}
	return 0;
}

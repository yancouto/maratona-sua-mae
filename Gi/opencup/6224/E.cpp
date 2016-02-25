#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const ll oo = 1000000000000000;
const int D = 8, dd = 30;

ll X, Y;
ll dx[D] = {1,-1, 1,-1,2,-2, 2,-2};
ll dy[D] = {2, 2,-2,-2,1, 1,-1,-1};
ll best[100][100];

bool isIn(ll x, ll y) { return x <= dd && x >= -dd && y <= dd && y >= -dd; }
		
void bfs() {
	deque<pii> dq;
	dq.pb(pii(0, 0));
	best[0+dd][0+dd] = 0;
	while(!dq.empty()) {
		pii v = dq.front(); dq.pop_front();
		for(int i = 0; i < D; i++) {
			if(!isIn(v.x+dx[i], v.y+dy[i]) || best[v.x+dx[i]+dd][v.y+dy[i]+dd] != -1) continue;
			best[v.x+dx[i]+dd][v.y+dy[i]+dd] = best[v.x+dd][v.y+dd] + 1ll;
			dq.pb(pii(v.x+dx[i], v.y+dy[i]));
		}
	}
}

ll dist(ll x,ll y) {
	int i, j;
	ll ret = oo;
	x = X - x; y = Y - y;
	if(!x && !y) return 0;
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

void show() {
	for(ll i = dd-5; i < dd+5 ; i++) {
		for(ll j = dd-5; j < dd+5; j++)
			printf("(%lld,%lld)%lld ", i-dd,j-dd,best[i][j]);
		putchar('\n');
	}
}

int main() {
	memset(best, -1, sizeof best);
	bfs(); //show();
	while(scanf("%lld %lld", &X, &Y) != 0) {
		ll ans = LLONG_MAX;
		for(int i = -dd; i < dd; i++)
			for(int j = -dd; j < dd; j++) {
				ans = min(ans, best[i+dd][j+dd] + dist(i, j));
				//printf("[%d][%d] best=%lld dist=%lld min %lld\n", i, j, best[i+dd][j+dd], dist(i, j), ans);
			}
		printf("%lld\n", ans);	
	}
	return 0;
}

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


struct raj {
	int x, y;
};

bool comp(raj a, raj b) {
	if(a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;
}

bool comp2(raj a, raj b) {
	if(a.y == b.y)
		return a.x < b.x;
	return a.y > b.y;
}

int N, H, K;
raj up[2005], low[2005];
int iup, ilow;

ll mmin(ll a, ll b) { return (a > b)?b:a; }
ll memo[2005][2005];
ll solve(int i, int k) {
	if(i == ilow) return 0;
	ll &m = memo[i][k];
	if(m != -1) return m;
	m = low[i].x - low[i].y + solve(i + 1, k);
	if(k) m = mmin(m, solve(i + 1, k - 1));
	return m;
}

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		memset(memo, -1, sizeof memo);
		scanf("%d %d %d", &N, &H, &K);
		iup = ilow = 0;
		for(int i = 0; i < N; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if(b > a) {
				up[iup].x = a;
				up[iup++].y = b;
			}
			else {
				low[ilow].x = a;
				low[ilow++].y = b;
			}
		}
		sort(up, up+iup, comp);
		for(int i = 0; i < iup; i++) {
			H -= up[i].x;
			if(H <= 0 && !K) { puts("N"); continue; }
			if(H <= 0) { H += up[i].x; K--; }
			else H += up[i].y;
		}
		sort(low, low+ilow, comp2);
		if(solve(0, K) >= H) puts("N");
		else puts("Y");
	}
	return 0;
}

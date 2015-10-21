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
const int oo = 100000000;

int N, K, E;
int v[1005];
int a[4] = { 0, 4, 8, 11 };
int memo[1005][15][55][5];

int solve(int s, int k, int e, int w) {
	if(s == N) return 0;
	int &m = memo[s][k][e][w];
	if(m != -1) return m;
	m = oo;
	if(e < w) m = v[s] + solve(s+1, 0, e, 0);
	for(int i = 0; i <= 3; i++) {
		if(k - (i != w) < 0) continue;
		if(e >= i)
			m = min(m, max(v[s] - a[i], 0) + solve(s + 1, k - (i != w), e - i, i));
	}
	return m;
}

int main() {
	for_tests(t, tt) {
		scanf("%d %d %d", &N, &K, &E);
		memset(memo, -1, sizeof memo);
		for(int i = 0; i < N; i++)
			scanf("%d", &v[i]);
		printf("Case #%d: %d\n", tt, solve(0, K, E, 0));
	}
	return 0;
}

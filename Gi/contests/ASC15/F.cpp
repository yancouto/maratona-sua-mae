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
const int N = 310;

set<int> st;
int dp[N][2*N+2], nim[N];

void solve(int tot, int i, int sm, int x) {
	if(!sm) { st.insert(x); return; }
	for(int d = i; d <= min(sm, tot-1); d++)
		solve(tot, d + 1, sm - d, x^nim[d]); 
}

int main() {
	freopen("nonequal.in", "r", stdin);
	freopen("nonequal.out", "w", stdout);
	int n, i, nn, sm, x;
	scanf("%d", &n);
	nim[1] = nim[2] = 0;
	for(nn = 3; nn <= 55; nn++) {
		st.clear();
		solve(nn, 1, nn, 0);
		while(st.count(nim[nn])) nim[nn]++;
		//printf("nim[%d]=%d\n", nn, nim[nn]);
	}

	dp[0][0] = 1;
	for(nn = 1; nn < N; nn++) {
		int xx = (nn<55)?nim[nn]:nn-4;
		for(sm = N-1; sm >= nn; sm--) 
			for(x = 0; x < 2*N; x++)
				if(!dp[sm][x] && dp[sm-nn][x^xx])
					dp[sm][x] = nn;
	}
	if(dp[n][0] == n) { puts("lose"); return 0; }
	puts("win"); x = 0;
	while(n) {
		printf("%d ", dp[n][x]);
		int got = dp[n][x];
		x = x^((got<55)?nim[got]:got-4);
		n = n - got;
	}
	putchar('\n');
	return 0;	
}

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000009;
inline ull mod(ull x) { return x % modn; }

vector<int> pr[10][10];
int mark[10002];
int n;
void pre() {
	for(int i = 4; i < 1000; i += 2) mark[i] = 1;
	for(int i = 3; i < 1000; i += 2) {
		if(mark[i]) continue;
		if(i > 100) pr[i/100][(i/10)%10].pb(i % 10);
		for(int j = i + i; j < 1000; j += i)
			mark[j] = 1;
	}
}
ll memo[10005][10][10];
ll solve(int i, int d1, int d2) {
	if(i == n) return 1;
	ll &m = memo[i][d1][d2];
	if(m != -1) return m;
	m = 0;
	for(int k = 0; k < pr[d1][d2].size(); k++) {
		int d3 = pr[d1][d2][k];
		m = mod(m + solve(i + 1, d2, d3));
	}
	return m;	
}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d", &n);	
	pre();
	ll ans = 0;
	for(int i = 1; i <= 9; i++) 
		for(int j = 0; j <= 9; j++) {
			if(pr[i][j].empty()) continue;
			ans = mod(ans + solve(2, i, j));
		}
	printf("%lld\n", ans);
	return 0;
}

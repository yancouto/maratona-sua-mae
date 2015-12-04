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

int n, t;
int memo[25][5][15][2];

int solve(int i, int lst, int tt, int dwn) {
	if(i == n) return tt == t;
	int &m = memo[i][lst][tt][dwn];
	if(m != -1) return m;
	m = 0;
	for(int y = ((i == 1)?lst+1:1); y <= 4; y++) { 
		if(y > lst && tt == t) continue;
		if(y != lst)
			m += solve(i + 1, y, tt + (y < lst && !dwn), y < lst);
	}
	return m;
}

int main() {
	scanf("%d %d", &n, &t);
	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(0, 0, 0, 0));
	return 0;
}

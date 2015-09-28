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
const int MAX = 1000005;

char s[MAX];
int n;
ll memo[MAX][3][2];

ll solve(int i, int sum, int pre) {
	if(i == n) { 
		return sum == 0 && !pre;
	}
	ll &m = memo[i][sum][pre];
	if(m != -1) return m;
	m = solve(i + 1, sum, pre);
	if(s[i] >= '0' && s[i] <= '9') {
		if(!(pre && s[i] == 0))
			m += solve(i + 1, (sum + s[i]-'0') % 3, 0);
	}
	return m;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	memset(memo, -1, sizeof memo);
	printf("%lld\n", solve(0, 0, 1));
	return 0;
}

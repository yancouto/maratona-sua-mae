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
bool isLetter(int i) { return s[i] >= 'a' && s[i] <= 'z'; }

ll solve(int i, int sum, int beg) {
	if(i == n || isLetter(i)) return sum == 0 && beg;	
	ll &m = memo[i][sum][beg];
	if(m != -1) return m;
	m = 0;
	if(beg)  m += solve(i + 1, (sum + s[i]-'0') % 3, beg) + solve(n, sum, beg);
	else m += solve(i + 1, 0, 0) + solve(i + 1, (s[i]-'0') % 3, 1);
	return m;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	memset(memo, -1, sizeof memo);
	ll ans = (isLetter(0)) ? 0 : (solve(0, 0, 0));
	for(int i = 1; i < n; i++)
		if(!isLetter(i) && isLetter(i-1)) 
			ans += solve(i, 0, 0);
	printf("%lld\n", ans);
	return 0;
}

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

int n;
int s[100005];
int memo[100005][4][2];
char ss[100005];

int solve(int i, int id, int lst) {
	if(i == n) return 0;
	int &m = memo[i][id][lst];
	if(m != -1) return m;
	m = solve(i + 1, id, lst);
	if(s[i] == !lst) m = max(m, 1 + solve(i + 1, id + (id == 1), s[i]));
	else if(id != 2) m = max(m, 1 + solve(i + 1, 1, !s[i]));
	return m;
}

int main() {
	int i;
	scanf("%d", &n);
	scanf("%s", ss);
	for(i = 0; i < n; i++) s[i] = ss[i] - '0';
	memset(memo, -1, sizeof memo);
	printf("%d\n", max(solve(0, 0, 0), solve(0, 0, 1)));
	return 0;
}

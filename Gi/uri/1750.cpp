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

int abs(int x) { return (x > 0) ? x : -x; }
int v[1005];
int memo[1003][1003];

int solve(int i, int lst) {
	if(i > lst) return 0;
	int &m = memo[i][lst];
	if(m != -1) return m;
	m = min(24 - abs(v[i]-v[lst]) + solve(i+1 , lst-1), abs(v[i]-v[i+1]) + solve(i + 2, lst));
	return m;
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);
	sort(v, v + n);
	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(0, n-1));
	return 0;
}

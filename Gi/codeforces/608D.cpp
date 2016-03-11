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
const int N = 505;

int v[N], n;
int memo[N][N];

int solve(int i, int j) {
	if(i >= j) return i == j;
	int &me = memo[i][j];
	if(me != -1) return me;
	me = 1 + solve(i + 1, j);
	for(int k = i + 2; k <= j; k++)
		if(v[k] == v[i]) 
			me = min(me, solve(i + 1, k - 1) + solve(k + 1, j));
	if(v[i] == v[i+1])
		me = min(me, 1 + solve(i + 2, j));
	return me;
}

int main() {
	int i;
	memset(memo, -1, sizeof memo);
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &v[i]);
	printf("%d\n", solve(0, n-1));
	return 0;
}

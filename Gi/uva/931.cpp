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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int oo = 1000000000;

int T, W;
int n;
int tres[35][2];
int memo[35][10005];

int solve(int i, int t) {
	if(t > T) return -oo;
	if(i == n) return 0;
	int &m = memo[i][t];
	if(m != -1) return m;
	m = solve(i + 1, t);
	m = max(m, v[i].snd + solve(i + 1, t + 3 * w * v[i].fst)); 
	return m;
}

vector<int> ans;
void build(int i, int t) {
	if(t > T) return ; 
	if(i == n) return ;
	int m = solve(i, t);
	if(m == solve(i + 1, t)) build(i + 1, t);
	else {
		ans.pb(i);
		build(i + 1, t + 3 * w * v[i].fst);
	m = max(m, tres[i][1] + solve(i + 1, t + 3 * W * tres[i][0]));
	return m;
}

int main() {
	int ini = 0;
	while(scanf("%d %d", &T, &W) != EOF) {
		memset(memo, -1, sizeof memo);
		ans.clear();
		if(ini > 0) putchar('\n');
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d %d", &tres[i][0], &tres[i][1]);
		printf("%d\n", solve(0, 0));
		build(0, 0);
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++)
			printf("%d %d\n", ans[i].fst, ans[i].snd);
		ini = 1;
	}
	return 0;
}
